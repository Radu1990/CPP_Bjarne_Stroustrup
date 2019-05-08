#include "temp_stats.h"

struct MyException : std::exception
{
    const char* what() const noexcept override { return "Buggers!"; }
};

struct Reading { // a temp reading
    int hour; // hour after midnight [0:23]
    double temperature; // in Celsius
};

vector<Reading> temps_2; // store readings in new format here

void fill_vector_2 (vector<Reading>& rr, const string& name) {
    // format (h:0 t:c7) where h = hour t = time and c = celsius
    ifstream is {name};
    if (!is) throw MyException{};
    char ch1, ch2, ch3, ch4, ch5;
    int hour;
    double temperature;
    while (true) {
        // check first char, if ok go to the next one
        if (is >> ch1 && ch1!='h') {
            is.unget();
            is.clear(ios_base::failbit);
            return;
        }
        // if end of file, break out from the loop
        if (!(is>>ch2)) break;
        is >> hour >> ch3 >> ch4 >> ch5 >> temperature;
        if (hour < 0 || 23 < hour) {
            throw MyException{};
        }
        // if c suffix found convert to fahrenheit
        if (ch5 == 'c') {
            temperature = (temperature * 9 / 5) + 32;
        }
        rr.push_back(Reading{hour, temperature});
    }
}

void compute_median_temp (const vector<Reading>& v) {
    // computes median temp from a list of values
    cout << "Median temp\t" << v[v.size()/2].temperature << "\tdeg F" << endl;
}

void compute_mean_temp (const vector<Reading>& v) {
    double sum{};
    for (const Reading x : v) {
        sum += x.temperature;
    }
    double mean = sum/v.size();
    cout.precision(2);

    cout << "Mean temp\t" << fixed << mean << "\tdeg F" << endl;
}

void compute_mean_temps() {
    // write values from second file to second vector
    fill_vector_2(temps_2, "raw_temps.txt");
    // computes median temp from a list of values
    compute_median_temp(temps_2);
    // computes mean temp from a list of values
    compute_mean_temp(temps_2);
}
