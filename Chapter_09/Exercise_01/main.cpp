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

    Name_pairs()
    :name{ }, age{ }  { }


    // modifying operations
    void read_names(); // read a series of names;
    void read_ages(); // prompts user for age for every name
    void sort_names(); // sort the name vector and reorganize the age vector to match

    //non-modifying operations
    vector<string> ret_name() const {
        return name;
    };

    vector<double> ret_age() const {
        return age;
    };


private:

    vector<string> name { };
    vector<double> age { };

};

void Name_pairs::read_names() {
    cout << "Please enter names\n";
    while (cin) {
        string n;
        cin >> n;
        if (n =="|") { // '|' quits
            break;
        }
        name.push_back(n); // add strings to vector;
    }
}

void Name_pairs::read_ages() {
    cout << "Please enter ages\n";
    double a;
    for (const string& x : name) {
        cout << endl << x << "'s age= ";
        cin >> a;
        age.push_back(a);
    }
}

void Name_pairs::sort_names()  {
    vector<string> name_copy = name; // names vector to ref to
    vector<double> new_age; // new reordered ages vector
    // sorting the name array
    sort(name);
    // sorting the ages in a fresh array
    for (int i=0; i < name_copy.size(); ++i) { // looping through old array
        for (int j=0; j < name.size(); ++j) { // looping through sorted array
            if ( name_copy[i] == name[j] ) { // old matches with new
                new_age.push_back(age[j]); // old value position comes in the new sorted position
            }
        }
    }
    //replacing age array with the fresh one
    age = new_age;
}

ostream& operator<<(ostream& os, const Name_pairs& np) {
    for (int i = 0; i < np.ret_name().size(); ++i) {
        os << np.ret_name()[i] << " : " << np.ret_age()[i] << endl;
    }
    return os;
}

bool operator==(const Name_pairs& a, const Name_pairs& b) {
    // checking sizes first
    if (a.ret_name().size() != b.ret_name().size() || a.ret_age().size() != b.ret_age().size() ) {
        return false;
    }
    // checking if names are the same and ages are the same
    for (int i = 0; i < a.ret_name().size(); ++i) {
        if (a.ret_name()[i] != b.ret_name()[i] || a.ret_age()[i] != b.ret_age()[i]) {
            return false;
        }
    }
    return true;
}

bool operator!=(const Name_pairs& a, const Name_pairs& b){
    return !(a == b); // return true if condition evaluates false
}



void f() {
    Name_pairs callmemaybe;
    callmemaybe.read_names();
    callmemaybe.read_ages();
    callmemaybe.sort_names();

    Name_pairs callmenot = callmemaybe;

    cout << callmemaybe;
    cout << callmenot;
}


int main() {
    f();
}
