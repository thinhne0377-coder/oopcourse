#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// =====================================================
// 1. KHAI BAO STRUCT
// =====================================================

struct Food {
    string id;          // Ma mon
    string name;        // Ten mon
    double price;       // Don gia
    int quantity;       // So luong con lai
};

struct Order {
    string id;          // Ma don hang
    string customerName;// Ten khach hang
    string address;     // Dia chi giao hang
    Food food;          // Mon an duoc dat
    int quantity;       // So luong dat
    string status;      // Trang thai
};

struct Restaurant {
    string name;        // Ten cua hang
    string address;     // Dia chi
    string phone;       // So dien thoai

    Food foods[100];    // Danh sach mon an
    int foodCount;

    Order orders[100];  // Danh sach don hang
    int orderCount;
};
// =====================================================
// 2. NHAP THONG TIN CUA HANG
// =====================================================

void inputRestaurant(Restaurant &r) {
    cin.ignore();

    cout << "\n===== NHAP THONG TIN CUA HANG =====\n";

    cout << "Ten cua hang: ";
    getline(cin, r.name);

    cout << "Dia chi: ";
    getline(cin, r.address);

    cout << "So dien thoai: ";
    getline(cin, r.phone);

    r.foodCount = 0;
    r.orderCount = 0;

    cout << "\nNhap thong tin cua hang thanh cong!\n";
}
// =====================================================
// 3. THEM MON AN MOI
// =====================================================

void addFood(Restaurant &r) {
    if (r.foodCount >= 100) {
        cout << "\nDanh sach mon an da day!\n";
        return;
    }

    Food &f = r.foods[r.foodCount];

    cin.ignore();

    cout << "\n===== THEM MON AN =====\n";

    cout << "Ma mon: ";
    getline(cin, f.id);

    cout << "Ten mon: ";
    getline(cin, f.name);

    cout << "Don gia: ";
    cin >> f.price;

    cout << "So luong con lai: ";
    cin >> f.quantity;

    r.foodCount++;

    cout << "\nThem mon an thanh cong!\n";
}
// =====================================================
// 4. HIEN THI DANH SACH MON AN
// =====================================================

void displayFoods(const Restaurant &r) {
    if (r.foodCount == 0) {
        cout << "\nChua co mon an nao!\n";
        return;
    }

    cout << "\n================ DANH SACH MON AN ================\n";

    cout << left
         << setw(10) << "Ma mon"
         << setw(25) << "Ten mon"
         << setw(15) << "Don gia"
         << setw(15) << "So luong"
         << endl;

    cout << string(65, '-') << endl;

    for (int i = 0; i < r.foodCount; i++) {
        cout << left
             << setw(10) << r.foods[i].id
             << setw(25) << r.foods[i].name
             << setw(15) << fixed << setprecision(2)
             << r.foods[i].price
             << setw(15) << r.foods[i].quantity
             << endl;
    }
}
