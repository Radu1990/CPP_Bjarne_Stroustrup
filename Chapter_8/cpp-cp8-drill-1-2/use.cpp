#include <iostream>
#include "my.h"
// CPP - Stroustrup: Chapter 8 - Functions: Drill
//
int foo;
int x;
int y;

int main() {
 // Ex 1
    std::cout << "### Exercise 1 ### " << std::endl;

    foo = 7;
    print_foo();
    print(99);

    std::cout << "\n";

 // Ex 2
    std::cout << "### Exercise 2 ### " << std::endl;

    x = 7;
    y = 9;
    swap_r(x,y);

    std::cout << "\n";
}