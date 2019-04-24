#include "std_lib_facilities.h"

//------------------------------------------------------------------
// Returns vector with number of char in each string
vector<int> somefunct(vector<string>& s) {
    vector<int> v;
    // throwing sizes of each string from vector s to vector v
    for (const string& x : s) {
        v.push_back(x.size());
    }
    return v;
}

// longest string
string somefunct(vector<string>& s) {
    vector<int> v;
    // finding longest string
    for (const string& x : s) {
        v.push_back(x.size());
    }
    return v;
}
// shortest string
// lexicographically first
// lexicographically last
int main() {
    ///
}