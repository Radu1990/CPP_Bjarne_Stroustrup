#include "ex5.h"

//------------------------------------------------
// FUNCTIONS ISBN CLASS
//------------------------------------------------

struct MyException : std::exception
{
    const char* what() const noexcept override { return "Buggers!"; }
};

isbn_number::isbn_number(int n1, int n2, int n3, char n4)
        :number_1(n1), number_2(n2), number_3(n3), number_4(n4) {
    if (!isbn_check()){ // if this blows up throw invalid
        throw MyException{};
    }
}

bool isbn_number::isbn_check() { // this checks if input is ok
    return (isalnum(number_4));
}

string isbn_number::ret_string() const {

    vector<string> isbn_vec(4);
    // convert ints to string
    isbn_vec[0] = to_string(number_1);
    isbn_vec[1] = to_string(number_2);
    isbn_vec[2] = to_string(number_3);
    isbn_vec[3] = to_string(number_4);
    // convert vector elements to one single string of form (n - n - n - x)
    string isbn_name = isbn_vec[0] + "-" + isbn_vec[1] + "-" + isbn_vec[2] + "-" + isbn_vec[3];
    return isbn_name;
}

//------------------------------------------------
// FUNCTIONS DATE CLASS
//------------------------------------------------

string Date::ret_date () const {
string date = to_string(day()) + "-" + to_string(month()) + "-" + to_string(year());
return date;
}

//------------------------------------------------
// FUNCTIONS BOOK CLASS
//------------------------------------------------

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
//------------------------------------------------
// FUNCTIONS PATRON CLASS
//------------------------------------------------
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




//------------------------------------------------
// FUNCTIONS LIBRARY CLASS
//------------------------------------------------

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
            throw MyException{};
        }
    }
    // check if Patron is in db
    for (int i=0; i < patron_db.size(); ++i) {

        if (patron_db[i].ret_username() == pp.ret_username()) {
            break;
        }
        if (i == patron_db.size()-1 && patron_db[i].ret_username() != pp.ret_username()) {
            throw MyException{};
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
        throw MyException{};;
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
