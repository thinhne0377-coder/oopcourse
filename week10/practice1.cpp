#include <iostream>
#include <string>

using namespace std;

class Food {
public:
    string id;
    string name;
    double price;
    int quantity;

    // Nhap thong tin mon an
    void input() {
        cout << "Nhap ten: ";
        getline(cin, name);

        cout << "Nhap gia: ";
        cin >> price;

        quantity = 0;

        cin.ignore();
    }

    // Hien thi thong tin mon an
    void display() {
        cout << name << " - " << price
             << " (" << quantity << ")" << endl;
    }
};

int main() {
    Food foods[3];

    // Tao 3 mon an
    cout << "=== NHAP THONG TIN 3 MON AN ===" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "\nMon an thu " << i + 1 << ":" << endl;
        foods[i].input();
    }

    // In danh sach mon an
    cout << "\n=== DANH SACH MON AN ===" << endl;

    for (int i = 0; i < 3; i++) {
        foods[i].display();
    }

    // Tim mon an theo ten
    string searchName;

    cout << "\nNhap ten mon an can tim: ";
    getline(cin, searchName);

    bool found = false;

    for (int i = 0; i < 3; i++) {
        if (foods[i].name == searchName) {
            cout << "\nTim thay mon an:" << endl;
            foods[i].display();

            // Cap nhat gia
            double newPrice;
            cout << "Nhap gia moi: ";
            cin >> newPrice;

            foods[i].price = newPrice;

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Khong tim thay mon an!" << endl;
    }

    // Hien thi lai danh sach
    cout << "\n=== DANH SACH MON AN SAU KHI CAP NHAT ===" << endl;

    for (int i = 0; i < 3; i++) {
        foods[i].display();
    }

    return 0;
}