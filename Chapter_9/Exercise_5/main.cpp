#include "std_lib_facilities.h"

//---------------------------------------------------
// Create a Book object with the following data:
// Book {ISBN Number, Title, Author, Copyright Date}
//---------------------------------------------------


//---------------------------------------------------
// isbn_number
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
// Book
//---------------------------------------------------
class Book {
public:
    // object constructor
    Book(isbn_number ii, string tt, string aa, string cc);
    // check if book is available
    void const check_status();
    // check in / check out
    void cico();

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

private:
    /* members
     isbn, title, author, copyright date
     */
    isbn_number isbn; // returned by isbn class function
    string title;
    string author;
    string c_date;

    // book availability (true/false)
    bool available{true};

};

//---------------------------------------------------
// class functions
Book::Book(isbn_number ii, string tt, string aa, string cc)
        :isbn(ii), title(move(tt)), author(move(aa)), c_date(move(cc)) { }

void const Book::check_status() {
    if (!available) {
        cout << "Book not available!\n";
    }
    else {
        cout << "Book available!\n";
    }
}

void Book::cico() {
    // switch true / false (false by default)
    if (!Book::available) {
        available = true;
    }
    else {
        available = false;
    }
}

//---------------------------------------------------
// f()
void f() {
    // first generate an ISBN number for the book
    isbn_number isbn_book_1 {23, 15, 5003, 'f'};
    // then create a book with the ISBN number and other details
    Book book_1 {isbn_book_1, "Linux Pocket Guide", "Daniel J Barrett", "2018-08-17"};
    // print book
    cout << "book_1:\n";
    cout << book_1.ret_isbn() << ", " << book_1.ret_title()
         << ", " << book_1.ret_author() << ", "
         << book_1.ret_c_date() << endl;
    // check if book is available
    book_1.check_status();
    // check it out
    book_1.cico();
    // check if book is available
    book_1.check_status();
    // check it in using the same method
    book_1.cico();
    // check if book is available
    book_1.check_status();
    // the EnD!
}

//---------------------------------------------------
// RUN MAIN
int main() {
    f();
}
