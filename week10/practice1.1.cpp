#include <iostream>

using namespace std;

class Food {
    string id;
    string name;
    double price;
    int quantity;

    void input() {
        cout << "Nhap ten: ";
        getline(cin, name);

        cout << "Nhap gia: ";
        cin >> price;

        quantity = 0;
    }

    void display() {
        cout << name << " - "
             << price << " (" << quantity << ")";
    }
};

int main() {
    Food f1;

    f1.id = "F001";       // Truy cap du lieu
    f1.name = "Burger";
    f1.price = 50000;
    f1.quantity = 10;

    f1.input();           // Goi ham
    f1.display();

    return 0;
}