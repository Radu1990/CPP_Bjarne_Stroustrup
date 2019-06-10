#include "Drill.h"
#include "std_lib_facilities.h"

// This program includes the Drill from
// Chapter 17: Vector and Free Store

// Free-store-allocated arrays and contrast off arrays with vectors

int size_a{}; // array of pointer's size

// Exercises 4 and 7:
// Write a function that prints out the values of a (assumed to have n elements) to os
void print_array10(ostream& os, const int* a, const int s){ // s = size of int* array a
    os << "\n";
    for (int i=0; i<s; ++i) {
        os << "for a[" << i << "]" << " val=" << a[i] << "\n";
    }
}

void f_1(){
    // 1. Allocate an array of ten ints on the free store using new.
    size_a = 10; // array of pointer's size

    auto p = new int[size_a];

    // 2. Print the values of the ten ints to cout
    cout << "\n";
    for (int i = 0; i<size_a; ++i) { // printing each value from 0 to 9
        cout << "Mem Add " << i << " = " << (p+i) << " which is an offset of "
             << i << " * size of *p = " << sizeof(*p) <<  " bytes\n";
    }
    // 3. Deallocate that array (using delete[])
    delete[] p;
}

void f_2(){
    // 5. Allocate an array of 10 ints on the free store; initialize it with 100, 101 etc and print out its values
    size_a = 10; // array of pointer's size
    auto p2 = new int[size_a]{100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
    print_array10(cout, p2, size_a);
    delete[] p2;
}

void f_3(){
    // 6. Allocate an array of 11 ints on the free store; initialize it with 100, 101 etc and print out its values
    size_a = 11; // array of pointer's size
    auto p2 = new int[size_a]{100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    print_array10(cout, p2, size_a);
    delete[] p2;
}

// 7. Write a function that prints out the values of a (assumed to have n elements) to os
// Already implemented.

void f_4(){
    // 8. Allocate an array of 20 ints on the free store; initialize it with 100, 101 etc and print out its values
    size_a = 20; // array of pointer's size
    auto p3 = new int[size_a]{
        100, 101, 102, 103, 104, 105, 106, 107, 108, 109,
        110, 111, 112, 113, 114, 115, 116, 117, 118, 119
    };
    print_array10(cout, p3, size_a);
    delete[] p3;
}

// 9. Delete the arrays
// checked!

// 10. Do 5,6, and 8 using a vector instead of an array
// and a print_vector() instead of print_array()

void print_vector(ostream& os, const vector<int*>& p, const vector<int>& v){
    // os - output stream; s - size of memory block
    // v - vector of values; p - vector of pointer addresses
    os << endl;
    for (int i = 0; i<v.size(); i++) {
        os <<"(" << i <<") " << "mem address: " << p[i] << " = value " << v[i] << endl;
    }
}

void allocate_x_blocks(int x){
    size_a = x; // array of pointer's size
    // pointer p pointing to the beginning
    // of a block of memory with sizeof (size_a * int)
    auto p = new int[size_a];
    int starting_value = 100; // starting value stored in memory
    vector<int*>pointer; // defining vector of memory addresses
    vector<int>values; // defining vector of values pointed by the pointer

    // filling vectors with values
    for (int i = 0; i<size_a; ++i) {
        values.push_back(starting_value); // adding value
        starting_value++;
        pointer.push_back(p+i); // adding memory address pointer points to
    }

    // printing values from vectors
    print_vector(cout, pointer, values);

    // deallocating memory
    delete[] p;
}

void f_5(){
    cout << "\n\nListing 10 values" << endl;
    allocate_x_blocks(10);
    cout << "\n\nListing 11 values" << endl;
    allocate_x_blocks(11);
    cout << "\n\nListing 20 values" << endl;
    allocate_x_blocks(20);
}

// Second part: pointers and their relation to arrays

void f_6(){
    // 1. Allocate an int, init to 7 and assign its address to a var p1
    int x1{7};
    int* p1 = &x1;

    // 2. Print out the value of p1 and the int it points to
    cout << endl;
    cout << "pointer p1: " << p1 << " points to ===> the int x1: " << x1 << endl;
}

void f_7(){

    int x1{7};
    int* p1 = &x1;

    // 3. Allocate an array of seven ints; initialize it to 1, 2, 4, 8, etc.
    // and assign its address to a variable p2
    auto p2 = new int[7]{1, 2, 4, 8, 16, 32, 64};

    // 4. Print out the value of p2 and of the array it points to
    cout << endl;
    for (int i=0; i<7; ++i) {
    cout << "pointer p2: " << p2 << " points to ===> array of type int[" << i << "]= " << p2[i] << endl;
    }

    // 5. Declare an int* called p3 and initialize it with p2
    auto p3 = p2;

    // 6 Assign p1 to p2
    p2 = p1;

    // 7 Assign p3 to p2
    p2 = p3;

    // 8 Print out the values of p1 and p2 and of what they point to
    cout << "pointer p1: " << p1 << " points to ===> " << *p1 << endl;
    cout << "pointer p2: " << p2 << " points to ===> " << *p2 << endl;

    // 9 Deallocate all the memory you allocated from the free store
    delete[](p2);
    delete[](p3);
}

void f_8(){
    // 10 Allocate an array of ten ints; initialize it to 1,2,4,8, etc.
    // and assign its address to a variable p1
    auto p1 = new int[10]{1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

    // 11 Allocate an array of ten ints;
    // and assign its address to a variable p2
    auto p2 = new int[10];

    // 12 Copy the values from the array pointed to by p1 into
    // the array pointed to by p2
    cout << endl;
    for (int i=0; i<10; ++i) {
        cout << "...copying value "<< p1[i] << endl;
        p2[i] = p1[i];
        cout << "copied value "<< p2[i] << endl;
    }
    cout << "\nDone copying! :)\n";
}

void f_9(){
    // 13. Repeat 10-12 using a vector rather than an array

    // 10 Allocate a vector of ten ints; initialize it to 1,2,4,8, etc.
    // and assign its address to a variable p1
    auto p1 = new vector<int>{1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

    // 11 Allocate a vector of ten ints;
    // and assign its address to a variable p2
    vector<int> values_backup;
    auto p2 = new vector<int>(10, 0); // size = 10; default value 0

    // 12 Copy the values from the vector pointed to by p1 into
    // the vector pointed to by p2
    cout << endl;
    for (int i=0; i<10; ++i) {
        cout << "...copying value " << p1->at(i) << endl; // Retrieve using pointer to member
        p2->at(i) = p1->at(i);
        cout << "copied value "<< p2->at(i) << endl;
    }
    cout << "\nDone copying! :)\n";
}
