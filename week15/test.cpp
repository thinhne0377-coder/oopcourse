#include <iostream>
#include <string>
using namespace std;

// ================= CLASS ROOM =================
class Room {
protected:
    string roomId;
    double price;
    int adults;
    int children;

public:
    // Constructor mac dinh
    Room() {
        roomId = "";
        price = 0;
        adults = 0;
        children = 0;
    }

    // Constructor co tham so
    Room(string id, double p, int a, int c) {
        roomId = id;
        price = p;
        adults = a;
        children = c;
    }

    // Setter
    void setRoomId(string id) {
        roomId = id;
    }

    void setPrice(double p) {
        price = p;
    }

    void setAdults(int a) {
        adults = a;
    }

    void setChildren(int c) {
        children = c;
    }

    // Getter
    string getRoomId() const {
        return roomId;
    }

    double getPrice() const {
        return price;
    }

    int getAdults() const {
        return adults;
    }

    int getChildren() const {
        return children;
    }

    // Ham ao
    virtual void displayInfo() const = 0;

    virtual ~Room() {}
};

// ================= STANDARD ROOM =================
class StandardRoom : public Room {
public:
    StandardRoom() : Room() {}

    StandardRoom(string id, double p, int a, int c)
        : Room(id, p, a, c) {}

    void displayInfo() const override {
        cout << "\nLoai phong: Standard Room\n";
        cout << "Ma phong: " << roomId << endl;
        cout << "Gia phong: " << price << endl;
        cout << "Nguoi lon: " << adults << endl;
        cout << "Tre em: " << children << endl;
        cout << "Dac diem: 2 nguoi lon, 1 tre em theo mo ta mau.\n";
    }
};

// ================= DELUXE ROOM =================
class DeluxeRoom : public Room {
public:
    DeluxeRoom() : Room() {}

    DeluxeRoom(string id, double p, int a, int c)
        : Room(id, p, a, c) {}

    void displayInfo() const override {
        cout << "\nLoai phong: Deluxe Room\n";
        cout << "Ma phong: " << roomId << endl;
        cout << "Gia phong: " << price << endl;
        cout << "Nguoi lon: " << adults << endl;
        cout << "Tre em: " << children << endl;
        cout << "Dac diem: 2 nguoi lon, 1 tre em theo mo ta mau.\n";
    }
};

// ================= LUXURY ROOM =================
class LuxuryRoom : public Room {
public:
    LuxuryRoom() : Room() {}

    LuxuryRoom(string id, double p, int a, int c)
        : Room(id, p, a, c) {}

    void displayInfo() const override {
        cout << "\nLoai phong: Luxury Room\n";
        cout << "Ma phong: " << roomId << endl;
        cout << "Gia phong: " << price << endl;
        cout << "Nguoi lon: " << adults << endl;
        cout << "Tre em: " << children << endl;
        cout << "Dac diem: Lua chon bo tri giuong cao cap.\n";
    }
};

// ================= HAM MAIN =================
int main() {
    const int N = 3;

    Room* rooms[N];

    string id;
    double price;
    int adults, children;
    int choice;

    for (int i = 0; i < N; i++) {
        cout << "\n===== NHAP THONG TIN PHONG " 
             << i + 1 << " =====\n";

        cout << "Nhap ma phong: ";
        cin >> id;

        cout << "Nhap gia phong: ";
        cin >> price;

        cout << "Nhap so nguoi lon: ";
        cin >> adults;

        cout << "Nhap so tre em: ";
        cin >> children;

        cout << "Chon loai phong:\n";
        cout << "1. Standard Room\n";
        cout << "2. Deluxe Room\n";
        cout << "3. Luxury Room\n";
        cout << "Lua chon: ";
        cin >> choice;

        if (choice == 1) {
            rooms[i] = new StandardRoom(
                id, price, adults, children
            );
        } else if (choice == 2) {
            rooms[i] = new DeluxeRoom(
                id, price, adults, children
            );
        } else {
            rooms[i] = new LuxuryRoom(
                id, price, adults, children
            );
        }
    }

    // Hien thi thong tin bang da hinh
    cout << "\n========== DANH SACH PHONG ==========\n";

    int totalAdults = 0;
    int totalChildren = 0;

    for (int i = 0; i < N; i++) {
        rooms[i]->displayInfo();

        totalAdults += rooms[i]->getAdults();
        totalChildren += rooms[i]->getChildren();
    }

    cout << "\n========== THONG KE ==========\n";
    cout << "Tong so phong: " << N << endl;
    cout << "Tong nguoi lon: " << totalAdults << endl;
    cout << "Tong tre em: " << totalChildren << endl;
    cout << "Tong so khach: "
         << totalAdults + totalChildren << endl;

    // Giai phong bo nho
    for (int i = 0; i < N; i++) {
        delete rooms[i];
    }

    return 0;
}
```