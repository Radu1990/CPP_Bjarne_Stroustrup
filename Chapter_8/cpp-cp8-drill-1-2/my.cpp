#include "my.h"
#include "std_lib_facilities.h"

void print_foo() {
    cout << "foo = " << foo << endl;
}

void print(int i) {
    cout << "i = " << i << endl;
}

void swap_r(int& a, int&b) {
    // print initial values
    cout << "a = " << a << " " << "b = " << b << endl;

    // swap
    int temp;
    temp = a;
    a = b;
    b = temp;

    // print swapped values
    cout << "a = " << a << " " << "b = " << b << endl;
// void swap_cr(constant int& a, constant int& b) {}
// won't work to swap variables because of constant type!

}


