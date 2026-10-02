#include <iostream>
#include <string>

using namespace std;

class Food {
private:
    string name;
    double price;
    int quantity;

public:
    // =========================
    // Constructor
    // =========================
    Food(string n, double p, int q) {
        name = n;
        price = p;
        quantity = q;
    }

    // =========================
    // Getter
    // =========================
    string getName() {
        return name;
    }

    double getPrice() {
        return price;
    }

    int getQuantity() {
        return quantity;
    }

    // =========================
    // Setter
    // =========================
    void setName(string n) {
        if (n != "")
            name = n;
    }

    void setPrice(double p) {
        if (p > 0)
            price = p;
    }

    void setQuantity(int q) {
        if (q >= 0)
            quantity = q;
    }

    // =========================
    // Hiển thị thông tin
    // =========================
    void display() {
        cout << "Ten mon an: " << name << endl;
        cout << "Gia: " << price << endl;
        cout << "So luong: " << quantity << endl;
    }
};

int main() {

    // =================================
    // Tao doi tuong Food
    // =================================
    Food f("Burger", 50000, 2);

    cout << "===== THONG TIN BAN DAU =====" << endl;
    f.display();

    // =================================
    // Su dung Getter
    // =================================
    cout << "\n===== SU DUNG GETTER =====" << endl;

    cout << "Ten mon an: " << f.getName() << endl;
    cout << "Gia: " << f.getPrice() << endl;
    cout << "So luong: " << f.getQuantity() << endl;

    // =================================
    // Su dung Setter
    // =================================
    cout << "\n===== CAP NHAT THONG TIN =====" << endl;

    f.setName("Pizza");
    f.setPrice(60000);
    f.setQuantity(5);

    f.display();

    // =================================
    // Kiem tra Setter
    // =================================
    cout << "\n===== KIEM TRA GIA TRI KHONG HOP LE =====" << endl;

    f.setPrice(-10000);
    f.setQuantity(-5);

    cout << "Gia sau khi nhap -10000: "
         << f.getPrice() << endl;

    cout << "So luong sau khi nhap -5: "
         << f.getQuantity() << endl;

    return 0;
}