#include "Exercise_01.h"
#include "std_lib_facilities.h"


// This program includes the Drill Exercise from
// Chapter 11. Customizing Input and Output

void tolower(string& s) { // put s into lower case
    for (char& x : s){
        x = tolower(x);
    }
}

void f_1(const string& input_name, const string& output_name){

    vector<string>input_vector{};

    ifstream is {input_name};
    if (!is) error("can't open input file!: input.txt");
    while (true) {
        string word;

        is >> word;

        input_vector.push_back(word);
        // if end of file, break out from the loop
        if (!(is)) break;
    }

    for (string& x : input_vector){
        tolower(x);

    }

    ofstream ost {output_name};
    if (!ost) error("can't open output file: output.txt");
    for (const string& x : input_vector) {
        ost << x << " ";
    }

}


