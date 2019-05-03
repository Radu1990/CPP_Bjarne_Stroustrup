#include "std_lib_facilities.h"

//---------------------------------------------------
// Create a Book object with the following data:
// Book {ISBN Number, Title, Author, Copyright Date}
//---------------------------------------------------
class Date{
public:
    class Invalid{}; // to throw as exception
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
    string ret_date () const {
        string date = to_string(day()) + "-" + to_string(month()) + "-" + to_string(year());
        return date;
    }

private:
    int y;
    int m;
    int d;
};
//---------------------------------------------------
// isbn_number class - isbn data
//---------------------------------------------------
class isbn_number {
public:
    class Invalid{}; // to throw as exception
    isbn_number(int n1, int n2, int n3, char n4); // constructor
    bool isbn_check(); // checks if input is ok
    string ret_string() const; // returns single string from this struct

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

string isbn_number::ret_string() const {
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
// Book class - book data
//---------------------------------------------------
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

    const vector<string>
    genre_enum{"fiction", "nonfiction", "mathematics", "computerscience", "biography", "children"};
};

//---------------------------------------------------
// class member functions
//---------------------------------------------------
Book::Book(Genre gg, isbn_number ii, string tt, string aa, string cc)
        :genre(gg), isbn(ii), title(move(tt)), author(move(aa)), c_date(move(cc)) { }

// check status if checked out or not
void const Book::check_status() {
    if (!available) {
        cout << "Book not available!\n";
    }
    else {
        cout << "Book available!\n";
    }
}

// check in / check out
void Book::checkio() {
    // switch true / false (false by default)
    available = !Book::available;
}
// return string from array corresponding to the Genre integer
string Book::ret_genre() {
    return genre_enum[genre];
}
// write book infos into output stream
ostream& Book::operator<<(ostream& os) {
    return os << ret_genre() << "\n"
              << ret_author() << "\n"
              << ret_title() << "\n"
              << ret_c_date() << "\n"
              << ret_isbn() << "\n";
}

//---------------------------------------------------
// global functions
//---------------------------------------------------
// compare isbn
bool Book::operator==(const Book& b) {
    //return true if book a and b have SAME isbn
    return ret_isbn() == b.ret_isbn();
}
// compare isbn
bool Book::operator!=(const Book& b) {
    //return true if book a and b have SAME isbn
    return ret_isbn() != b.ret_isbn();
}

//---------------------------------------------------
// Patron class - username data
//---------------------------------------------------
class Patron {
public:
    class Invalid{}; // to throw as exception
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
//---------------------------------------------------
// class member functions
//---------------------------------------------------
Patron::Patron(string uu, int ll)
:un(move(uu)), lcn(ll) { }

// write book infos into output stream
ostream& Patron::operator<<(ostream& os) {
    return os << "username\t" << ret_username() << "\n"
              << "cardnumber\t" << ret_cardnumber() << "\n"
              << "owes fees\t" << ret_owes_fee_str() << "\n"
              << "fees\t\t"<< ret_fee() << "$\n";
}

// set fees
void Patron::set_fee(double n) {
    lf += n;
    owes_fee = {true};
}
void Patron::remove_fee(double n) {
    lf -= n;
    if (lf == 0) {
        owes_fee = {false};
    }
}


//---------------------------------------------------
// f() - testing Book class
//---------------------------------------------------
void f() {
    // first generate an ISBN number for the book
    // book_1: Algorithms
    isbn_number isbn_book_1 {0, 262, 3384, '4'};
    // book_2: Linux Guide
    isbn_number isbn_book_2 {9, 780, 59680634, '7'};
    // then create a book with the ISBN number and other details

    Book book_1 {Book::Genre::mathematics , isbn_book_1, "Introduction to Algorithms", "Thomas Cormen", "2009-01-01"};
    Book book_2 {Book::Genre::computerscience , isbn_book_2, "Linux Pocket Guide", "Daniel J Barrett", "2018-08-17"};
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
// g() - testing Patron class
//---------------------------------------------------
void g() {
    // creating patron obj
    Patron patron_1 {"Radu", 123456};
    // printing data
    patron_1.operator<<(cout);
    // setting fee of 1.99
    patron_1.set_fee(1.99);
    patron_1.operator<<(cout);
    // remove fee of 1.99
    patron_1.remove_fee(1.99);
    patron_1.operator<<(cout);
}
//---------------------------------------------------
// Library Class - holds patron, books and transactions data
//---------------------------------------------------
class Library {
public:
    Library() = default; // default constructor
    class Invalid{}; // to throw as exception

    // member functions
    void add_book(Book& bb);
    void add_patron(Patron& pp);
    bool checkok(Book& bb, Patron& pp);
    void check_out_book(Book& bb, Patron& pp, Date& dd); //check-out book if conditions are passed
    void read_transactions();
    void read_book_db();
    void read_patron_db();
    vector <Patron> ret_fee_owners(); // writes fee owners into vector member
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

void Library::add_book(Book& bb) {
    book_db.push_back(bb);
}

void Library::add_patron(Patron& pp) {
    patron_db.push_back(pp);
}

bool Library::checkok(Book& bb, Patron& pp){
    // check if Book is in db
    for (int i=0; i < book_db.size(); ++i) {
        if (book_db[i].ret_title() == bb.ret_title()) {
            break;
        }
        if (i == book_db.size()-1 && book_db[i].ret_title() != bb.ret_title()) {
            error("Book not in database!");
        }
    }
    // check if Patron is in db
    for (int i=0; i < patron_db.size(); ++i) {

        if (patron_db[i].ret_username() == pp.ret_username()) {
            break;
        }
        if (i == patron_db.size()-1 && patron_db[i].ret_username() != pp.ret_username()) {
            error("Patron not in database!");
        }
    }
    // check if Patron is in debt
    if (pp.ret_owes_fee_bool()) {
        cout << "Patron owes fees!\n";
        return false;
    }
    return true;
}

void Library::check_out_book(Book& bb, Patron& pp, Date& dd ) {
    if (Library::checkok(bb, pp)) {
        Transaction t {bb, pp, dd};
        // add transaction to the vector
        transactions.push_back(t);
    }
    else {
        throw Invalid{};
    }
}

void Library::read_transactions() {
    cout << "Listing Transactions:\n";
    int counter_transactions{0};
    for (const Transaction& x : transactions) {
        ++counter_transactions;
        cout << "Transaction:\t" << counter_transactions << "\n"
             << "Book:\t\t\t" << x.b.ret_title() << "\n"
             << "Patron:\t\t\t" << x.t.ret_username() << "\n"
             << "Date:\t\t\t" << x.dd.ret_date() << "\n";
    }
}

void Library::read_book_db(){
    for (const Book& x : book_db) {
        cout << x.ret_title() << "\n";
    }

}

void Library::read_patron_db(){
    for (const Patron& x : patron_db) {
        cout << x.ret_username() << "\n";
    }

}

vector<Patron> Library::ret_fee_owners(){
    for (const Patron& x : patron_db) {
        if (x.ret_owes_fee_bool()){
            fee_owners.push_back(x);
        }
    }
    return fee_owners;
}

void Library::read_fee_owners(){
    cout << "Listing fee owners:\n";
    for (Patron x : fee_owners) {
        cout << x.ret_username() << "\n";
    }
}



//---------------------------------------------------
// h() - testing Library class
//---------------------------------------------------
void h() {
    // creating Patrons
    Patron patron_1{"Radu", 123456};
    Patron patron_2{"Maria", 564895};
    // setting fee for patron_2
    patron_2.set_fee(1.99);
    // creating books
    isbn_number isbn_book_1 {0, 262, 3384, '4'};
    isbn_number isbn_book_2 {9, 780, 59680634, '7'};
    Book book_1 {Book::Genre::mathematics , isbn_book_1, "Introduction to Algorithms", "Thomas Cormen", "2009-01-01"};
    Book book_2 {Book::Genre::computerscience , isbn_book_2, "Linux Pocket Guide", "Daniel J Barrett", "2018-08-17"};
    // creating library
    Library library_1;
    // adding books and patrons to library database
    library_1.add_patron(patron_1);
    library_1.add_patron(patron_2);
    library_1.add_book(book_1);
    library_1.add_book(book_2);
    // creating dates
    Date d1 {2, 5, 2019};
    Date d2 {3, 5, 2019};
    // checking book out from library
    library_1.check_out_book(book_1, patron_1, d1);
    library_1.read_transactions();
    library_1.ret_fee_owners();
    library_1.read_fee_owners();
    
}

//---------------------------------------------------
// RUN MAIN
int main() {
//    f(); // Book class test
//    g(); // Patron class test
    h(); // Library class test
}
