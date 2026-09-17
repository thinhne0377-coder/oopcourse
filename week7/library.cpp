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
        cout << idLibrary << endl;
        cout << nameLibrary << endl;
        cout << numBooks << endl;

        for (int i = 0; i < numBooks; i++) {
            cout << books[i].id << endl;
            cout << books[i].name << endl;
            cout << books[i].author << endl;
        }
    }

    void addBook(Book a) {
        books[numBooks] = a;
        numBooks++;
    }

    void getBookInfo(int idBook) {
        for (int i = 0; i < numBooks; i++) {
            if (books[i].id == idBook) {
                cout << books[i].id << endl;
                cout << books[i].name << endl;
                cout << books[i].author << endl;
                return;
            }
        }

        cout << "Khong tim thay Book!" << endl;
    }

    Book getBook(int idBook) {
        for (int i = 0; i < numBooks; i++) {
            if (books[i].id == idBook) {
                return books[i];
            }
        }

        // Neu khong tim thay
        Book book;
        book.id = -1;
        return book;
    }

    void getBooks() {
        for (int i = 0; i < numBooks; i++) {
            cout << books[i].id << " ";
            cout << books[i].name << " ";
            cout << books[i].author << endl;
        }
    }
};