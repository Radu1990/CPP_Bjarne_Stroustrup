#include "std_lib_facilities.h"

/*
 *  This Program reads 2 input files and outputs
 *  the SORTED content of them into 1 single file
 */

void concat_2_files () {

    vector<string> first;
    vector<string> second;
    vector<string> result;

    string a;
    string b;
    string c;

    // open first input file:
    string iname = "../textfiles/input_1.txt"; // add / change to cin >> iname; if needed
    ifstream ifs_1 {iname};
    if (!ifs_1) error ("can't open file name \n", iname);
    ifs_1.exceptions(ifs_1.exceptions()|ios_base::badbit);

    // open second input file:
    string iname_2 = "../textfiles/input_2.txt"; // add / change to cin >> iname; if needed
    ifstream ifs_2 {iname_2};
    if (!ifs_2) error ("can't open file name \n", iname_2);
    ifs_2.exceptions(ifs_2.exceptions()|ios_base::badbit);

    // open output file
    string oname = "../textfiles/output.txt"; // add / change to cin >> oname; if needed
    ofstream ofs {oname};
    if (!ofs) error("can't open output file", oname);

    // write file to memory
    while (ifs_1 >> a) {
        first.push_back(a);
    }
    while (ifs_2 >> b) {
        second.push_back(b);
    }

    // read, concatenate, and write files
    for (const string& x : first) {
        result.push_back(x);
    }
    for (const string& y : second) {
        result.push_back(y);
    }
    sort(result);
    for (const string& z : result) {
        ofs << z << " ";
    }
}

// RUN
int main() {
    concat_2_files();
}
