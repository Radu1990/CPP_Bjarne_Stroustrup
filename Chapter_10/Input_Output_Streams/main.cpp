#include <iostream>
#include "std_lib_facilities.h"

struct Point {
    int x;
    int y;
};

vector<Point> original_points;
vector<Point> processed_points;

void read_vector(const vector<Point>& v) {
    cout << "Printing points...\n";
    for (Point p : v) {
        cout << "x: " << p.x << " "
             << "y: " << p.y << endl;
    }
}

void write_vector_to_file (const vector<Point>& pp, const string& name) {
    ofstream ost {name};
    if (!ost) error("can't open output file: data.txt");
    for (Point p : pp) {
        ost << '(' << p.x << ',' << p.y << ")\n";
    }
}

void fill_vector_from_file(vector<Point>& pp, const string& name) {
    ifstream is {name};
    if (!is) error("can't open input file!");
    while (true) {
        char ch1,ch2,ch3;
        int x,y;
        // check first char, if ok go to the next one
        if (is >> ch1 && ch1!='(') {
            is.unget();
            is.clear(ios_base::failbit);
            return;
        }
        // if end of file, break out from the loop
        if (!(is>>x)) break;
        is >> ch2 >> y >> ch3;
        if (!is || ch3 != ')') error("bad reading!\n"); // check last char
        pp.push_back(Point{x, y});
    }
}

void prompt_xy_pairs() {
    // prompt for 7 (x,y) pairs
    cout << "Please enter 2 (x,y) pairs:\n";
    for (int pairs = 0; pairs < 2; ++pairs) {
        Point p{}; cin >> p.x >> p.y;
        original_points.push_back(p);
    }
}

void vectors_check(const vector<Point>& a, const vector<Point>& b) {
    // first test: check if the sizes are matching
    if (a.size() != b.size()) return;
    // second test: check if elements are the same
    for (int i = 0; i < a.size(); ++i) {
        if (a[i].x != b[i].x || a[i].y != b[i].y) {
            error("Values are not the same, check files again.");
        }
    }
    cout << "VECTOR CHECK: OK!";
}

int main(){
    // prompt for 7 (x,y) pairs write values to vector
    prompt_xy_pairs();

    // read 1st vector
    read_vector(original_points);

    // write vector values to file
    write_vector_to_file(original_points, "data.txt");

    // read file and write values to other vector
    fill_vector_from_file(processed_points, "data.txt");

    // read other vector
    read_vector(processed_points);

    //compare vectors
    vectors_check(original_points, processed_points);

}
