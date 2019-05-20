#include "custom_io.h"
#include "std_lib_facilities.h"

// This program includes the examples from
// Chapter 11. Customizing Input and Output

void f_1() {
    cout << "\nFunction 1 - Integer output:\n";
    cout << 1234 << "\t(decimal)\n"
         << hex << 1234 << "\t(hexadecimal)\n"
         << oct << 1234 << "\t(octal)\n";
}

void f_2() {
    cout << "\nFunction 2 - Integer output:\n";
    cout << 1234 << "\t" << hex << 1234 << "\t" << oct << 1234 << '\n';
    cout << 1234;

}

void f_3() {
    // decimal numbers - no prefix
    // octal numbers - prefix 0
    // hexadecimal numbers - prefix 0x or 0X
    cout << "\nFunction 3 - Show base:\n";
    cout << 1234 << "\t" << hex << 1234 << "\t" << oct << 1234 << '\n';
    cout << showbase << dec; // show bases
    cout << 1234 << '\t' << hex << 1234 << '\t' << oct << 1234 << '\n';
    // to revert use "noshowbase"
}

void f_4() {
    cout << "\nFunction 4 - print dec, oct and hex in decimal form:\n";
    // print dec, oct, and hex numbers in decimal form
    cout << 1234 << '\t' << 0x4d2 << '\t' << 02322 << '\n';
}

void f_5() {
    cout << "\nFunction 5 - Integer input:\n";
    // tell >> to read hexadecimal or octal integers, by default he reads decimal integers
    int a,b,c,d;
    cin >> a >> hex >> b >> oct >> c >> d;
    cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';
    // input: 1234 4d2 2322 2322
    // output: 1234	1234 1234 1234
    // ! oct, hex and dec stick for input as they do for output
}

void f_6(istream& aa, istream& bb) {
    cout << "\nFunction 6 - Integer input:\n";
    // You can get >> to interpret the 0 and 0x prefixes by unsetting all the defaults.
    // The stream member function unsetf() clears the flag (or flags)
    // given as argument.
    int a,b,c,d;

    // input: 1234 4d2 2322 2322
    // output: 1234 1234 1234 1234
    aa >> a >> hex >> b >> oct >> c >> d;
    cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';

    bb.unsetf(ios::dec);
    bb.unsetf(ios::oct);
    bb.unsetf(ios::hex);

    bb >> a >> b >> c >> d;
    cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';

    // input: 1234 0x4d2 02322 02322
    // output: 1234 1234 1234 1234

}

void f_6_1() {
    cout << "\nFunction 6 - Integer input:\n";
    // Trying to simplify things and testing the
    // function from above using istringstream
    int a,b,c,d;

    // input:
    // output: 1234 1234 1234 1234
    istringstream aa {"1234 4d2 2322 2322"};
    aa >> a >> hex >> b >> oct >> c >> d;
    cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';

    aa.unsetf(ios::dec);
    aa.unsetf(ios::oct);
    aa.unsetf(ios::hex);

    aa >> a >> b >> c >> d;
    cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';

    // input: 1234 0x4d2 02322 02322
    // output: 1234 1234 1234 1234

}

void f_7() {
    cout << "\nFunction 7 - Floating point ouput:\n";
    // Useful typically for hardware or scientific calculations

    cout << 1234.56789 << "\t\t\t(defaultfloat)\n"
         << fixed << 1234.56789 << "\t\t(fixed)\n"
         << scientific << 1234.56789 << "\t(scientific)\n";
    cout << 1234.56789 << "\t(scientific) sticks\n"
         << defaultfloat << 1234.56789 << '\t'
         << fixed << 1234.56789 << '\t' << scientific << 1234.56789 << '\n';
}

void try_this_1() {
    cout << defaultfloat << 1234567.89 << "\t\t\t(defaultfloat)\n"
         << fixed << 1234567.89 << "\t\t(fixed)\n"
         << scientific << 1234567.89 << "\t(scientific)\n";
}

void f_8() {
    cout << "\nFunction 8 - Precision:\n";
    // By default, a floating-point value is printed using six total
    // digits using the default format
    cout << "Default precision:\n";
    cout << 1234.56789 << "\t\t\t(defaultfloat)\n"
         << fixed << 1234.56789 << "\t\t(fixed)\n"
         << scientific << 1234.56789 << "\t(scientific)\n";
    cout << "setprecision(5):\n";
    cout << defaultfloat << setprecision(5) << 1234.56789 << '\t'
         << fixed << 1234.56789 << '\t'
         << scientific << 1234.56789 << '\n';
    cout << "setprecision(8):\n";
    cout << defaultfloat << setprecision(8) << 1234.56789 << '\t'
         << fixed << 1234.56789 << '\t'
         << scientific << 1234.56789 << '\t';

    // observe the rounding rule (the 4/5 Rule)
}

void f_9() {
    cout << "\nFunction 9 - Fields:\n";
    // using scientific and fixed formats, you can control exactly how much space
    // a value takes up on output
    // the equivalent mechanism for integer values is called fields.
    cout << 123456 << '|' << setw(4) << 123456 << '|'
         << setw(8) << 123456 << '|' << 123456 << "|\n";
    // ! Note that the field width doesn't stick!
    // ! It must be set every time before the output operator

}

void try_this_2() {
    // simple table including last name, first name,
    // telephone number and e-mail address
    vector<string>description{
        "first name", "last name", "Phone number", "e-mail"
    };
    vector<string>last_name{
        "Radu", "Maria", "Victor", "Jon", "Delia", "Raluca"
    };
    vector<string>first_name{
        "Pelicanul", "Broasca", "Croitorul", "Crocodilul",
        "Pisica", "Ciripitoarea"
    };
    vector<string>phone{
        "+49(0)12265348942","+49(0)15565343942","+49(0)15567548942",
        "+49(0)15135348942", "+49(0)67465348942","+49(0)11095348942"
    };
    vector<string>email{"Pelicanul@delta.ro", "Broasca@baltaverde.ro",
                        "Croitorul@traian.ro", "Crocodilul@baltaverde.ro",
                        "Pisica@suspegard.com", "Ciripitoarea@cicalitorii.com"
    };
    // The future me will probably laugh at this code.
    cout << "+----------------------------------------------------------------------------------+\n"
         << '|' << setw(15) << description[0] << '|' << setw(14) << description[1] << '|' << setw(20) << description[2] << '|' << setw(30) << description[3]  << '|' << '\n'
         << "+----------------------------------------------------------------------------------+\n"
         << '|' << setw(15) << last_name[0] << '|' << setw(14) << first_name[0] << '|' << setw(20) << phone[0] << '|' << setw(30) << email[0]  << '|' << '\n'
         << '|' << setw(15) << last_name[1] << '|' << setw(14) << first_name[1] << '|' << setw(20) << phone[1] << '|' << setw(30) << email[1]  << '|' << '\n'
         << '|' << setw(15) << last_name[2] << '|' << setw(14) << first_name[2] << '|' << setw(20) << phone[2] << '|' << setw(30) << email[2]  << '|' << '\n'
         << '|' << setw(15) << last_name[3] << '|' << setw(14) << first_name[3] << '|' << setw(20) << phone[3] << '|' << setw(30) << email[3]  << '|' << '\n'
         << '|' << setw(15) << last_name[4] << '|' << setw(14) << first_name[4] << '|' << setw(20) << phone[4] << '|' << setw(30) << email[4]  << '|' << '\n'
         << '|' << setw(15) << last_name[5] << '|' << setw(14) << first_name[5] << '|' << setw(20) << phone[5] << '|' << setw(30) << email[5]  << '|' << '\n'
         << "+----------------------------------------------------------------------------------+\n";
}

void f_10(){
    // open an istream for binary input from a file:
    // can use cout << Please enter input file name
    // and then cin >> iname; as-well
    string iname{"filenamehere"};
    ifstream ifs {iname, ios_base::binary};
    // note stream mode binary tells the stream
    // not to try anything clever with the bytes.
    if (!ifs) error("can't open input file ", iname);

    // open an ostream for binary output to a file
    string oname{"filenamehere"};
    ofstream ofs {oname, ios_base::binary};
    if (!ofs) error("can't open output file", oname);

    vector<int> v;

    // read from binary file:
    for (int x; ifs.read(as_bytes(x), sizeof(int));){ // note: reading bytes
        v.push_back(x);
    }

    // ... do something with v ...

    // write to binary file:

    for(int x : v) {
        ofs.write(as_bytes(x), sizeof(int)); // note: writing bytes
    }
}
