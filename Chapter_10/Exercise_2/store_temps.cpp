#include <iostream>
#include "std_lib_facilities.h"

// info: store temp readings from "temps_1.txt" in a new file "temps_2.txt"
// source temps: wetter.de
// date: 7 May 2019 Stuttgart, Germany
struct Reading { // a temp reading
    int hour; // hour after midnight [0:23]
    double temperature; // in Celsius
};

vector<Reading> temps; // store the readings here

void fill_vector_from_file(vector<Reading>& rr, const string& name) {
    ifstream is {name};
    if (!is) error("can't open input file!");
    int hour;
    double temperature;
    while (is >> hour >> temperature) {
        if (hour < 0 || 23 < hour) {
            error("Hour out of range!\n");
        }
        rr.push_back(Reading{hour, temperature});
    }
}

void write_vector_to_file (const vector<Reading>& rr, const string& name) {
    ofstream ost {name};
    if (!ost) error("can't open output file:", name);
    for (Reading r : rr) {
        // format (h:0 t:c7) where h = hour t = time and c = celsius
        ost << "h:" << r.hour << " " << "t:" << 'c' << r.temperature << endl;
    }
}

void store_temps() {
    // write values from file to vector
    fill_vector_from_file(temps, "temps_1.txt");
    // write values from vector to file
    write_vector_to_file(temps, "raw_temps.txt");
}
