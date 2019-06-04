#include "vector_free_store.h"
#include "std_lib_facilities.h"

// This program includes the Theory from
// Chapter 17: Vector and Free Store

// a very simplified vector of doubles (like vector<double>)
class vector_v2 {
    int sz; // the size
    double *elem; // pointer to the first element (of type double)
public:
    // constructor: allocate s doubles
    // let elem point to them
    // store s in sz
    explicit vector_v2(int s);

    int size() const { return sz; } // the current size
};

// Memory, addresses, and pointers
int x = 17;
int *pi = &x; // pointer to int

double e = 2.71828;
double *pd = &e; // pointer to double

void f_1() {
    cout << "\n";
    cout << "pi==" << pi << "; contents of pi==" << *pi << "\n";
    cout << "pd==" << pd << "; contents of pd==" << *pd << "\n";
}

// The sizeof operator
void sizes(char ch, int i, int *p, bool b, double d) {
    cout << "the size of char is " << sizeof(char) << " or " << sizeof(ch) << " bytes\n";
    cout << "the size of int is " << sizeof(int) << " or " << sizeof(i) << " bytes\n";
    cout << "the size of int* is " << sizeof(int *) << " or " << sizeof(p) << " bytes\n";
    cout << "the size of bool is " << sizeof(bool) << " or " << sizeof(b) << " bytes\n";
    cout << "the size of double is " << sizeof(double) << " or " << sizeof(d) << " bytes\n";
}

void f_2() {
    char ch{'1'};
    int i{1};
    int *p = &i;
    bool b{false};
    double d{1.0};

    cout << endl;
    sizes(ch, i, p, b, d);

}

void f_3() {
    // How much memory is used by a vector
    vector<int> v(1000);
    cout << endl;
    cout << "the size of vector<int>v(1000) is " << sizeof(v) << "\n";
}

// Free store allocation and pointers
void f_4() {
    /*
     * Memory layout:
     * Code: memory for code
     * Static data: memory for global variables
     * Free store:
     * Stack: memory for calling functions (space for their arguments and local variables)
     */
    auto pi = new int; // allocate one int
    auto qi = new int[4]; // allocate 4 ints (an array of 4 ints)
    auto pd = new double; // allocate one double
    auto qd = new double[10]; // allocate n doubles (an array of doubles)
//    pi = pd; // error: can't assign a double* to an int*
//    pd = pi; // error: can't assign an int* to a double*
}

// Access through pointers
void f_5() {
    auto p = new double[4]; // allocate 4 doubles on the free store
    double x = *p;          // read the first object pointed to by p
    double y = p[2];        // read the 3rd obhect pointed to by p
    *p = 7.7; // write to the first object pointed to by p
    p[2] = 9.9; // write to the 3rd object pointed to by p
}

void f_6() {
    /* A pointer points to an object in memory.
     * The "contents of" operator (also called the
     * dereference operator) allows us to read and write
     * the object pointed to by a pointer p. */
    auto p = new double[4];
    double x = *p; // read the object pointed to by p
    *p = 8.8; // write the object pointed to by p
}

void f_7() {
    // When applied to a pointer the [] operator treats memory as
    // a sequence of objects (of the type specified by the pointer declaration)
    // with the first one pointed to by a pointer p
    auto p = new double[4];
    double x = p[3]; // read the 4th object pointed to by p
    p[3] = 4.4; // write to the 4th object pointed to by p
    double y = p[0]; // p[0] is the same as *p
}

// Ranges
void f_8(){
    // The major problem with pointers is that a pointer
    // doesn't know how many elements it points to
    auto pd =  new double[3];
    pd[2] = 2.2; // ok
    pd[4] = 4.4; // not ok
    pd[-3] = -3.3; // not ok

}

void f_9(){
    // Here q[700] refers to two different memory locations
    // and the last use is an out-of-range access and a likely disaster

    auto p = new double; // allocate a double
    auto q = new double[1000]; // allocate 1000 doubles

    q[700] = 7.7; // fine
    q = p; //let q point to the same address as p
    double d = q[700]; // out-of-range access!
}

// Understanding pointers is essential for understanding
// lots of real-world code

// Initialization

void f_10(){
    double* p0;  // uninitialized: likely trouble
    auto p1 = new double; // get (allocate) an uninitialized double
    auto p2 = new double{5.5}; // get a double initialized to 5.5
    auto p3 = new double[5]; // get (allocate) 5 uninitialized doubles

    auto p4 = new double[5]{0,1,2,3,4};

    // if a type X has a default constructor
    struct X{};
    X* px1 = new X; // one default-initialized X
    X* px2 = new X[17]; // 17 default-initialized Xs

    // if a type Y has a constructor, we have to explicitly initialize
    struct Y{
    public:
        Y(int s): number(s){}
    private:
        int number;
    };
//    Y* py1 = new Y; // error: no default constructor
    Y* py2 = new Y{13}; // OK: Initialized to Y{13}
//    Y* py3 = new Y[17]; // error: no default constructor
    Y* py4 = new Y[5]{0,1,2,3,4}; // OK

}

// The null pointer

void f_11(){
    double* p0 = nullptr;
    // when assigned to a pointer, the value zero is called the null pointer
    // and often we test if a pointer is valid by checking whether it is nullptr

    // this condition is
    if (p0 != nullptr) { // consider p0 valid
        // do something ...
    }
    // the same as this condition
    if (p0) {
        // do something ...
    }

    
}