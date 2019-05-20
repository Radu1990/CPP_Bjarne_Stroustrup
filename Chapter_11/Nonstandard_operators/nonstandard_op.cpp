#include "nonstandard_op.h"
#include "std_lib_facilities.h"

// This program includes the examples from
// Chapter 11. Customizing Input and Output

// 11.7 Using nonstandard separators

class Punct_stream {
    // like an istream but the user can add to the list of
    // whitespace characters
public:
    Punct_stream(istream& is)
    : source{is}, sensitive{true} { }
    void whitespace(const string& s) { // make s the whitespace set
        white = s;
    }
    void add_white(char c) {
        white +=c; // add to the whitespace set
    }
    bool is_whitespace(char c); // is c in the whitespace set?
    void case_sensitive(bool b) {
        sensitive = b;
    }
    bool is_case_sensitive() {
        return sensitive;
    }
    Punct_stream& operator>> (string& s);
    explicit operator bool();
private:
    istream& source; // character source
    istringstream buffer; // we let buffer do our formatting
    string white; // characters considered "whitespace"
    bool sensitive; // is the stream case-sensitive?
};

/*
    1. Read a whole line from istream into string
    2. Convert all whitespace char to ' ' char
    3. Put line into istringstream called buffer
    4. use whitespace separating >> to read from buffer.
*/
Punct_stream& Punct_stream::operator>>(string &s) {
    while(!(buffer>>s)) { // try to read from buffer
        if(buffer.bad() || !source.good()) {
            return *this;
        }
        buffer.clear();
        string line;
        getline(source, line); // get a line from source
        // do character replacement as needed:
        for (char& ch: line) {
            if (is_whitespace(ch)) {
                ch = ' '; // to space
            }
            else if (!sensitive) {
                ch = tolower(ch);
            }
            buffer.str(line);
        }
    }
    return *this;
}

// Testing for whitespace
// We compare a character to each character of the string
// that holds our whitespace set
bool Punct_stream::is_whitespace(char c) {
    for (char w:white) {
        if (c==w) {
            return true;
        }
    }
    return false;
}

// This returns true if the operation on the
// Punt_stream succeeded
Punct_stream::operator bool() {
    return !(source.fail() || source.bad()) &&  buffer.good();
}

void f_main(istream& ss){
    // given text input, produce a sorted list of all words in that text
    // ignore punctuation and case differences
    // eliminate duplicates from the output
    Punct_stream ps {ss}; // replace ss with cin if main function
    ps.whitespace(";:,.?!()\"{}<>/&$@#%^*|~");
    ps.case_sensitive(false);
    cout << "Please enter words\n";
    vector<string>vs;
    for(string word; ps>>word;){
        vs.push_back(word); // read words
    }
    sort(vs.begin(), vs.end()); // sort in lexicographically order
    for (int i=0; i<vs.size(); ++i){ // write dictionary
        if (i==0 || vs[i]!= vs[i-1]){
            cout << vs[i] << '\n';
        }
    }
}
