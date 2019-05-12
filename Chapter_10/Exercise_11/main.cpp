#include "std_lib_facilities.h"

int main() {
    // read a file containing white-space separated values
    // and add up only the integer values
    // eg. input: 2 bananas 3 kiwis; output: 5

    vector<string>terms{};
    vector<int>numbers{};

    // open input .txt file
    ifstream is {"../textfiles/input.txt"};
    if (!is) error("can't open input file!");

    // create variables where the input stream will go
    char ch{};
    string istr; // integer string
    string th; // thrash

    // read the stream and filter out only the integer values
    while (is.get(ch)) { // this does not ignore WHITESPACES

        if (isdigit(ch) && !isspace(ch)) {
            istr += ch; // where the integer goes
        }
        if (!isdigit(ch) && !isspace(ch)) {
            th += ch; // where the non digits characters go
        }
        if (isspace(ch) && !istr.empty()) { // if space detected and variable not empty add to vector
            terms.push_back(istr);
            istr.clear(); // reset istr after throwing the integer value in the array
        }
    }

    // convert string to int
    // throw int to vector of ints
    for (const string& x : terms) {
        int new_val = stoi(x);
        numbers.push_back(new_val);
    }

    // print ints from ints vector
    cout << "Numbers list: ";
    for (int x : numbers) {
        cout << x << " ";
    }
    cout << endl;

    // add them up and print the sum
    int sum{};
    for (int x : numbers) {
        sum += x;
    }
    cout << "Sum of elements = " << sum << endl;
}
