#include "Exercise_01.h"
#include "std_lib_facilities.h"

// This program includes the Exercises from
// Chapter 17: Vector and Free Store

// 1. Q: Output format of pointer values on your implementation?
//    A: The actual data type of the value of all pointers, whether
//    integer, float, character, or otherwise, is the same,
//    a long hexadecimal number that represents a memory address.

// 2. int = 4 bytes, double = 8 bytes, bool = 1 byte

// 3. write a function that replaces all upper case characters
// in a C-Style String s with their lower case equivalents
// without any std library functions

int get_length(const char*& string){
    // finding length of C Style string
    int length{0};
    for (int i=0; ++i;) {
        length++; // increment length
        if (string[i]==0) { // break if end of string found
            break;
        }
    }
    return length;
}

void to_lower(char* s){ // convert any uppercase char to lowercase
    if (isupper(*s)) {
        *s = tolower(*s);
    }
}

void char_to_lower(const char*& string){
    int length = get_length(string);

    // passing reference
    char myStr[length];
    strcpy(myStr, string); // library function

    // printing input
    cout << "\nInput: " << myStr << endl;

    int next_val{0}; // iterator for chars inside char array

    // printing converted output
    cout << "Output: ";
    for (int i=0; i<length; ++i) {
        char* p = (myStr + next_val); // pointing to next value every iteration
        if (*p == 0) { // checking if we reached the end of the char array
            return;    // and returning if end
        }
        to_lower(p); // converting upper case to lowercase if case given
        cout << *p; // printing the char
        next_val++;
    }
}

void f_1() {
    char myString[] = "It's Already, Too Late"; // C-Style string
    const char* p = myString; // pointer to C-Style string
    char_to_lower(p);
}

// 4. Write a function that copies a C-style
// string into memory it allocates on the free store
// Do not use any std library functions

char* strdup_2(const char*& string){

    int length = get_length(string);
    auto p = new char[length]; // pointer to block of memory of type char[]

    // copy string
    for (int i=0; i<length; ++i){
        p[i] = string[i];
    }
    // <----- NOT HERE (DELETE)
    return p;
}

void f_2(){
    char myString[] = "It's Already, Too Late"; // C-Style string
    const char* p = myString; // pointer to C-Style string

    const char* myPointer = strdup_2(p);

    // do something with myPointer
    int length = get_length(myPointer); // first get length of string

    for (int i = 0; i<length; ++i){
        cout << myPointer[i];
    }
    // <----- DELETE HERE
    delete[]myPointer; // put this only after you are done with your reading/writing...
}

// 5. Write a function, that finds the first occurrence of the
// C-Style String x in s

char* findx(const char* s, const char* x){
    int length = get_length(s); // first get length of string
    // if character found in string
    // copy string into a new allocated memory
    // and return a pointer to it
    cout << "\nInput string: \"" << s << "\"" << endl;

    for (int i=0; i<length; ++i) {
        if (s[i] == *x) {
            char* ret = strdup_2(s); // delete this after
            cout << "Character: \"" << *x << "\" found!\n";
            cout << "First occurence at index : " << i << endl;
            cout << "Returning pointer to the string containing it\n";
            return ret;
        }
    }
    cout << "Character: \"" << *x << "\" not found!\n";
    cout << "Returning nullptr\n";
    return nullptr;
}

void f_3(){
    char myString[] = "It's Already, Too Late"; // C-Style string
    char myChar = 'T';
    char myChar_2 = 'W';

    const char* s = myString; // pointer to C-Style string
    const char* x = &myChar; // pointer to myChar
    const char* y = &myChar_2; // pointer to myChar_2

    char* p1 = findx(s, x);
    char* p2 = findx(s, y);

    delete[]p1;
    delete[]p2;
}

// 6. Memory exhaustion

// 7. Write a program that reads characters from cin into an array that
// you allocate on the heap (free store).

// Read individual characters until an exclamation mark (!)
// is entered. Do not use std::string. Do not worry about Memory Exhaustion

void f_4(istream& is){
    vector <char> characters;
    auto p = new char;
    cout << endl;

    while (true) {
        // quit if EOF
        if(!(is >> *p)) {
            cout << "\n >>> End of File! <<<\n";
            break;
        }
        // quit if '!' entered
        if (*p == '!') {
            cout << "\n >>> Character '!' entered <<<\n";
            break;
        }
        // add char to vector
        characters.push_back(*p);
    }
    delete p;
}

// 8. Do ex. 7 again but this time read into a std::string rather than to memory

void f_5(istream& is){
    string s{};
    cout << endl;

    while (true) {
        // quit if EOF
        if(!(is >> s)) {
            cout << "\n >>> End of File! <<<\n";
            break;
        }
        // quit if '!' entered
        if (s == "!") {
            cout << "\n >>> Character '!' entered <<<\n";
            break;
        }
    }
}

// 9. Which way does the stack grow: up (towards higher addresses) or down?
// Same for the heap (free store). Write a program to determine the answers.

void f_6(){
    // declaring pointers -> memory allocated on the stack
    int v{0};
    int w{0};
    int x{0};
    int y{0};
    int z{0};

    int* pv = &v;
    int* pw = &w;
    int* px = &x;
    int* py = &y;
    int* pz = &z;

    // declaring pointers with "new" -> allocating memory on the heap
    int* pa = new int;
    int* pb = new int;
    int* pc = new int;
    int* pd = new int;
    int* pe = new int;

    // printing pointer addresses
    cout << "\n";
    cout << ">>> Printing addresses of pointers allocated on the stack\n";
    cout << "pv =\t" << pv << "\n";
    cout << "pw =\t" << pw << "\n";
    cout << "px =\t" << px << "\n";
    cout << "py =\t" << py << "\n";
    cout << "pz =\t" << pz << "\n";

    cout << "\n";

    cout << "Printing addresses of pointers allocated on the heap (free store)\n";
    cout << "pa =\t" << pa << "\n";
    cout << "pb =\t" << pb << "\n";
    cout << "pc =\t" << pc << "\n";
    cout << "pd =\t" << pd << "\n";
    cout << "pe =\t" << pe << "\n";

}

// 11. Complete the "list of gods example from 17.10.1 and run it.

class Link2 {
public:
    string value;
    explicit Link2(string v, Link2* p = nullptr, Link2* s = nullptr)
            :value{std::move(v)}, prev{p}, succ{s} { }

    Link2* insert(Link2* n); // insert n before this object
    Link2* add(Link2* n); // add n after this object
    Link2* erase(); // remove this object from list
    Link2* find(const string& s); // find s in list

    const Link2* find(const string& s) const; // find s in const list

    Link2* advance(int n) const; // move n positions in list

    Link2* next() const {
        return succ;
    }

    Link2* previous() const {
        return prev;
    }

private:
    Link2* succ;
    Link2* prev;
};

Link2* Link2::insert(Link2* n){ // insert n before this object
    if (n== nullptr) return this; // nothing to insert
    if (this==nullptr) return n;
    n->succ = this; // p comes after n
    if (prev) {
        prev->succ = n;
    }
    n->prev = prev; // p's predecessor becomes n's predecessor
    prev = n; // n becomes p's predecessor
    return n;
}

void print_all_lists(Link2* p){
    cout << "{ ";
    while(p) {
        cout << p->value;
        if(p==p->next()){
            cout <<", ";
        }
    }
    cout << "}";
}

void f_7(){
    // create lists
    Link2* norse_gods = new Link2{"Thor"};
    norse_gods = norse_gods->insert(new Link2{"Odin"});
    norse_gods = norse_gods->insert(new Link2{"Zeus"});
    norse_gods = norse_gods->insert(new Link2{"Freia"});

    Link2* greek_gods = new Link2{"Hera"};
    greek_gods = greek_gods->insert(new Link2{"Athena"});
    greek_gods = greek_gods->insert(new Link2{"Mars"});
    greek_gods = greek_gods->insert(new Link2{"Poseidon"});

    // correct the name of the god war
    Link2* p = greek_gods->find("Mars");
    if (p) p->value = "Ares";

    // move Zeus into his correct Pantheon
    Link2* p2 = norse_gods->find("Zeus");
    if (p2) {
        if (p2 == norse_gods) {
            norse_gods = p2->next();
        }
        p2->erase();
        greek_gods = greek_gods->insert(p2);
    }

    // print out the lists
    cout << "\n";
    print_all_lists(norse_gods);
    cout << "\n";
    print_all_lists(greek_gods);
    cout << "\n";
}
