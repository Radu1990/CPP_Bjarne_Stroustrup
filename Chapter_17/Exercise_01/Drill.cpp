#include "Drill.h"
#include "std_lib_facilities.h"

// This program includes the Exercises from
// Chapter 17: Vector and Free Store

// 1. Q: Output format of pointer values on your implementation?
//    A: The actual data type of the value of all pointers, whether
//    integer, float, character, or otherwise, is the same,
//    a long hexadecimal number that represents a memory address.

// 2. int = 4 bytes, double = 8 bytes, bool = 1 byte

// 3. write void to_lower without any std library functions

void to_lower(char* s){
    if (isupper(*s)) {
        *s = tolower(*s);
    }
}

void f_1(){
    char myString[] = "It's Already, Too Late"; // char array


    // printing input
    cout << "\nInput: " << myString << endl;

    int next_val{0}; // iterator for chars inside char array
    int length = sizeof(myString); // size of char array

    // printing converted output
    cout << "Output: ";
    for (int i=0; i<length; ++i) {
        char* p = (myString + next_val); // creating a new pointer every iteration
        if (*p == 0) { // checking if we reached the end of the char array
            return;    // and returning if end
        }
        to_lower(p); // converting upper case to lowercase if case given
        cout << *p; // printing the char
        next_val++;
    }
}
