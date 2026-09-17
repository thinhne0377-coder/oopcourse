#include <iostream>
#include <string>

using namespace std;

struct Book {
    int id;
    string name;
    string author;

    void inputInfo() {
        cin >> name;
        cin >> author;
        cin >> id;
    }

    void outputInfo() {
        cout << name;
        cout << id;
        cout << author;
    }
};

struct Library {
    int idLibrary;
    string nameLibrary;
    int numBooks;
    Book books[100];

    void inputLibrary() {
        cin >> idLibrary;
        cin >> nameLibrary;
        cin >> numBooks;

        for (int i = 0; i < numBooks; i++) {
            cin >> books[i].id;
            cin >> books[i].name;
            cin >> books[i].author;
        }
    }

    void outputLibrary() {
        cout << idLibrary;
        cout << nameLibrary;
        cout << numBooks;

        for (int i = 0; i < numBooks; i++) {
            cout << books[i].id;
            cout << books[i].name;
            cout << books[i].author;
        }
    }

    void addBook(Book a) {
        books[numBooks] = a;
        numBooks++;
    }

    void getBookInfo(int idBook) {
        for (int i = 0; i < numBooks; i++) {
            if (books[i].id == idBook) {
                books[i].outputInfo();
            }
        }
    }

    Book getBookInfo(int idBook) {
        for (int i = 0; i < numBooks; i++) {
            if (books[i].id == idBook) {
                return books[i];
            }
        }

        // trong truong hop khong tim thay
        Book book;
        book.id = -1;
        return book;
    }

    Book* getBooks() {
        return books;
    }
};

int main() {

    Library library;

    library.inputLibrary();

    library.outputLibrary();

    return 0;
}