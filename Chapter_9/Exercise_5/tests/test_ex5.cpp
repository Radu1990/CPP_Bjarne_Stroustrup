#include "gtest/gtest.h"
#include "../ex5.h"

TEST(testingBookClass, test1) {

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

TEST(testingPatronClass, test1) {
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

TEST(testingLibraryClass, test1){
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
