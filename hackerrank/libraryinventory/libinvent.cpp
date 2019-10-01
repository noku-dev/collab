#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <iterator>
using namespace std;

struct Book {
    int book_id;
    int borrower_id;
    int bookshelf_num;
    friend ostream& operator<< (ostream &out, const Book &book);
    friend istream& operator>> (istream &in, Book &book);
};

ostream& operator<< (ostream &out, const Book &book) {
  out << "Book id : " << book.book_id << " Borrower id : " <<
  book.borrower_id << " Book shelf : " << book.bookshelf_num;
  return out;
}

istream& operator>> (istream &in, Book &book) {
  // New book doesn't have a borrower yet
  book.borrower_id = 0;
  in >> book.book_id >> book.bookshelf_num;
  return in;
}


class Library {
public:
  void add_book(const string book_title, int book_id, int bookshelf_num){
    library[book_title].push_back({book_id, 0, bookshelf_num});
  }
  void add_book(const string book_title, const Book &book){
    library[book_title].push_back(book);
  }
  Book borrow_book(const string book_title, int borrower_id) {
    Book borrowed_book = {-1,-1,-1};
    if (library.find(book_title) != library.end()) {
      // Title found, see if there is a book that can be borrowed.
      auto &book_list = library[book_title];
      for (auto &bk : book_list) {
        if (bk.borrower_id == 0) {
          bk.borrower_id = borrower_id;
          return bk;
        }
      }
    }
    return borrowed_book;
  }
  void return_book(const string book_title, int book_id) {
    if (library.find(book_title) != library.end()) {
      // Title found, see if there is a book that can be borrowed.
      auto &book_list = library[book_title];
      for (auto &bk : book_list) {
        if (bk.book_id == book_id) {
          bk.borrower_id = 0;
        }
      }
    }
  }
  void check_book_status(const string book_title, int book_id) {
    // cout borrowed and borrower_id or available and bookshelf_id
    if (library.find(book_title) != library.end()) {
      // Title found, see if there is a book that can be borrowed.
      auto &book_list = library[book_title];
      for (auto const &bk : book_list) {
        if (bk.book_id == book_id) {
          if (bk.borrower_id == 0) {
            cout << "available" << endl << endl;
          } else {
            cout << "borrowed by " << bk.borrower_id << endl << endl;
          }
        }
      }
    }
  }

  void check_book_status(int book_id) {
    // cout borrowed and borrower_id or available and bookshelf_id
    for (auto const &book_list : library) {
      for (auto const &bk : book_list.second) {
        if (bk.book_id == book_id) {
          if (bk.borrower_id == 0) {
            cout << "available" << endl << endl;
          } else {
            cout << "borrowed by " << bk.borrower_id << endl << endl;
          }
        }
      }
    }
  }


  void print_library() {
    for (auto &book_title : library) {
      cout << "Title : " << book_title.first << endl;
      for (auto book_item : book_title.second) {
        cout << book_item << endl;
      }
    }
    cout << endl;
  }
private:
  map<string,list<Book>> library;

};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    Library lib;
    Book tmp;
    lib.add_book("Hamlet", 1, 1);
    lib.add_book("Hamlet", 2, 1);
    lib.add_book("Othello", 3, 2);
    lib.add_book("Othello", 4, 1);
    lib.add_book("Othello", 5, 2);
    lib.print_library();
    tmp = lib.borrow_book("Hamlet", 1000);
    lib.print_library();
    auto bkid = tmp.book_id;
    tmp = lib.borrow_book("Hamlet", 1001);
    lib.check_book_status("Hamlet", 2);
    lib.print_library();
    lib.return_book("Hamlet", bkid);
    lib.check_book_status(bkid);
    lib.print_library();

    int num_book;
    string book_title;
    Book tmpbook;
    while (true) {
      cin >> book_title;
      // Done capturing input when title is DONENOD123
      if (book_title == "DONENOD123") {
        break;
      }
      cin >> num_book;
      for (int i = 0 ; i < num_book ; i++) {
        cin >> tmpbook;
        lib.add_book(book_title, tmpbook);
      }
    }
    lib.print_library();
    return 0;
}
