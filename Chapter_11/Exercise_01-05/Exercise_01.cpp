#include "Exercise_01.h"
#include "std_lib_facilities.h"


// Chapter 11. Customizing Input and Output

/* Exercise 01:
 * Write a program that reads a text file
 * and converts its input to all lower case,
 * producing a new file
*/
void tolower(string& s) {
    // put s into lower case
    for (char& x : s){
        x = tolower(x);
    }
}

void f_1(const string& input_name, const string& output_name){

    vector<string>input_vector{};

    // open file
    ifstream is {input_name};
    if (!is) error("can't open input file!: input.txt");

    // fill vector with words from file
    while (true) {
        string word;

        is >> word;

        input_vector.push_back(word);
        // if end of file, break out from the loop
        if (!(is)) break;
    }

    // change all uppercase letters to lowercase
    // inside the vector
    for (string& x : input_vector){
        tolower(x);
    }

    // write output file from updated vector
    ofstream ost {output_name};
    if (!ost) error("can't open output file: output.txt");
    for (const string& x : input_vector) {
        ost << x << " ";
    }
}

/* Exercise 02:
 * Write a program that given a file name and a word
 * outputs each line that contains that word together
 * with the line number.
*/

bool search_word(const string& word, const string& line){
    // search a line for a given word
    // if found return true else return false

    stringstream ss {line};

    for (string s; ss >> s; )
        if (s == word) return true;

    return false;
}

vector<string> get_lines(ifstream& ist) {
    // retrieve the contents of a file stream by line

    vector<string> lines;

    while (ist) {
        string line;
        getline(ist, line);
        lines.push_back(line);
    }

    if (!ist && !ist.eof())
        error("couldn't fill from file");

    return lines;
}

void f_2(const string& file_name, const string& word_name){

    ifstream ist {file_name};
    if (!ist) error("could not read from file ", file_name);

    const string& word{word_name};

    vector<string> lines = get_lines(ist);

    cout << '\n';
    cout << "searched word: " << word << '\n';

    for (int i = 0; i < lines.size(); ++i)
        if (search_word(word, lines[i]))
            cout << "paragraph: " << i + 1 << '\t' << "line: " << lines[i] << '\n';

}

/* Exercise 03:
 * Write a program that removes all vowels
 * from a file. For example:
 * "Once upon a time!" becomes "nc pn tm!"
*/

class Punct_stream {
    // like an istream but the user can add to the list of
    // whitespace characters
public:
    explicit Punct_stream(istream& is)
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

void f_3(istream& ist){
    // given text input, produce a list of all words in that text
    // ignore punctuation and case differences and vowels

    Punct_stream ps {ist};
    ps.whitespace(";:,.?!()\"{}<>/&$@#%^*'|~aeiouy");
    ps.case_sensitive(false);
    vector<string>vs;
    for(string word; ps>>word;){
        vs.push_back(word); // read words
    }
    cout << '\n';
    for (int i=0; i<vs.size(); ++i){ // read dictionary
        if (i==0 || vs[i]!= vs[i-1]){
            cout << vs[i] << ' ';
        }
    }
}

/* Exercise 04:
 * Write a program called multi_input.cpp that
 * prompts the user to enter several integers
 * in any combination of octal, decimal or
 * hexadecimal, using 0 and 0x base suffixes;
 * interprets the numbers correctly;
 * and converts them to decimal form.
 * Then output the values in properly spaced
 * columns.
*/

void f_4(istringstream& is) {
    int a,b,c;

    is.unsetf(ios::dec);
    is.unsetf(ios::oct);
    is.unsetf(ios::hex);

    is >> a >> b >> c;
    cout << "\n multi_input.cpp: \n";
    cout<<"0x"<<hex<<a<<setw(4)<<"\t"<<setw(12)<<"hexadecimal"<<setw(4)<<"\t"<<setw(12)<<"converts to"<<setw(4)<<"\t"<<dec<<a<<" decimal"<<'\n';
    cout<<"0"<<oct<<b<<setw(4)<<"\t"<<setw(12)<<"octal"<<setw(4)<<"\t"<<setw(12)<<"converts to"<<setw(4)<<"\t"<<dec<<b<<" decimal"<<'\n';
    cout<<""<<dec<<c<<setw(4)<<"\t"<<setw(12)<<"decimal"<<setw(4)<<"\t"<<setw(12)<<"converts to"<<setw(4)<<"\t"<<dec<<c<<" decimal"<<'\n';

    // input: 1234 0x4d2 02322 02322
    // output: 1234 1234 1234 1234
}

/*
 * Exercise 05:
 * Write a program that reads strings and for each string
 * outputs the character classification of each character,
 * as defined by the character classification functions
 * presented in 11.6.
 */

void f_5(istream& input_stream){

    istream& is {input_stream};

    vector<string>char_types{};

    // fill vector with words from file
    while (true) {

        for (char ch; is.get(ch);) {
            if (isspace(ch)) {
                char_types.push_back("_spc_");
            }
            if (isalpha(ch)) {
                char_types.push_back("Abc");
            }
            if (isdigit(ch)) {
                char_types.push_back("123");
            }
            if (ispunct(ch)) {
                char_types.push_back("!?,");
            }
        }
        if (!is) {
            break;
        }
    }

    cout << "\n";
    cout << "This program prints the type of the input characters\n";
    for (const string& x : char_types) {
        cout << x << " ";
    }
}
