#include <iostream>
#include "std_lib_facilities.h"

// This program computes the sum of all
// space-separated integer values
// stored in a .txt file

vector<int> values{};

void read_file_to_vector (const string& name, vector<int>& v) {
    // open file
    ifstream is {name};
    if (!is) error("can't open input file!");
    // throw values from file to vector
    while (true) {
        int x{};
        // if end of file, break out from the loop
        if (!(is>>x)) break;
        v.push_back(x);
    }
    // could make sum in same function but wanted to split the operations
}

int make_sum(const vector<int>& v) {
    int sum {};
    for (int x : v) {
       sum += x;
    }
    return sum;
}

int main() {
    std::cout << "Hi there!" << std::endl;
    read_file_to_vector("myinputfile.txt", values);
    int my_sum = make_sum(values);
    cout << "Sum of values= " << my_sum << endl;
}

