#include <iostream>
#include <string>

using namespace std;

// =====================================
// STRUCT BOOK
// =====================================
struct Book {
    int id;
    string name;
    string author;

    // Nhap thong tin sach
    void inputInfo() {
        cout << "Nhap ID sach: ";
        cin >> id;

        cout << "Nhap ten sach: ";
        cin >> name;

        cout << "Nhap tac gia: ";
        cin >> author;
    }

    // Xuat thong tin sach
    void outputInfo() {
        cout << "ID: " << id << endl;
        cout << "Ten sach: " << name << endl;
        cout << "Tac gia: " << author << endl;
    }
};


// =====================================
// STRUCT LIBRARY
// =====================================
struct Library {
    int idLibrary;
    string nameLibrary;

    int numBooks;

    // Mang sach
    Book books[100];

    // Nhap thong tin thu vien
    void inputLibrary() {
        cout << "Nhap ID thu vien: ";
        cin >> idLibrary;

        cout << "Nhap ten thu vien: ";
        cin >> nameLibrary;

        cout << "Nhap so luong sach: ";
        cin >> numBooks;

        for (int i = 0; i < numBooks; i++) {
            cout << "\n--- Nhap sach thu " << i + 1 << " ---" << endl;

            cin >> books[i].id;
            cin >> books[i].name;
            cin >> books[i].author;
        }
    }

    // Xuat thong tin thu vien
    void outputLibrary() {
        cout << "\n=================================" << endl;
        cout << "ID thu vien: " << idLibrary << endl;
        cout << "Ten thu vien: " << nameLibrary << endl;
        cout << "So luong sach: " << numBooks << endl;

        cout << "\nDanh sach sach:" << endl;

        for (int i = 0; i < numBooks; i++) {
            cout << "\n--- Sach thu " << i + 1 << " ---" << endl;
            cout << "ID: " << books[i].id << endl;
            cout << "Ten sach: " << books[i].name << endl;
            cout << "Tac gia: " << books[i].author << endl;
        }
    }

    // =====================================
    // THEM MOT QUYEN SACH
    // =====================================
    void addBook(Book a) {
        books[numBooks] = a;
        numBooks++;
    }

    // =====================================
    // TIM SACH THEO ID
    // =====================================
    Book getBookInfo(int idBook) {
        for (int i = 0; i < numBooks; i++) {
            if (books[i].id == idBook) {
                return books[i];
            }
        }

        // Neu khong tim thay
        Book emptyBook;
        emptyBook.id = -1;
        return emptyBook;
    }

    // =====================================
    // TRA VE DANH SACH SACH
    // =====================================
    void getBooks() {
        for (int i = 0; i < numBooks; i++) {
            books[i].outputInfo();
        }
    }
};


// =====================================
// MAIN
// =====================================
int main() {

    Library library;

    // Nhap thu vien
    library.inputLibrary();

    // Xuat thu vien
    library.outputLibrary();

    // =====================================
    // THEM SACH
    // =====================================

    Book newBook;

    cout << "\n\n=== THEM SACH MOI ===" << endl;

    newBook.inputInfo();

    library.addBook(newBook);

    // Xuat lai danh sach
    cout << "\n\n=== DANH SACH SAU KHI THEM ===" << endl;

    library.outputLibrary();


    // =====================================
    // TIM SACH THEO ID
    // =====================================

    int idSearch;

    cout << "\nNhap ID sach can tim: ";
    cin >> idSearch;

    Book result = library.getBookInfo(idSearch);

    if (result.id == -1) {
        cout << "Khong tim thay sach!" << endl;
    }
    else {
        cout << "\nTim thay sach:" << endl;
        result.outputInfo();
    }

    return 0;
}