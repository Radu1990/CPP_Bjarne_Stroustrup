#include "drill.h"
#include "std_lib_facilities.h"

// This program includes the Drill Exercise from
// Chapter 14. Graphics Class Design


// 01. Define B1 class with a virtual function vf()
// and a non-virtual function f()

class B1{
public:
    virtual void vf()=0;
    virtual void f()=0;
    virtual void pvf()=0;
};

void B1::vf() {
    cout << "\n>>> function B1::vf() <<<\n";
}
void B1::f() {
    cout << "\n>>> function B1::f() <<<\n";
}

void B1::pvf() {
    cout << "\n>>> pure virtual function B1::pvf() <<<\n";
}

void f_1(){
    cout << "\nf_1:\n";
//    B1 b1_obj; // error: B1 is abstract
}

// 02. Derive D1 from B1 and override vf()

class D1: public B1 {
public:
    void vf() override;
    void f() override ;
    void pvf() override;
};

void D1::vf() {
    cout << "\n>>> function D1::vf() <<<\n";
}

void D1::f() {
    cout << "\n>>> function D1::f() <<<\n";
}
void D1::pvf() {
    cout << "\n>>> function D1::pvf() <<<\n";
}

void f_2(){
    cout << "f_2:\n";
    D1 d1_obj;

    d1_obj.vf();
    d1_obj.f();
    d1_obj.pvf();
}

// 03-04. Define a reference to B1(a B1&) and initialize that
// to the D1 object you just defined. Call vf() and f() for that reference

// 05. Add a pure virtual function called pvf() to B1
// and try to repeat 1-4.

void call(B1& b1_ref) {
    b1_ref.vf();
    b1_ref.f();
    b1_ref.pvf();
}

void f_3(){
    cout << "f_3:\n";
    D1 d1_obj;
    call(d1_obj);
}

// 06. Define a class D2 derived from D1 and override pvf() in D2.
// Make an object of class D2 and invoke f(), vf(), and pvf() for it.

class D2 : public D1 {
public:
    void vf() override;
    void f() override;
    void pvf() override;
};

void D2::vf() {
    cout << "\n D2::vf()\n";
}

void D2::f() {
    cout << "\n D2::f()\n";
}

void D2::pvf() {
    cout << "\n D2::pvf()\n";
}

void f_4(){
    cout << "f_4:\n";

    D2 d2_obj;

    d2_obj.f();
    d2_obj.vf();
    d2_obj.pvf();
}

/* 07. Define a class B2 with a pure virtual function pvf().
 * Define a class D21 with a string data member and a member function
 * that overrides pvf(); D21::pvf() should output the value of the string.
 * Define a class D22 that is just like D21 except that its data member is an int.
 * Define a function f() that takes a B2& argument and calls pvf() for its argument.
 * Call f() with a D21 and a D22.
*/

class B2 {
public:
    virtual void pvf() =0;
};

class D21 : public B2 {
public:
    string d21_string{"Radu"};
    void pvf() override;

};

void D21::pvf() {
    cout << "\nd21_string: " << d21_string << endl;
}

class D22 : public B2 {
public:
    int d22_int{1990};
    void pvf() override;

};

void D22::pvf() {
    cout << "\nd22_int: " << d22_int << endl;
}

void call_f(B2& b2_ref) {
    b2_ref.pvf();
}

void f_5(){
    cout << "f_5:\n";
    D21 d21_obj;
    D22 d22_obj;

    call_f(d21_obj);
    call_f(d22_obj);

}
