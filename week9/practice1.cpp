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
// =====================================================
// 5. TIM MON AN THEO MA HOAC TEN
// =====================================================

void searchFood(const Restaurant &r) {
    if (r.foodCount == 0) {
        cout << "\nChua co mon an nao!\n";
        return;
    }

    string keyword;

    cin.ignore();

    cout << "\n===== TIM MON AN =====\n";
    cout << "Nhap ma hoac ten mon an: ";
    getline(cin, keyword);

    bool found = false;

    for (int i = 0; i < r.foodCount; i++) {

        if (r.foods[i].id == keyword ||
            r.foods[i].name == keyword) {

            cout << "\nTim thay mon an:\n";

            cout << "Ma mon: " << r.foods[i].id << endl;
            cout << "Ten mon: " << r.foods[i].name << endl;
            cout << "Don gia: " << r.foods[i].price << endl;
            cout << "So luong: " << r.foods[i].quantity << endl;

            found = true;
        }
    }

    if (!found) {
        cout << "\nKhong tim thay mon an!\n";
    }
}
// =====================================================
// 6. CAP NHAT GIA HOAC SO LUONG MON AN
// =====================================================

void updateFood(Restaurant &r) {
    if (r.foodCount == 0) {
        cout << "\nChua co mon an nao!\n";
        return;
    }

    string id;

    cin.ignore();

    cout << "\n===== CAP NHAT MON AN =====\n";
    cout << "Nhap ma mon can cap nhat: ";
    getline(cin, id);

    for (int i = 0; i < r.foodCount; i++) {

        if (r.foods[i].id == id) {

            cout << "\nMon an hien tai:\n";
            cout << "Ten: " << r.foods[i].name << endl;
            cout << "Gia: " << r.foods[i].price << endl;
            cout << "So luong: " << r.foods[i].quantity << endl;

            cout << "\nNhap gia moi: ";
            cin >> r.foods[i].price;

            cout << "Nhap so luong moi: ";
            cin >> r.foods[i].quantity;

            cout << "\nCap nhat thanh cong!\n";
            return;
        }
    }

    cout << "\nKhong tim thay mon an!\n";
}
// =====================================================
// 7. TIM MON AN + KIEM TRA SO LUONG
// =====================================================

int findFood(const Restaurant &r, string foodID) {

    for (int i = 0; i < r.foodCount; i++) {

        if (r.foods[i].id == foodID) {
            return i;
        }
    }

    return -1;
}
// =====================================================
// 8. TAO DON HANG MOI
// =====================================================

void createOrder(Restaurant &r) {

    if (r.orderCount >= 100) {
        cout << "\nDanh sach don hang da day!\n";
        return;
    }

    string foodID;
    int quantity;

    cin.ignore();

    cout << "\n================ TAO DON HANG ================\n";

    Order &o = r.orders[r.orderCount];

    cout << "Ma don hang: ";
    getline(cin, o.id);

    cout << "Ten khach hang: ";
    getline(cin, o.customerName);

    cout << "Dia chi giao hang: ";
    getline(cin, o.address);

    cout << "Nhap ma mon an: ";
    getline(cin, foodID);

    // Tim mon an
    int index = findFood(r, foodID);

    if (index == -1) {
        cout << "\nKhong tim thay mon an!\n";
        return;
    }

    cout << "Nhap so luong: ";
    cin >> quantity;

    // Kiem tra so luong
    if (quantity <= 0) {
        cout << "\nSo luong khong hop le!\n";
        return;
    }

    if (quantity > r.foods[index].quantity) {
        cout << "\nKhong du so luong mon an!\n";
        cout << "So luong hien co: "
             << r.foods[index].quantity << endl;
        return;
    }

    // Luu thong tin mon an vao Order
    o.food = r.foods[index];

    // Luu so luong dat
    o.quantity = quantity;

    // Trang thai mac dinh
    o.status = "Cho xu ly";

    // Tru so luong mon an
    r.foods[index].quantity -= quantity;

    r.orderCount++;

    cout << "\nTao don hang thanh cong!\n";
}
// =====================================================
// 9. TINH TONG TIEN CUA DON HANG
// =====================================================

double calculateOrderTotal(const Order &o) {

    return o.food.price * o.quantity;
}
