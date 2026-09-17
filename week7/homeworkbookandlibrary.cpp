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

    void inputLibrary(){
        cout << "*************************" << endl;
        cout << "Enter the id of the library: ";
        cin >> idLibrary;
        
        cin.ignore();

        cout << "Enter the name of the library: ";
        getline (cin, nameLibrary);

        cout << "Enter the number of the book: ";
        cin >> bookNumber;

        for (int i= 0; i < bookNumber; i++){
            bookList[i].inputInfo();
        }
        cout << "*************************" << endl;
    }

    void outputLibrary(){
        cout << "<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
        cout << "ID of the library: " << idLibrary << endl;
        cout << "Name of the library: " << nameLibrary << endl;
        cout << "The number of books we currently have: " << bookNumber << endl;
        for (int i = 0; i < bookNumber; i++){
            bookList[i].outputInfo();
        }
        cout << "<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
    }

    bool checkLibrary (){
        if (idLibrary == 123 && nameLibrary == "A5-103"){
            cout << "======================" << endl;
            cout << "Welcome to the library" << endl;
            cout << "======================" << endl;
            return true;
        }
        else {
            cout << "Sorry we don't have this library" << endl;
            return false;
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
            else {
                cout << "Sorry there is no ID: " << idSearch << " match with the book" << endl;
            }
        }
    }

    // Get the book info with the ID and return the whole struct
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
        emptyBook.nameBook == "N/A" ;
        emptyBook.author == "N/A";
        return emptyBook;
    }
};


int main(){
    cout << "Hello World" << endl;
    
    return 0;
}