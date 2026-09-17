#include <iostream>
#include <string>
using namespace std;

#define MAX 5

struct Book{
    int idBook;
    string nameBook;
    string author;

    void inputInfo(){
        cout << "Enter the id of the book: ";
        cin >> idBook;

        cin.ignore();

        cout << "Enter the name of the book: ";
        getline (cin, nameBook);

        cout << "Enter the author of the book : ";
        getline (cin, author);

        cout << endl;
    } 

    void outputInfo(){
        cout << "========================" << endl;
        cout << "   |   ID      :" << idBook << endl;
        cout << "   |   Name    :" << nameBook << endl;
        cout << "   |   Author  :" << author << endl;
        cout << "========================" << endl;

    }
};

struct Library{
    int idLibrary;
    string nameLibrary;
    int bookNumber;

    Book bookList[MAX];

    bool checkLibrary (int id, string name){
        return(id == 123 && name == "A5-103");
    }

    bool inputLibrary(){
        cout << "*************************" << endl;
        cout << "Enter the id of the library: ";
        cin >> idLibrary;

        cin.ignore();

        cout << "Enter the name of the library: ";
        getline (cin, nameLibrary);

        if (!checkLibrary(idLibrary, nameLibrary)){
            cout << "Sorry we don't have this library" << endl;
            return false;
        }

        cout << "Enter the number of the book: ";
        cin >> bookNumber;

        for (int i= 0; i < bookNumber; i++){
            bookList[i].inputInfo();
            }
        cout << "*************************" << endl;
        return true;
    }

    void outputLibrary(){
        cout << "<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
        cout << "ID of the library: " << idLibrary << endl;
        cout << "Name of the library: " << nameLibrary << endl;
        cout << "The number of books we currently have: " << bookNumber << endl;
        for (int i = 0; i < bookNumber; i++){
            bookList[i].outputInfo();
        }
    }

    void addBook (Book s){
        if (bookNumber < MAX){
            bookList[bookNumber] = s;
            bookNumber++;
            cout << " --> Add book successfully!" << endl;
        }
        else {
            cout << " --> Sorry there is no space left" << endl;
        }
    }

    // Get the book info directly when searching for ID
    void getBookInfo(int idSearch){
        for (int i = 0; i < bookNumber; i++){
            if (bookList[i].idBook == idSearch){
                cout << "===================" << endl;
                cout << " ==> Found the book with the ID: " << idSearch << endl;
                bookList[i].outputInfo();
                return;
            }
        }
        cout << "Sorry there is no ID: " << idSearch << " match with the book" << endl;
    }

    // Show the book info with the ID and return the whole struct
    Book showBookInfo (int idSearch){
        for (int i = 0; i < bookNumber; i++){
            if (bookList[i].idBook == idSearch){
                cout << "===================" << endl;
                cout << " ==> Found the book with the ID: " << idSearch << endl;
                bookList[i].outputInfo();
                return bookList[i];
            }
            else {
                cout << "Sorry there is no ID: " << idSearch << " match with the book" << endl;
            }
        }
        Book emptyBook;
        emptyBook.idBook = -1;
        emptyBook.nameBook = "N/A" ;
        emptyBook.author = "N/A";
        return emptyBook;
    }
};


int main(){
    Library oopLibrary;

    // Find the library
    cout << "=================================" << endl;
    cout << "========Welcome to the library========" << endl;
    cout << "=================================" << endl;
    if (oopLibrary.inputLibrary()){
        oopLibrary.outputLibrary();
    }

    // Get the book info directly when searching for ID
    int idSearch;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Enter the ID u wanna search (void): ";
    cin >> idSearch;

    oopLibrary.getBookInfo(idSearch);

    // Show the book info directly when searching for ID
    cout << "Enter the ID u wanna search (Struct): ";
    cin >> idSearch;

    Book s = oopLibrary.showBookInfo(idSearch);
    if (s.idBook != -1){
        cout << " --> Found the ID  :" << s.idBook << endl;
        cout << "   | Name          :" << s.nameBook << endl;
        cout << "   | Author        :" << s.author << endl;
    }
    else{
        cout << " --> The ID: " << idSearch << " does not exist" << endl;
    }
    return 0;
}

