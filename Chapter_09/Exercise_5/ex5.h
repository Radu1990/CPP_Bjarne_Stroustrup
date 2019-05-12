using namespace std;
#include "string"
#include "vector"
#include "iostream"
#include "exception"

#ifndef EXERCISE_3_EX5_H
#define EXERCISE_3_EX5_H

class Date{
public:

    Date (int y, int m, int d)
            :d(d), m(m), y(y) {} // check for valid date and initialize

    // non-modifying operations:
    int day() const {
        return d;
    }
    int month() const {
        return m;
    }
    int year() const {
        return y;
    }
    string ret_date () const;

private:
    int y;
    int m;
    int d;
};

class isbn_number { // ISBN NUMBER IN THE FORM nnnx - where n is an int and x an alphanumeric digit
public:

    isbn_number(int n1, int n2, int n3, char n4); // constructor
    bool isbn_check(); // checks if input is ok
    string ret_string() const; // returns single string from this struct

private:
    int number_1;
    int number_2;
    int number_3;
    char number_4;
};

class Book {
public:
    enum Genre{
        mathematics=0, computerscience
    };

    // object constructor
    Book(Genre gg, isbn_number ii, string tt, string aa, string cc);

    // check if book is available
    void const check_status();
    // check in / check out
    void checkio();

    // functions returning private members
    string ret_genre();

    string ret_isbn() const {
        return isbn.ret_string();
    }
    string ret_title() const {
        return title;
    }
    string ret_author() const {
        return author;
    }
    string ret_c_date() const {
        return c_date;
    }

    // overloaded operators
    // write into output stream
    ostream& operator<<(ostream& os);
    bool operator==(const Book& b);
    bool operator!=(const Book& b);


private:

    Genre genre;
    isbn_number isbn; // returned by isbn class function
    string title;
    string author;
    string c_date; // copyright date

    // book availability (true/false)
    bool available{true};

    const vector<string> genre_enum{
        "fiction", "nonfiction", "mathematics", "computerscience", "biography", "children"
    };
};

class Patron {
public:

    Patron(string uu, int ll); // constructor

    // members functions
    string ret_username() const {
        return un;
    }
    int ret_cardnumber() {
        return lcn;
    }
    // return string
    string ret_owes_fee_str() {
        if (owes_fee) {
            return "Yes";
        }
        else {
            return "No";
        }
    }
    bool ret_owes_fee_bool() const {
        return owes_fee;
    }
    double ret_fee() {
        return lf;
    };

    void set_fee(double n); // set fee by amount n
    void remove_fee(double n);
    // print info
    ostream& operator<<(ostream& os);


private:
    string un; // username
    int lcn; // library card number of form xxxxxx
    double lf {0}; // library fees in $
    bool owes_fee {false}; // owes fees or not
};

class Library {
public:
    Library() = default; // default constructor

    // member functions
    void add_book(Book& bb);
    void add_patron(Patron& pp);
    bool checkok(Book& bb, Patron& pp);
    void check_out_book(Book& bb, Patron& pp, Date& dd); //check-out book if conditions are passed
    void read_transactions();
    void read_book_db();
    void read_patron_db();
    vector<Patron> ret_fee_owners(); // writes fee owners into vector member
    void read_fee_owners(); // reads fee owners from vector

private:
    vector<Book> book_db;
    vector<Patron> patron_db;

    struct Transaction {
        Book b;
        Patron t;
        Date dd;
    };
    vector<Transaction> transactions;
    vector<Patron> fee_owners;
};

#endif //EXERCISE_3_EX5_H
