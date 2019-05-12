#include "std_lib_facilities.h"

void concat_2_files () {

    string a;
    string b;
    string c;

    // open first input file:
    string iname = "../textfiles/input_1.txt"; // add / change to cin >> iname; if needed
    ifstream ifs_1 {iname};
    if (!ifs_1) error ("can't open file name \n", iname);
    ifs_1.exceptions(ifs_1.exceptions()|ios_base::badbit);

    // write file to memory
    ifs_1 >> a;

    // open second input file:
    string iname_2 = "../textfiles/input_2.txt"; // add / change to cin >> iname; if needed
    ifstream ifs_2 {iname_2};
    if (!ifs_2) error ("can't open file name \n", iname_2);
    ifs_2.exceptions(ifs_2.exceptions()|ios_base::badbit);

    // write file to memory
    ifs_2 >> b;

    // open output file
    string oname = "../textfiles/output.txt"; // add / change to cin >> oname; if needed
    ofstream ofs {oname};
    if (!ofs) error("can't open output file", oname);

    // read, concatenate, and write files
    c = a + " " + b;
    ofs << c;
}

int main() {
    concat_2_files();
}
