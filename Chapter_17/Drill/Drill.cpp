#include "Drill.h"
#include "std_lib_facilities.h"

// This program includes the Drill from
// Chapter 17: Vector and Free Store

ostream& print_array10(ostream& os, const int* a); // calling this here

void f_1(){
    // 1. Allocate an array of ten ints on the free store using new.
    auto p = new int[10];

    // 2. Print the values of the ten ints to cout
    cout << "\n";
    for (int i = 0; i<10; ++i) { // printing each memory address from 0 to 9
        cout << "Mem Add " << i << " = " << p[i] << "\n";
    }
    // 3. Deallocate that array (using delete[])
    delete[] p;

    ostream ost ;


}

// 4. Write a function that prints out the values of a (assumed to have ten elements) to os.
ostream& print_array10(ostream& os, const int* a){
    for (int i=0; i<10; ++i) {
        os << *a << "\n";
    }
    return os;
}
