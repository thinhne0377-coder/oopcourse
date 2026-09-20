#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// =====================================================
// CONSTANT
// =====================================================
const int MAX_MOBILE = 100;
const int MAX_ORDER = 100;
const int MAX_ITEM = 20;

// =====================================================
// STRUCT MOBILE
// Thông tin điện thoại
// =====================================================
struct Mobile {
    string id;
    string brand;
    string version;
    string serial;
    int year;
    double price;
};

// =====================================================
// STRUCT ORDER
// Thông tin đơn hàng
// =====================================================
struct Order {
    string idOrder;
    string idCustomer;

    // Phuong thuc thanh toan:
    // true  = da thanh toan
    // false = chua thanh toan
    bool paymentMethod;

    string mobileItems[MAX_ITEM];
    int itemCount;

    string date; // dd/mm/yyyy
};

// =====================================================
// STRUCT SHOP
// Shop co it nhat 2 mang: mobiles va orders
// =====================================================
struct Shop {
    string shopName;
    string address;
    string phone;

    Mobile mobiles[MAX_MOBILE];
    int mobileCount;

    Order orders[MAX_ORDER];
    int orderCount;
};

// =====================================================
// NHAP THONG TIN SHOP
// =====================================================
void inputShop(Shop& shop) {
    cout << "\n========== NHAP THONG TIN SHOP ==========\n";

    cout << "Ten shop: ";
    getline(cin, shop.shopName);

    cout << "Dia chi: ";
    getline(cin, shop.address);

    cout << "So dien thoai shop: ";
    getline(cin, shop.phone);

    shop.mobileCount = 0;
    shop.orderCount = 0;
}

// =====================================================
// HIEN THI 1 MOBILE
// =====================================================
void outputMobile(const Mobile& mobile) {
    cout << left
         << setw(10) << mobile.id
         << setw(15) << mobile.brand
         << setw(20) << mobile.version
         << setw(15) << mobile.serial
         << setw(8) << mobile.year
         << setw(12) << fixed << setprecision(0) << mobile.price
         << endl;
}

// =====================================================
// HIEN THI DANH SACH MOBILE
// =====================================================
void showMobiles(const Shop& shop) {
    if (shop.mobileCount == 0) {
        cout << "\nShop chua co dien thoai!\n";
        return;
    }

    cout << "\n================ DANH SACH DIEN THOAI ================\n";

    cout << left
         << setw(10) << "ID"
         << setw(15) << "Brand"
         << setw(20) << "Version"
         << setw(15) << "Serial"
         << setw(8) << "Year"
         << setw(12) << "Price"
         << endl;

    cout << string(80, '-') << endl;

    for (int i = 0; i < shop.mobileCount; i++) {
        outputMobile(shop.mobiles[i]);
    }
}

// =====================================================
// TIM MOBILE THEO ID
// =====================================================
int findMobile(const Shop& shop, const string& id) {
    for (int i = 0; i < shop.mobileCount; i++) {
        if (shop.mobiles[i].id == id) {
            return i;
        }
    }

    return -1;
}

// =====================================================
// 1. THEM MOI DIEN THOAI
// =====================================================
void addMobile(Shop& shop) {
    if (shop.mobileCount >= MAX_MOBILE) {
        cout << "\nDanh sach dien thoai da day!\n";
        return;
    }

    Mobile& mobile = shop.mobiles[shop.mobileCount];

    cout << "\n========== THEM DIEN THOAI ==========\n";

    cout << "Nhap ID: ";
    getline(cin, mobile.id);

    // Kiem tra ID trung
    if (findMobile(shop, mobile.id) != -1) {
        cout << "ID dien thoai da ton tai!\n";
        return;
    }

    cout << "Nhap brand: ";
    getline(cin, mobile.brand);

    cout << "Nhap version: ";
    getline(cin, mobile.version);

    cout << "Nhap serial: ";
    getline(cin, mobile.serial);

    cout << "Nhap nam san xuat: ";
    cin >> mobile.year;

    cout << "Nhap gia: ";
    cin >> mobile.price;

    cin.ignore();

    shop.mobileCount++;

    cout << "\nThem dien thoai thanh cong!\n";
}

// =====================================================
// 2. XOA DIEN THOAI
// =====================================================
void deleteMobile(Shop& shop) {
    if (shop.mobileCount == 0) {
        cout << "\nKhong co dien thoai de xoa!\n";
        return;
    }

    string id;

    cout << "\n========== XOA DIEN THOAI ==========\n";
    cout << "Nhap ID dien thoai can xoa: ";
    getline(cin, id);

    int pos = findMobile(shop, id);

    if (pos == -1) {
        cout << "Khong tim thay dien thoai!\n";
        return;
    }

    // Dich cac phan tu phia sau len 1 vi tri
    for (int i = pos; i < shop.mobileCount - 1; i++) {
        shop.mobiles[i] = shop.mobiles[i + 1];
    }

    shop.mobileCount--;

    cout << "Xoa dien thoai thanh cong!\n";
}

// =====================================================
// NHAP 1 ORDER
// =====================================================
void inputOrder(Shop& shop, Order& order) {
    cout << "\n========== TAO ORDER ==========\n";

    cout << "Nhap ID order: ";
    getline(cin, order.idOrder);

    cout << "Nhap ID customer: ";
    getline(cin, order.idCustomer);

    cout << "Da thanh toan? (1: Co / 0: Chua): ";
    cin >> order.paymentMethod;

    cin.ignore();

    cout << "Nhap ngay dat hang (dd/mm/yyyy): ";
    getline(cin, order.date);

    cout << "Nhap so luong dien thoai trong order: ";
    cin >> order.itemCount;

    while (order.itemCount < 1 || order.itemCount > MAX_ITEM) {
        cout << "So luong khong hop le! Nhap lai: ";
        cin >> order.itemCount;
    }

    cin.ignore();

    for (int i = 0; i < order.itemCount; i++) {
        cout << "Nhap ID dien thoai thu " << i + 1 << ": ";
        getline(cin, order.mobileItems[i]);

        // Kiem tra dien thoai co ton tai khong
        while (findMobile(shop, order.mobileItems[i]) == -1) {
            cout << "Khong tim thay dien thoai!\n";
            cout << "Nhap lai ID dien thoai: ";
            getline(cin, order.mobileItems[i]);
        }
    }
}

// =====================================================
// 3. TAO MOI ORDER
// =====================================================
void addOrder(Shop& shop) {
    if (shop.orderCount >= MAX_ORDER) {
        cout << "\nDanh sach order da day!\n";
        return;
    }

    Order& order = shop.orders[shop.orderCount];

    inputOrder(shop, order);

    shop.orderCount++;

    cout << "\nTao order thanh cong!\n";
}

// =====================================================
// HIEN THI 1 ORDER
// =====================================================
void outputOrder(const Shop& shop, const Order& order) {
    cout << "\n----------------------------------------\n";
    cout << "ID Order       : " << order.idOrder << endl;
    cout << "ID Customer    : " << order.idCustomer << endl;

    cout << "Thanh toan     : ";

    if (order.paymentMethod) {
        cout << "Da thanh toan";
    } else {
        cout << "Chua thanh toan";
    }

    cout << endl;

    cout << "Ngay dat       : " << order.date << endl;

    cout << "Danh sach dien thoai:\n";

    for (int i = 0; i < order.itemCount; i++) {
        int pos = findMobile(shop, order.mobileItems[i]);

        if (pos != -1) {
            cout << "  - "
                 << shop.mobiles[pos].id
                 << " | "
                 << shop.mobiles[pos].brand
                 << " | "
                 << shop.mobiles[pos].version
                 << " | "
                 << shop.mobiles[pos].price
                 << endl;
        } else {
            cout << "  - " << order.mobileItems[i] << endl;
        }
    }
}

// =====================================================
// HIEN THI TAT CA ORDER
// =====================================================
void showOrders(const Shop& shop) {
    if (shop.orderCount == 0) {
        cout << "\nChua co order nao!\n";
        return;
    }

    cout << "\n================ DANH SACH ORDER ================\n";

    for (int i = 0; i < shop.orderCount; i++) {
        outputOrder(shop, shop.orders[i]);
    }
}

// =====================================================
// TIM ORDER THEO ID
// =====================================================
int findOrder(const Shop& shop, const string& idOrder) {
    for (int i = 0; i < shop.orderCount; i++) {
        if (shop.orders[i].idOrder == idOrder) {
            return i;
        }
    }

    return -1;
}

// =====================================================
// 4. CHINH SUA ORDER
// =====================================================
void editOrder(Shop& shop) {
    if (shop.orderCount == 0) {
        cout << "\nChua co order de chinh sua!\n";
        return;
    }

    string idOrder;

    cout << "\n========== CHINH SUA ORDER ==========\n";
    cout << "Nhap ID order can sua: ";
    getline(cin, idOrder);

    int pos = findOrder(shop, idOrder);

    if (pos == -1) {
        cout << "Khong tim thay order!\n";
        return;
    }

    cout << "\nThong tin order hien tai:";
    outputOrder(shop, shop.orders[pos]);

    cout << "\nNhap lai thong tin order:\n";

    // Giữ nguyên ID order
    cout << "Nhap ID customer moi: ";
    getline(cin, shop.orders[pos].idCustomer);

    cout << "Da thanh toan? (1: Co / 0: Chua): ";
    cin >> shop.orders[pos].paymentMethod;

    cin.ignore();

    cout << "Nhap ngay dat hang moi (dd/mm/yyyy): ";
    getline(cin, shop.orders[pos].date);

    cout << "Nhap so luong dien thoai: ";
    cin >> shop.orders[pos].itemCount;

    while (shop.orders[pos].itemCount < 1 ||
           shop.orders[pos].itemCount > MAX_ITEM) {

        cout << "So luong khong hop le! Nhap lai: ";
        cin >> shop.orders[pos].itemCount;
    }

    cin.ignore();

    for (int i = 0; i < shop.orders[pos].itemCount; i++) {

        cout << "Nhap ID dien thoai thu "
             << i + 1 << ": ";

        getline(cin, shop.orders[pos].mobileItems[i]);

        while (findMobile(shop, shop.orders[pos].mobileItems[i]) == -1) {

            cout << "Khong tim thay dien thoai!\n";
            cout << "Nhap lai ID: ";

            getline(cin, shop.orders[pos].mobileItems[i]);
        }
    }

    cout << "\nChinh sua order thanh cong!\n";
}

// =====================================================
// LAY THANG TU CHUOI DATE
// Vi du: 15/09/2026 -> 9
// =====================================================
int getMonth(const string& date) {
    if (date.length() < 5) {
        return -1;
    }

    if (date[2] != '/') {
        return -1;
    }

    int month =
        (date[3] - '0') * 10 +
        (date[4] - '0');

    return month;
}

// =====================================================
// 5. THONG KE ORDER THEO THANG
// =====================================================
void statisticsByMonth(const Shop& shop) {
    if (shop.orderCount == 0) {
        cout << "\nChua co order!\n";
        return;
    }

    int month;

    cout << "\n========== THONG KE ORDER THEO THANG ==========\n";

    cout << "Nhap thang can thong ke (1 - 12): ";
    cin >> month;

    while (month < 1 || month > 12) {
        cout << "Thang khong hop le! Nhap lai: ";
        cin >> month;
    }

    int count = 0;

    cout << "\nCac order trong thang " << month << ":\n";

    for (int i = 0; i < shop.orderCount; i++) {

        int orderMonth = getMonth(shop.orders[i].date);

        if (orderMonth == month) {
            outputOrder(shop, shop.orders[i]);
            count++;
        }
    }

    cout << "\nTong so order trong thang "
         << month << ": "
         << count << endl;
}

// =====================================================
// MENU
// =====================================================
void menu() {
    cout << "\n\n============================================\n";
    cout << "       QUAN LY SHOP BAN DIEN THOAI\n";
    cout << "============================================\n";

    cout << "1. Them moi dien thoai\n";
    cout << "2. Xoa dien thoai\n";
    cout << "3. Tao moi order\n";
    cout << "4. Chinh sua order\n";
    cout << "5. Thong ke order theo thang\n";
    cout << "6. Hien thi danh sach dien thoai\n";
    cout << "7. Hien thi danh sach order\n";
    cout << "0. Thoat\n";

    cout << "============================================\n";
    cout << "Nhap lua chon: ";
}

// =====================================================
// MAIN
// =====================================================
int main() {

    Shop shop;

    // Nhap thong tin chung cua shop
    inputShop(shop);

    int choice;

    do {
        menu();
        cin >> choice;
        cin.ignore();

        switch (choice) {

            case 1:
                // 1. Them moi dien thoai
                addMobile(shop);
                break;

            case 2:
                // 2. Xoa dien thoai
                deleteMobile(shop);
                break;

            case 3:
                // 3. Tao moi order
                addOrder(shop);
                break;

            case 4:
                // 4. Chinh sua order
                editOrder(shop);
                break;

            case 5:
                // 5. Thong ke order theo thang
                statisticsByMonth(shop);
                break;

            case 6:
                showMobiles(shop);
                break;

            case 7:
                showOrders(shop);
                break;

            case 0:
                cout << "\nKet thuc chuong trinh!\n";
                break;

            default:
                cout << "\nLua chon khong hop le!\n";
        }

    } while (choice != 0);

    return 0;
}