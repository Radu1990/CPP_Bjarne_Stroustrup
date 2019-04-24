#include "std_lib_facilities.h"

// Results struct
struct Results {
public:
    double smallest; // smallest element in vector
    double largest; // largest element in vector
    double mean; // mean value of vector
    double median; // median value of vector
    Results(double s, double l, double me, double md)
    :smallest(s), largest(l), mean(me), median(md)  {}
};
//------------------------------------------------------------------
// This function returns a struct of
// type Results containing all the values
Results compute_results(const vector<double>& v) {
    // sort the vector's elements
    vector<double>n = v; // n = new_vector
    sort(n);
    // results to be returned
    double smallest = n[0];
    double largest = n[n.size()-1];
    double mean = n[(n.size()-1) / 2];

    // -------- compute median value - Begin
    double median = 0; // values will be added later
    for (int i = 0; i < n.size(); ++i) {
        median += n[i];
    }
    median = median / n.size();
    // -------- compute median value - End

    // returning struct containing results
    return Results{smallest, largest, mean, median};
}
//------------------------------------------------------------------
// This function returns nothing but changes
// the values directly through reference arguments
void compute_results_2(const vector<double>& v, Results& r) {
    // sort the vector's elements
    vector<double>n = v; // n = new_vector
    sort(n);

    // -------- compute median value - Begin
    double median = 0;
    for (int i = 0; i < n.size(); ++i) {
        median += n[i];
    }
    median = median / n.size();
    // -------- compute median value - End

    // results to be written through reference arguments
    r.smallest = n[0];
    r.largest = n[n.size()-1];
    r.mean = n[(n.size()-1) / 2];
    r.median = median; // values will be added later
}
//------------------------------------------------------------------
// This function reads the values from a Result object
void read_results(const Results& r) {
    // printing results from struct r
    cout << "\nsmallest= " << r.smallest
         << "\nlargest= " << r.largest
         << "\nmedian= " << r.median
         << "\nmean= " << r.mean;
}
void print_vector(const vector<double>& v) {
    // printing vector - Begin
    cout << "{";
    for (int i = 0; i < v.size(); ++i) {
        if (i != v.size()-1) {
            cout << v[i] << ", ";
        }
    }
    cout << v[v.size()-1] << "}";
    // printing vector - End

}


int main() {
    vector<double>price{0.12, 0.05, 0.2, 0.421, 0.114, 0.47, 0.11, 40.95 }; // input vector
    // printing vector
    print_vector(price);

    // Method 1: assigning computed results to a struct "r" :
    Results r = compute_results(price);
    // printing results from struct r
    read_results(r);

    // Method 2: passing back results through reference arguments
    // initializing a Results object called 'x'
    Results x(0,0,0,0);
    // input is price vector from upstairs
    // and results are written in object 'x'
    compute_results_2(price, x);
    // reading results from object 'x'
    read_results(x);

}
