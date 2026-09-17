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
        cout << name << " ";
        cout << id << " ";
        cout << author << endl;
    }
};

int main() {
    Book book;

    book.inputInfo();
    book.outputInfo();

    return 0;
}