#include "std_lib_facilities.h"

class Book {
public:
    /* members
     ISBN, title, author, copyright date
     */
    string ISBN;
    string title;
    string author;
    string c_date; // copyright date
    Book(string ii, string tt, string aa, string cc);
    // book checkout out (true/false)
    // functions returning these
    // functions for checking in and out
    // validation of data entered in the book: eg. ISBN only in form of n-n-n-x, n-int x-digit or letter store isbn as string

};
Book::Book(string ii, string tt, string aa, string cc)
:ISBN(move(ii)), title(move(tt)), author(move(aa)), c_date(move(cc)) { }

void f() {
    Book("bla","bla","bla","bla");
}

int main() {

}
