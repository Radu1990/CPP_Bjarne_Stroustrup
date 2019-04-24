#include "std_lib_facilities.h"

//-------------------------------------------------------------------------------------
// Random funcs
//-------------------------------------------------------------------------------------
// prints the contents of an int vector
void print(const string& x, const vector<int>& y) {

    cout << "Printing vector: " << x << " - begin\n\n" ;
    for (int i=0; i < y.size(); ++i) {
        cout << x << " " << i << " = "
             << y[i] << endl;
    }
    cout << "\nPrinting vector: " << x << " - end\n\n" ;
}
//-------------------------------------------------------------------------------------
// returns a vector containing fibonacci numbers
const vector<int> fibonacci (int x, int y, int n) {
    vector<int>f(n); // fibonacci_vector with n elements
    f[0] = x; // first element is x
    f[1] = y; // second element is y
    // for loop which adds the elements in the f vector
    for (int i = 2; i < n; ++i) { // starting loop from the 3rd element
        // compute next value to be pushed back in the vector
        int next_val = f[i-1] + f[i-2];
        // assign the value to the corresponding slot in the vector
        f[i] = next_val;
    }
    return f;
}
//-------------------------------------------------------------------------------------
// creates new vector with elements in reversed position
vector<int>swap_vector_v1(const vector<int>& v) {
    // creating new empty vector
    vector<int>new_vector;
    // looping backwards through the vector
    // from the last element down to the first
    for (int i = v.size()-1; i > -1; --i) {
        int last_val = v[i]; // assigning to last val the vector's value
        new_vector.push_back(last_val); // pushing it in the new vector
    }
    // return the new vector
    return new_vector;
}
//-------------------------------------------------------------------------------------
// swaps two vector elements
void swap_element(int& x, int& y){
    int temp = x;
    x = y;
    y = temp;
}
// orders decreasingly the elements of
// an increasingly ordered vector
vector<int>swap_vector_v2(vector<int>& v) {
    // example [1,2,3,4]
    while (v[0] < v[1]) {
        int j = 1;
        for (int i = 0; i < v.size()-1; ++i) {
            int curr_val = v[i];
            int next_val = v[j];
            // swap the two
            if (curr_val < next_val) {
                swap_element(curr_val, next_val);
                v[i] = curr_val;
                v[j] = next_val;
            }
            ++j;
        }
    }
    return v;
}

//-------------------------------------------------------------------------------------
// Exercises funcs
//-------------------------------------------------------------------------------------
// ex 1
void func_1() {
    vector<int> some_vector{100, 200, 300, 400, 500, 600, 700, 800};
    print("Candy", some_vector);
}
//-------------------------------------------------------------------------------------
// ex 2
void func_2() {
    // creating fibonacci vector with 10 elements and first 2 elements 1 and 2
    const vector<int>f_vector = fibonacci(1, 2, 100);
    // printing fibonacci vector
    print("Fibonacci", f_vector);
    //printing maximum value stored in an int
    int max_value = f_vector[44];
    cout << "Maximum value stored in an integer is f_vector[44] = " << max_value << endl;
}
//-------------------------------------------------------------------------------------
// ex 3.1
void func_3_1() {
    vector<int> some_vector{100, 200, 300, 400, 500, 600, 700, 800};
    vector<int>reversed_vector = swap_vector_v1(some_vector);
    print("Rev", reversed_vector);
}
//-------------------------------------------------------------------------------------
// ex 3.2
void func_3_2() {
    vector<int> some_vector{100, 200, 300, 400, 500, 600, 700, 800};
    print("Before reverse", some_vector);
    swap_vector_v2(some_vector);
    print("After reverse", some_vector);
}

//-------------------------------------------------------------------------------------
int main(){
    // ex 1
//    func_1();
    //ex 2
//    func_2();
    // ex 3.1
//    func_3_1();
    // ex 3.2
    func_3_2();
}
