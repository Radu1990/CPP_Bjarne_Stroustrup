#include "std_lib_facilities.h"

int main() {
    vector<string>terms{};
    vector<int>numbers{};

    ifstream is {"input.txt"};
    if (!is) error("can't open input file!");

    char ch{};
    string istr; // integer string
    string th; // thrash

    while (is.get(ch)) { // this does not ignore WHITESPACES

        if (isdigit(ch) && !isspace(ch)) {
            istr += ch;
        }
        if (!isdigit(ch) && !isspace(ch)) {
            th += ch;
        }
        if (isspace(ch) && !istr.empty()) { // if space detected and variable not empty add to vector
            terms.push_back(istr);
            istr.clear(); // reset istr
        }
    }

    for (string x : terms) {
        int new_val = stoi(x); // convert string to int
        numbers.push_back(new_val); // throw int to vector of ints
    }
    // read ints from ints vector
    cout << "Numbers list: ";
    for (int x : numbers) {
        cout << x << " ";
    }
    cout << endl;

    // add them up and print sum
    int sum{};
    for (int x : numbers) {
        sum += x;
    }
    cout << "Sum of elements = " << sum << endl;
}
