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