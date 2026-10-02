#include <iostream>
#include <string>

using namespace std;

class Food {
public:
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
        cin.ignore();
    }

    void display() {
        cout << name << " - "
             << price << " (" << quantity << ")" << endl;
    }
};

int main() {
    Food foods[3];

    // ==========================================
    // 1. Tao 3 mon an va nhap thong tin
    // ==========================================
    for (int i = 0; i < 3; i++) {
        foods[i].input();
    }

    // ==========================================
    // 2. In thong tin cac mon an
    // ==========================================
    cout << "\n=== Danh sach mon an ===" << endl;

    for (int i = 0; i < 3; i++) {
        foods[i].display();
    }

    // ==========================================
    // 3. Tim mon an theo ten
    // ==========================================
    string nameSearch;

    cout << "\nNhap ten mon an can tim: ";
    getline(cin, nameSearch);

    bool found = false;

    for (int i = 0; i < 3; i++) {
        if (foods[i].name == nameSearch) {
            cout << "\nTim thay mon an:" << endl;
            foods[i].display();

            // ==================================
            // 4. Cap nhat gia cua mon an
            // ==================================
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

    // ==========================================
    // 5. Hien thi lai danh sach mon an
    // ==========================================
    cout << "\n=== Danh sach mon an sau khi cap nhat ==="
         << endl;

    for (int i = 0; i < 3; i++) {
        foods[i].display();
    }

    return 0;
}