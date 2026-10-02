#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Food {
private:
    int id;
    string name;
    double price;
    int quantity;

public:
    // Nhập thông tin món ăn
    void input() {
        cout << "Nhap ID: ";
        cin >> id;
        cin.ignore();
        cout << "Nhap ten mon: ";
        getline(cin, name);
        cout << "Nhap gia: ";
        cin >> price;
        cout << "Nhap so luong: ";
        cin >> quantity;
    }

    // Hiển thị thông tin món ăn
    void display() {
        cout << "ID: " << id
             << " | Ten: " << name
             << " | Gia: " << price
             << " | So luong: " << quantity << endl;
    }

    // Getter
    double getPrice() { return price; }
    int getQuantity() { return quantity; }
    string getName() { return name; }
    int getId() { return id; }

    // Setter
    void setPrice(double p) {
        if (p > 0) price = p;
    }
    void setQuantity(int q) {
        if (q >= 0) quantity = q;
    }

    // Kiểm tra còn hàng
    bool isAvailable() {
        return quantity > 0;
    }
};

int main() {
    vector<Food> menu;
    int choice;

    do {
        cout << "\n===== MENU QUAN LY MON AN =====\n";
        cout << "1. Nhap danh sach mon an\n";
        cout << "2. Hien thi danh sach mon an\n";
        cout << "3. Tim mon an theo ID\n";
        cout << "4. Tim mon an theo ten\n";
        cout << "5. Cap nhat gia mon an\n";
        cout << "6. Cap nhat so luong mon an\n";
        cout << "7. Kiem tra mon an con hang\n";
        cout << "8. Thoat\n";
        cout << "Chon chuc nang: ";
        cin >> choice;

        if (choice == 1) {
            Food f;
            f.input();
            menu.push_back(f);
        }
        else if (choice == 2) {
            for (auto &f : menu) f.display();
        }
        else if (choice == 3) {
            int id;
            cout << "Nhap ID can tim: ";
            cin >> id;
            for (auto &f : menu)
                if (f.getId() == id) f.display();
        }
        else if (choice == 4) {
            string ten;
            cout << "Nhap ten can tim: ";
            cin.ignore();
            getline(cin, ten);
            for (auto &f : menu)
                if (f.getName() == ten) f.display();
        }
        else if (choice == 5) {
            int id;
            double newPrice;
            cout << "Nhap ID mon an: ";
            cin >> id;
            cout << "Nhap gia moi: ";
            cin >> newPrice;
            for (auto &f : menu)
                if (f.getId() == id) f.setPrice(newPrice);
        }
        else if (choice == 6) {
            int id, newQty;
            cout << "Nhap ID mon an: ";
            cin >> id;
            cout << "Nhap so luong moi: ";
            cin >> newQty;
            for (auto &f : menu)
                if (f.getId() == id) f.setQuantity(newQty);
        }
        else if (choice == 7) {
            int id;
            cout << "Nhap ID mon an: ";
cin >> id;
            for (auto &f : menu)
                if (f.getId() == id)
                    cout << (f.isAvailable() ? "Con hang!\n" : "Het hang!\n");
        }
    } while (choice != 8);

    return 0;
}
