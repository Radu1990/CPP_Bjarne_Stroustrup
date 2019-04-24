#include "std_lib_facilities.h"

// get input names and age from cin
// and sort name:age pairs alphabetically
// and output in cout
int main() {
    vector<string>name;
    string name_val;

    vector<double>age;
    double age_val;

    cout << "How many names are being added? ";
    int nr_names;
    cin >> nr_names;
    cout << "Please enter name and age for desired person: \n"
         << "Type | to finish\n";
    // inserting name - age values inside the two vectors
    while (cin && name.size() < nr_names) {
        cout << "Name: ";
        cin >> name_val;

        cout << "Age: ";
        cin >> age_val;

        name.push_back(name_val);
        age.push_back(age_val);
    }
    // printing name-age pairs
    cout << "\nPrinting Name-Age pairs:\n";
    for (int i = 0; i < name.size(); ++i) {
        cout << i << " " << name[i] << ":" << age[i] << endl;
    }
    // creating a copy of the name vector;
    vector<string>name_copy = name;
    vector<double>age_copy = age;
    // sorting the names in the first vector
    sort(name.begin(), name.end());
    // matching the sorted names with their corresponding ages
    for (int i = 0; i < name.size(); ++i) { // looping through sorted name list
        for (int j = 0; j < name_copy.size(); ++j) { // looping through unsorted name list
            if (name[i] == name_copy[j]) { // matching new names with old names
                age[i] = age_copy[j]; // overwrite ages in the new order
            }
        }
    }
    // printing sorted name-age pairs
    cout << "\nPrinting sorted Name-Age pairs:\n";
    for (int i = 0; i < name.size(); ++i) {
        cout << i << " " << name[i] << ":" << age[i] << endl;
    }
}
