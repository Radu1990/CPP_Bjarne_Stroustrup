#include "std_lib_facilities.h"
// Chapter 9 :: Exercise 1
/* Plausible operations for real objects
 * computer file: open, save, load, import, export, edit, view, print
 * web page: open, save, refresh, print, view html src code
 * toaster: set toasting time, cancel toasting
 * music player: play, rewind, fast-forward, pause, stop, next track, previous track
 * coffee cup: keep coffee warm
 * car engine: ignite fuel, start moving cylinders, burn fuel, stop engine.
 * cell phone: make calls, receive calls, hold calls, send messages, receive messages, display messages
 * telephone directory: store contact, view contact, load contacts, save contact, find contact.
 */

// Chapter 9 :: Exercise 2

class Name_pairs {
public:

    Name_pairs(); // default constructors

    void read_names(); // read a series of names;
    void read_ages(); // prompts user for age for every name
    void print(); // prints all name-age pairs
    void sort(); // sort the name vector and reorganize the age vector to match

private:
    vector<string> name;
    vector<double> age;
};



Name_pairs::Name_pairs()
:



void Name_pairs::read_names() {
    cout << "Please enter names\n";
    while (cin) {
        cin >> n;
        if (n =="|") { // '|' quits
            break;
        }
        name.push_back(n); // add strings to vector;
    }
}

void Name_pairs::read_ages() {
    cout << "Please enter ages\n";
    for (const string& x : name) {
        cout <<  x << "age= " << endl;
        cin >> a;
        age.push_back(a);
    }
}

void f() {
    // create object
    Name_pairs callmemaybe;
}


int main() {
    //
}
