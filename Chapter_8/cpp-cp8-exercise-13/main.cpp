#include "std_lib_facilities.h"

//------------------------------------------------------------------
// Returns vector with strings length
vector<int> stringlength(const vector<string>& s) {
    vector<int> v;
    // throwing sizes of each string from vector s to vector v
    for (const string& x : s) {
        v.push_back(x.size());
    }
    return v;
}

// lexicographically first string
string lexfirst(const vector<string>& s) {
    //sort
    vector<string> v = s;
    sort(v);

    // finding lexicographically first string
    string l = v[0];
    // initializing first string with an element
    // loop needs nonempty string to compare to
    for (const string& x : v) {
        if (x < l) {
            l = x;
        }
    }
    return l;
}

// lexicographically last string
string lexlast(const vector<string>& s) {
    //sort
    vector<string> v = s;
    sort(v);

    // finding longest string
    string l {}; // longest string
    for (const string& x : v) {
        if (x > l) {
            l = x;
        }
    }
    return l;
}

// longest and shortest string
void ls(const vector<string>& s) { // find longest and shortest string
    // return variables
    string sm; // smallest string
    string bg; // biggest string

    // create a fresh string vector
    vector<string> v = s;
    // assign some values to the variables
    sm = v[0];
    bg = v[0];
    // find from the alphabetically sorted strings
    // which one is the shortest and longest
    // TODO could be improved to return also
    //  the first alphabetically ordered string
    for (int i = 0; i < v.size()-1; ++i) {
        for (int j = i+1; j < v.size(); ++j) {
            if (v[i].size() < v[j].size() && v[i].size() < sm.size()) {
                sm = v[i];
            }
        }
    }
    for (int i = 0; i < v.size()-1; ++i) {
        for (int j = i+1; j < v.size(); ++j) {
            if (v[i].size() > v[j].size() && v[i].size() > bg.size()) {
                bg = v[i];
            }
        }
    }
    cout << "smallest string= " << sm << endl;
    cout << "biggest string= " << bg << endl;
}

// print vector
void print_vec_int(const vector<int>& v) {
    for (int x : v) {
        cout << x << " ";
    }
}
void print_vec_str(const vector<string>& v) {
    for (const string& x : v) {
        cout << x << " ";
    }
}


int main() {
    ///
    vector<string>example{"gfk", "geeksforgeeks", "tatacalurulez", "survival", "of", "the", "fittest"}; // input vector
    cout << "string example= ";
    print_vec_str(example); // read

    vector<int> x = stringlength(example); // array of string lengths
    cout << "\nlengths of strings= ";
    print_vec_int(x); // read

    string y = lexfirst(example); // lexicographically first
    cout << "\nlex first= " << y << endl;

    string z = lexlast(example); // lexicographically last
    cout << "lex last= " << z << endl;

    ls(example); // smallest and biggest strings from the array

}