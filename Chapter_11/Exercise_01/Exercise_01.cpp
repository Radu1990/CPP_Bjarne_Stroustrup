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
