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
