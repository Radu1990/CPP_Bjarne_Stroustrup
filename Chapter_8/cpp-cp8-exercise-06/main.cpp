#include "std_lib_facilities.h"

//-------------------------------------------------------------------------------------
// Random funcs
//-------------------------------------------------------------------------------------
// prints the contents of an string vector
void print(const string& x, const vector<string>& y) {

    cout << "Printing vector: " << x << " - begin\n\n" ;
    for (int i=0; i < y.size(); ++i) {
        cout << x << " " << i << " = "
             << y[i] << endl;
    }
    cout << "\nPrinting vector: " << x << " - end\n\n" ;
}
//-------------------------------------------------------------------------------------
// creates new vector with elements in reversed position
vector<string>swap_vector_v1(const vector<string>& v) {
    // creating new empty vector
    vector<string>new_vector;
    // looping backwards through the vector
    // from the last element down to the first
    for (int i = v.size()-1; i > -1; --i) {
        string last_val = v[i]; // assigning to last val the vector's value
        new_vector.push_back(last_val); // pushing it in the new vector
    }
    // return the new vector
    return new_vector;
}
//-------------------------------------------------------------------------------------
// swaps two vector elements
void swap_element(string& x, string& y){
    string temp = x;
    x = y;
    y = temp;
}
// orders decreasingly the elements of
// an increasingly ordered vector
vector<string>swap_vector_v2(vector<string>& v) {
    // example [1,2,3,4]
    while (v[0] < v[1]) {
        int j = 1;
        for (int i = 0; i < v.size()-1; ++i) {
            string curr_val = v[i];
            string next_val = v[j];
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
void func_1() {
    vector<string> some_vector{"1.1.Linux", "1.2.Pocket", "1.3.Guide", "2.1.Introduction", "2.2.To", "2.3.Algorithms"};
    print("Book", some_vector);
}
//-------------------------------------------------------------------------------------
void func_3_1() {
    vector<string> some_vector{"1.1.Linux", "1.2.Pocket", "1.3.Guide", "2.1.Introduction", "2.2.To", "2.3.Algorithms"};
    vector<string>reversed_vector = swap_vector_v1(some_vector);
    print("Rev", reversed_vector);
}
//-------------------------------------------------------------------------------------
void func_3_2() {
    vector<string> some_vector{"1.1.Linux", "1.2.Pocket", "1.3.Guide", "2.1.Introduction", "2.2.To", "2.3.Algorithms"};
    print("Before reverse", some_vector);
    swap_vector_v2(some_vector);
    print("After reverse", some_vector);
}
//-------------------------------------------------------------------------------------
int main(){
//    func_1();
//    func_3_1();
    func_3_2();
}
// Take these changes too pls
