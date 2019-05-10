#include "std_lib_facilities.h"

class Roman_int {

public:
    explicit Roman_int(string ss): roman_int(move(ss)) { }; // constructor
    string as_roman_int () const;
    int as_int () const;

private:
    // first 30 positive integers
    vector<string> numerals {
        "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X",
        "XI", "XII", "XIII", "XIV", "XV", "XVI", "XVII", "XVIII", "XIX", "XX", "XXI", "XXII",
        "XXIII", "XXIV", "XXV", "XXVI", "XXVII", "XXVIII", "XXIX", "XXX"
    };
    string roman_int {};
};

//--------------------------------------------------------------------------------

// return roman symbol
string Roman_int::as_roman_int() const {
    return roman_int;
}

// return arabic symbol
int Roman_int::as_int() const {
    string m = roman_int;
    for (int i = 0; i < numerals.size(); ++i) {
        int ret = i+1; // for I = 1, II = 2 etc.
        if (numerals[i] == m) {
            return ret;
        }
    }
    error("No match!");
    return 1;
}

// overload operator << to write the roman symbol
ostream& operator<<(ostream& os, const Roman_int& rr) {
    return cout << rr.as_roman_int();
}

int main() {
    Roman_int x ("II");
    Roman_int y ("IX");
    Roman_int z ("XVI");
    cout << "Roman " << x << " equals " << x.as_int() << endl;
    cout << "Roman " << y << " equals " << y.as_int() << endl;
    cout << "Roman " << z << " equals " << z.as_int() << endl;
}
