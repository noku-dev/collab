#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <iterator>
using namespace std;

struct book {
    int book_id;
    int borrower_id;
    int bookshelf_num;
};

class Library {
public:
  void add_book(const string book_title, int book_id, int bookshelf_num){
    library[book_title].push_back({book_id, 0, bookshelf_num});
  }
  book borrow_book(const string book_title, int borrower_id) {
    book borrowed_book = {-1,-1,-1};
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
        cout << "Book id : " << book_item.book_id << " Borrower id : " <<
        book_item.borrower_id << " Book shelf : " << book_item.bookshelf_num <<
        endl;
      }
    }
    cout << endl;
  }
private:
  map<string,list<book>> library;

};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    Library lib;
    book tmp;
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

    return 0;
}
