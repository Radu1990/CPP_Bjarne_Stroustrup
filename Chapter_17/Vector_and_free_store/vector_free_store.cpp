#include "vector_free_store.h"
#include "std_lib_facilities.h"

// This program includes the Theory from
// Chapter 17: Vector and Free Store

// 17.1 Introduction

// 17.2 Vector Basics
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

// 17.3 Memory, addresses, and pointers


void f_1() {
    int x = 17;
    int *pi = &x; // pointer to int

    double e = 2.71828;
    double *pd = &e; // pointer to double

    cout << "\n";
    cout << "pi==" << pi << "; contents of pi==" << *pi << "\n";
    cout << "pd==" << pd << "; contents of pd==" << *pd << "\n";
}

// 17.3.1 The sizeof operator
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

// 17.4 Free store and pointers
// 17.4.1 Free-store allocation
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

// 17.4.2 Access through pointers
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

// 17.4.3 Ranges
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

// 17.4.4 Initialization

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

// 17.4.5 The null pointer

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

// 17.4.6 Free-store deallocation

// The new operator allocates ("gets") memory from the free store.
// Memory is limited so we should also return memory to the free store.

double* calc(int res_size, int max){
    // leaks memory
    auto p = new double[max];
    auto res = new double[res_size];
    // use p to calculate results to be put in res
    delete[] p; // we don't need that memory anymore: free it
    return res;
}

void f_12(){
    double* r = calc(100, 1000);
    // use r
    cout << endl;
    cout << r << endl;
    delete[] r; // we don't need that memory anymore: free it
}
// as written each call of calc() "leaks" the doubles allocated for p.
// the call calc(100, 1000) will render the space needed for 1000 doubles
// unusable for the rest of the program.

// the operator for returning memory to the free store is called delete.

// 17.5 Destructors
// 17.5.1 Generated destructors

// If a member of a class has a destructor, then that destructor
// will be called when the object containing the member is destroyed.

// a very simplified vector of doubles
class vector_v3 {
private:
    int sz; // the size
    double* elem; // a pointer to the elements
public:
    // constructor
    explicit vector_v3(int s)
    // initialize sz and elem
    :sz{s}, elem{new double[s]}{
        for (int i=0;  i<s; ++i) {
            elem[i] = 0; // initialize elements
        }
    }
    // destructor
    ~vector_v3() {
        delete[]elem; // free memory
    }

    int size() const {
        return sz; // the current size
    }
    // ...
};
// 17.5.2 Destructors and free store

void f_13(int n) {
    auto p = new double[n]; // allocate n doubles ---> useless now
    vector_v3 v(n); // the vector allocates n doubles
    // ... use p and v ...
    delete[]p; // deallocate p's doubles ---> useless now
    // vector automatically cleans up after v
    // so delete and allocation of memory is not needed here anymore
}

/*
 * Try this:
 * Write a program using base classes and members where you
 * define the constructors and destructors to output a line
 * of information when they are called.
 */

struct A {
private:
    // member
    double* elem; // a pointer to the elements
public:
    // constructor
    explicit A(int s)
    :elem{new double[s]}{
        for (int i=0;  i<s; ++i) {
            elem[i] = 0; // initialize elements
        }
        cout << "\n >>> Constructor for A was called <<<\n";
    }
    // destructor
    ~A(){
        delete[]elem;
        cout << "\n >>> Destructor for A was called <<<\n";
    }
};

void f_14() {
    // 1. create object
    A a1_object{5};
    // 2. call f_14
    // 3. expect to see the print messages for Constructor and Destructor
}

// 17.6 Access to elements

class vector_v4{
private:
    int sz; // the size
    double* elem; // a pointer to the elements
public:
    explicit vector_v4(int s)
    :sz{s}, elem{new double[s]} { // constructor
        // ...
        cout << "\n >>> Constructor for A was called <<<\n";
    }

    ~vector_v4() { // destructor
        delete[] elem;
        cout << "\n >>> Destructor for A was called <<<\n";
    }

    int size() const { // the current size
        return sz;
    }

    double get(int n) const { // access: read
        return elem[n];
    }

    void set(int n, double v) { // access: write
        elem[n]=v;
    }
};

void f_15(){
    vector_v4 v(5);
    for (int i = 0; i<v.size(); ++i) {
        v.set(i, 1.1*i);
        cout << endl;
        cout << "v["<<i<<"]=="<<v.get(i)<<'\n';
    }
}

// 17.7 Pointers to class objects
// We can point to just about anything we can place in memory.
// eg. vectors, chars...etc.

vector_v4* some_func(int s){
    auto p = new vector_v4(s); // allocate a vector on free store
    // fill *p
    return p;
}

void f_16(){
    vector_v4* q = some_func(4);
    // use *q
    delete q; // free vector on free store
    // when we delete a vector
    // its destructor is called
}

void f_17(){
    // note that all classes support the operator . (dot)
    // for accessing members, given the name of an object:
    vector_v4 v(4);
    int x = v.size();
    double d = v.get(3);

    // similary all classes support the operator -> (arrow)
    // for accessing members, given a pointer to an object:

    auto p = new vector_v4(4);
    int x_2 = p->size();
    double d_2 = p->get(3);
}

// 17.8 Messing with types: void* and casts

void f_18(){
    // The type void* means "pointer to some memory the compiler
    // doesn't know the type of."
    void* pv1 = new int; // OK: int* converts to void*
    void* pv2 = new double[10]; // OK: double* converts to void*
}

void f_19(void* pv){
    // since the compiler doesn't know
    // what a void* points to, we must tell it:
    void* pv2 = pv; // copying is OK (copying is what void*s are for)
//    double* pd = pv; // error: can not convert void to double
//    *pv = 7; // error: can not dereference a void
               // (we don't know what type of object it points to)
//    pv[2] = 9; // error: cannot subscript a void*
    int * pi = static_cast<int*>(pv); // OK: explicit conversion
}

// 17.9 Pointers and references

void f_20(){
    int x = 10;
    int* p = &x; // you need & to get a pointer
    *p = 7; // use * to assign to x through p
    int x2 = *p; // read x through p and assign to x2
    int* p2 = &x2; // get a pointer to another int
    p2 = p; // p2 and p both point to x
    p = &x2; // make p point to another object

    // The corresponding example for references is:

    int y = 10;
    int& r = y; // the & is in the type, not in the initializer
    r = 7; // assign to y through r (no * needed)
    int y2 = r; // read y through r (no * needed) and assign to y2
    int& r2 = y2; // get a reference to another int
    r2 = r; // the value of y is assigned to y2
//    r = &y2; // error: you can't change the value of a reference
               // ( no assignment of an int* to an int&)


}

// 17.9.1 Pointer and reference parameters

// when you want to change the value of a variable
// to a value computed by a function you have 3 options:

// compute a new value and return it
int incr_v(int x) {
    return x+1;
}

// pass a pointer (dereference it and increment the result)
void incr_p(int* p) {
    ++*p;
}

// pass a reference
void incr_r(int& r) {
    ++r;
}

// 17.9.2 Pointers, references, and inheritance

// Circle is a derived class from Shape
// a Circle* can be implicitly converted to a Shape*
// because Shape is a public base of Circle
struct Shape{};
struct Circle: Shape {};
void rotate(Shape* s, int n); // rotate *s n degrees

//void f_21(){
//    auto p = new Circle;
//    Circle c;
//    rotate(p, 35);
//    rotate(&c, 45);
//}

// similarly for references
void rotate_2(Shape& s, int n); // rotate s n degrees

//void f_22(){
//    auto p = new Circle;
//    Circle c;
//    Shape& r = c;
//    rotate_2(r, 55);
//    rotate_2(*p, 65);
//    rotate_2(c, 75);
//}

// 17.9.3 An example: lists
struct Link {
    string value;
    Link* prev;
    Link* succ;
    // we use nullptr to indicate that a Link
    // doesn't have a successor or a predecessor
    explicit Link(string v, Link* p = nullptr, Link* s = nullptr) // constructor
    :value{std::move(v)}, prev{p}, succ{s} {}
};

Link* insert(Link* p, Link* n){
    if (n== nullptr) return p;
    if (p== nullptr) return n;
    n->succ = p; // p comes after n
    if (p->prev) {
        p->prev->succ = n;
    }

    p->prev->succ = n; // n comes after what used to be p's predecessor
    n->prev = n; // n becomes p's predecessor
    return n;
}

void f_23(){
    // we can build our list like this
    Link* norse_gods = new Link{"Thor"};
    norse_gods = new Link{"Odin", nullptr, norse_gods};
    // this notation means get ng's succ and then that succ's prev and write in there the new link
    norse_gods->succ->prev = norse_gods;
    // this way both links point to each-other
    norse_gods = new Link{"Freia", nullptr, norse_gods};
    norse_gods->succ->prev = norse_gods; // same here
}

void f_24(){
    Link* norse_gods = new Link{"Thor"};
    norse_gods = insert(norse_gods, new Link{"Odin"});
    norse_gods = insert(norse_gods, new Link{"Freia"});
}

// 17.9.4 List operations

Link* add(Link* p, Link* n) { // insert n after p, return n
    if (n== nullptr) return p;
    if (p== nullptr) return n;
    p->succ = n; // n comes after p
    if(n->prev) {
        n->prev->succ=p;
    }
    p->prev = n->prev;
    n->prev = p;
    return n;
}

Link* erase(Link* p) { // remove *p from list; return p's successor
    if (p==nullptr){
        return nullptr;
    }
    if (p->succ) {
        p->succ->prev = p->prev;
    }
    if (p->prev) {
        p->prev->succ = p->succ;
    }
    return p->succ;
}

Link* find(Link* p, const string& s){ // find s in list; return nullptr for "not found"
    while (p) {
        if (p->value == s) {
            return p;
        }
        p = p->succ;
    }
    return nullptr;
}

Link* advance(Link* p, int n){
    // move n positions in list
    // return nullptr for "not found"
    // positive n moves forward, negative backward
    if (p== nullptr) {
        return nullptr;
    }
    if (0<n) {
        while (n--) {
            if (p->succ == nullptr) {
                return nullptr;
            }
            p = p->succ;
        }
    }
    else if (n<0) {
        while (n++) {
            if (p->prev == nullptr) {
                return nullptr;
            }
            p = p->prev;
        }
    }
    return p;
}