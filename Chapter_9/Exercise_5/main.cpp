#include "std_lib_facilities.h"

//---------------------------------------------------
// Create a Book object with the following data:
// Book {ISBN Number, Title, Author, Copyright Date}
//---------------------------------------------------

//---------------------------------------------------
// isbn_number class
//---------------------------------------------------
class isbn_number {
public:
    class Invalid{}; // to throw as exception
    isbn_number(int n1, int n2, int n3, char n4); // constructor
    bool isbn_check(); // checks if input is ok
    string ret_string(); // returns single string from this struct

private:
    int number_1;
    int number_2;
    int number_3;
    char number_4;
};

//---------------------------------------------------
// class functions
//---------------------------------------------------
isbn_number::isbn_number(int n1, int n2, int n3, char n4)
        :number_1(n1), number_2(n2), number_3(n3), number_4(n4) {
    if (!isbn_check()){ // if this blows up throw invalid
        throw Invalid {};
    }
}

bool isbn_number::isbn_check() { // this checks if input is ok
    if (!isalnum(number_4)) {
        return false;
    }
    return true;
}

string isbn_number::ret_string() {
    vector<string>isbn_vec(4);
    // convert ints to string
    isbn_vec[0] = to_string(number_1);
    isbn_vec[1] = to_string(number_2);
    isbn_vec[2] = to_string(number_3);
    isbn_vec[3] = to_string(number_4);
    // convert vector elements to one single string of form (n - n - n - x)
    string isbn_name = isbn_vec[0] + "-" + isbn_vec[1] + "-" + isbn_vec[2] + "-" + isbn_vec[3];
    return isbn_name;
}

//---------------------------------------------------
// Book class
//---------------------------------------------------
class Book {
public:
    enum class Genre{
        fiction=1, nonfiction, mathematics, computerscience, biography, children
    };
    // object constructor
    Book(Genre gg, isbn_number ii, string tt, string aa, string cc);
    // check if book is available
    void const check_status();
    // check in / check out
    void checkio();

    // functions returning private members

    string ret_isbn() {
        return isbn.ret_string();
    }
    string ret_title() {
        return title;
    }
    string ret_author() {
        return author;
    }
    string ret_c_date() {
        return c_date;
    }
    // overloaded operators
    ostream& operator<<(ostream& os);


private:
    /* members
     isbn, title, author, copyright date
     */
    Genre genre;
    isbn_number isbn; // returned by isbn class function
    string title;
    string author;
    string c_date;

    // book availability (true/false)
    bool available{true};

};

//---------------------------------------------------
// class functions
//---------------------------------------------------
Book::Book(Genre gg, isbn_number ii, string tt, string aa, string cc)
        :genre(gg), isbn(ii), title(move(tt)), author(move(aa)), c_date(move(cc)) { }

void const Book::check_status() {
    if (!available) {
        cout << "Book not available!\n";
    }
    else {
        cout << "Book available!\n";
    }
}

void Book::checkio() {
    // switch true / false (false by default)
    available = !Book::available;
}

bool operator==(Book& a , Book& b) {
    //return true if book a and b have SAME isbn
    return a.ret_isbn() == b.ret_isbn();
}

bool operator!=(Book& a , Book& b) {
    //return true if book a and b have SAME isbn
    return a.ret_isbn() != b.ret_isbn();
}

ostream& Book::operator<<(ostream& os) {
    return os << ret_author() << "\n"
              << ret_title() << "\n"
              << ret_c_date() << "\n"
              << ret_isbn() << "\n";
}

//---------------------------------------------------
// f()
void f() {
    // first generate an ISBN number for the book
    // Algorithms
    isbn_number isbn_book_1 {0, 262, 3384, '4'};
    // Linux Guide
    isbn_number isbn_book_2 {9, 780, 59680634, '7'};
    // then create a book with the ISBN number and other details

    Book book_1 {Book::Genre::biography , isbn_book_1, "Introduction to Algorithms", "Thomas Cormen", "2009-01-01"};
    Book book_2 {4, isbn_book_2, "Linux Pocket Guide", "Daniel J Barrett", "2018-08-17"};
    // print book
    cout << "book_1:\n";
    cout << book_1.ret_isbn() << ", " << book_1.ret_title()
         << ", " << book_1.ret_author() << ", "
         << book_1.ret_c_date() << endl;
    // check if book is available
    book_1.check_status();
    // check-out
    book_1.checkio();
    // check if book is available
    book_1.check_status();
    // check-in using the same method
    book_1.checkio();
    // check if book is available
    book_1.check_status();
    // compare isbn of 2 different books using == operator
    if (book_1==book_2){
        cout << "Books have same isbn number!\n";
    }
    else {
        cout << "Books don't have same isbn number!\n";
    }
    // compare isbn of 2 different books using != operator
    if (book_1!=book_2){
        cout << "Books don't have same isbn number!\n";
    }
    else {
        cout << "Books have same isbn number!\n";
    }
    // print out Book infos using overloaded operator
    book_1.operator<<(cout);
    book_2.operator<<(cout);
}

//---------------------------------------------------
// RUN MAIN
int main() {
    f();
}
