#include "std_lib_facilities.h"

struct Results {
public:
    double smallest; // smallest element in vector
    double largest; // largest element in vector
    double mean; // mean value of vector
    double median; // median value of vector
    Results(double s, double l, double me, double md)
    :smallest(s), largest(l), mean(me), median(md)  {}
};

Results compute_results(const vector<double>& v) {
    // sort the vector's elements
    vector<double>n = v; // n = new_vector
    sort(n);
    // results to be returned
    double smallest = n[0];
    double largest = n[n.size()-1];
    double mean = n[(n.size()-1) / 2];
    double median = 0; // values will be added later

    // -------- compute median value - Begin
    for (int i = 0; i < n.size(); ++i) {
        median += n[i];
    }
    median = median / n.size();
    // -------- compute median value - End

    // returning struct containing results
    return Results{smallest, largest, mean, median};
}

int main() {
    vector<double>price{0.12, 0.05, 0.2, 0.421, 0.114, 0.47, 0.11, 40.95 }; // input vector

    // printing vector - Begin
    cout << "{";
    for (int i = 0; i < price.size(); ++i) {
        if (i != price.size()-1) {
            cout << price[i] << ", ";
        }
    }
    cout << price[price.size()-1] << "}";
    // printing vector - End

    // assigning computed results to struct r
    Results r = compute_results(price);

    // printing results from struct r
    cout << "\nsmallest= " << r.smallest
         << "\nlargest= " << r.largest
         << "\nmedian= " << r.median
         << "\nmean= " << r.mean;
}