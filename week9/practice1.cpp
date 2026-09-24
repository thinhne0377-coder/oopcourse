#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// =====================================================
// STRUCT FOOD - THONG TIN MON AN
// =====================================================
struct Food {
    string id;
    string name;
    double price;
    int quantity;
};

// =====================================================
// STRUCT ORDER - THONG TIN DON HANG
// =====================================================
struct Order {
    string id;
    string customerName;
    string phone;
    string address;
    string foodName;
    int quantity;
    string status;
};

// =====================================================
// CHUYEN CHUOI VE CHU THUONG
// =====================================================
string toLower(string s) {
    for (int i = 0; i < (int)s.length(); i++) {
        s[i] = tolower((unsigned char)s[i]);
    }

    return s;
}

// =====================================================
// XOA KHOANG TRANG DAU VA CUOI
// =====================================================
string trim(string s) {

    int start = 0;
    int end = (int)s.length() - 1;

    while (start <= end && s[start] == ' ') {
        start++;
    }

    while (end >= start && s[end] == ' ') {
        end--;
    }

    if (start > end) {
        return "";
    }

    return s.substr(start, end - start + 1);
}

// =====================================================
// CHUAN HOA TEN MON AN
// - XOA KHOANG TRANG DAU/CUOI
// - XOA KHOANG TRANG THUA GIUA CAC TU
// - VIET HOA CHU CAI DAU MOI TU
// =====================================================
string normalizeFoodName(string s) {

    s = trim(s);

    string result = "";
    bool newWord = true;

    for (int i = 0; i < (int)s.length(); i++) {

        if (s[i] == ' ') {

            if (!result.empty() && result[result.length() - 1] != ' ') {
                result += ' ';
            }

            newWord = true;
        }
        else {

            if (newWord) {
                result += toupper((unsigned char)s[i]);
                newWord = false;
            }
            else {
                result += tolower((unsigned char)s[i]);
            }
        }
    }

    // Xoa khoang trang cuoi neu co
    if (!result.empty() && result[result.length() - 1] == ' ') {
        result.erase(result.length() - 1);
    }

    return result;
}

// =====================================================
// 1. NHAP VA HIEN THI TEN CUA HANG
// =====================================================
void step1() {

    string restaurantName;

    cout << "\n===== BUOC 1: NHAP VA HIEN THI TEN CUA HANG =====\n";

    cout << "Nhap ten cua hang: ";
    getline(cin, restaurantName);

    cout << "Chao mung den voi ["
         << restaurantName
         << "]!"
         << endl;
}

// =====================================================
// 2. CHUAN HOA TEN MON AN
// =====================================================
string step2() {

    string foodName;

    cout << "\n===== BUOC 2: CHUAN HOA TEN MON AN =====\n";

    cout << "Nhap ten mon an: ";
    getline(cin, foodName);

    string result = normalizeFoodName(foodName);

    cout << "Ten mon sau khi chuan hoa: "
         << result
         << endl;

    return result;
}

// =====================================================
// 3. TAO MA DON HANG
// - NHAP TEN KHACH HANG
// - NHAP SO DIEN THOAI
// - TAO MA DON HANG
// =====================================================
string step3() {

    string customerName;
    string phone;

    cout << "\n===== BUOC 3: TAO MA DON HANG =====\n";

    cout << "Nhap ten khach hang: ";
    getline(cin, customerName);

    cout << "Nhap so dien thoai: ";
    getline(cin, phone);

    customerName = trim(customerName);

    // Lay tu dau tien cua ten khach hang
    string firstPart = "";

    for (int i = 0; i < (int)customerName.length(); i++) {

        if (customerName[i] != ' ') {
            firstPart += customerName[i];
        }
        else {
            break;
        }
    }

    // Lay 4 so cuoi cua so dien thoai
    string phonePart;

    if (phone.length() >= 4) {
        phonePart = phone.substr(phone.length() - 4);
    }
    else {
        phonePart = phone;
    }

    string orderId = "DH_" + firstPart + "_" + phonePart;

    cout << "Ma don hang: "
         << orderId
         << endl;

    return orderId;
}

// =====================================================
// 4. KIEM TRA MON AN
// - NHAP TEN MON
// - KIEM TRA TRONG DANH SACH MON AN
// =====================================================
void step4(Food foods[], int foodCount) {

    string foodName;

    cout << "\n===== BUOC 4: KIEM TRA MON AN =====\n";

    cout << "Nhap ten mon an can kiem tra: ";
    getline(cin, foodName);

    foodName = normalizeFoodName(foodName);

    bool found = false;

    for (int i = 0; i < foodCount; i++) {

        if (toLower(foods[i].name) == toLower(foodName)) {

            cout << "Mon an co ton tai trong danh sach!\n";
            cout << "Ma mon: " << foods[i].id << endl;
            cout << "Ten mon: " << foods[i].name << endl;
            cout << "Gia: " << foods[i].price << endl;
            cout << "So luong: " << foods[i].quantity << endl;

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Mon an khong ton tai trong danh sach!\n";
    }
}

// =====================================================
// 6. THAY DOI TRANG THAI DON HANG
// =====================================================
void step6(Order orders[], int orderCount) {

    string orderId;
    string newStatus;

    cout << "\n===== BUOC 6: THAY DOI TRANG THAI DON HANG =====\n";

    cout << "Nhap ma don hang: ";
    getline(cin, orderId);

    cout << "Nhap trang thai moi: ";
    getline(cin, newStatus);

    bool found = false;

    for (int i = 0; i < orderCount; i++) {

        if (toLower(orders[i].id) == toLower(orderId)) {

            orders[i].status = newStatus;

            cout << "Cap nhat trang thai thanh cong!\n";
            cout << "Ma don hang: "
                 << orders[i].id
                 << endl;

            cout << "Trang thai moi: "
                 << orders[i].status
                 << endl;

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Khong tim thay don hang!\n";
    }
}

// =====================================================
// 7. TIM CAC DON HANG THEO TEN KHACH HANG
// - KHONG PHAN BIET HOA/THUONG
// - TIM THEO TU KHOA
// =====================================================
void step7(Order orders[], int orderCount) {

    string keyword;

    cout << "\n===== BUOC 7: TIM DON HANG THEO TEN KHACH HANG =====\n";

    cout << "Nhap tu khoa ten khach hang: ";
    getline(cin, keyword);

    keyword = toLower(keyword);

    bool found = false;

    for (int i = 0; i < orderCount; i++) {

        string customer = toLower(orders[i].customerName);

        if (customer.find(keyword) != string::npos) {

            cout << "\nDon hang tim thay:\n";

            cout << "Ma don hang: "
                 << orders[i].id
                 << endl;

            cout << "Ten khach hang: "
                 << orders[i].customerName
                 << endl;

            cout << "So dien thoai: "
                 << orders[i].phone
                 << endl;

            cout << "Dia chi: "
                 << orders[i].address
                 << endl;

            cout << "Mon an: "
                 << orders[i].foodName
                 << endl;

            cout << "So luong: "
                 << orders[i].quantity
                 << endl;

            cout << "Trang thai: "
                 << orders[i].status
                 << endl;

            cout << "-------------------------\n";

            found = true;
        }
    }

    if (!found) {
        cout << "Khong tim thay don hang nao!\n";
    }
}

// =====================================================
// 9. THONG KE MON AN BAN CHAY
// - NHAP TEN MON
// - DEM SO LAN MON XUAT HIEN TRONG CAC DON HANG
// =====================================================
void step9(Order orders[], int orderCount) {

    string foodName;

    cout << "\n===== BUOC 9: THONG KE MON AN BAN CHAY =====\n";

    cout << "Nhap ten mon an: ";
    getline(cin, foodName);

    foodName = normalizeFoodName(foodName);

    int count = 0;

    for (int i = 0; i < orderCount; i++) {

        if (toLower(orders[i].foodName) ==
            toLower(foodName)) {

            count += orders[i].quantity;
        }
    }

    cout << "Mon an: "
         << foodName
         << endl;

    cout << "So luong da ban: "
         << count
         << endl;
}

// =====================================================
// 10. TAO THONG BAO GIAO HANG
// =====================================================
void step10() {

    string customerName;
    string orderId;
    string address;

    cout << "\n===== BUOC 10: TAO THONG BAO GIAO HANG =====\n";

    cout << "Nhap ten khach hang: ";
    getline(cin, customerName);

    cout << "Nhap ma don hang: ";
    getline(cin, orderId);

    cout << "Nhap dia chi: ";
    getline(cin, address);

    cout << "\nThong bao giao hang:\n";

    cout << "Don hang ["
         << orderId
         << "] cua ["
         << customerName
         << "] dang duoc giao den ["
         << address
         << "]. Cam on ban!"
         << endl;
}

// =====================================================
// MAIN
// =====================================================
int main() {

    // =================================================
    // DANH SACH MON AN CO SAN
    // =================================================
    Food foods[100];

    int foodCount = 4;

    foods[0].id = "F01";
    foods[0].name = "Banh Mi";
    foods[0].price = 25000;
    foods[0].quantity = 20;

    foods[1].id = "F02";
    foods[1].name = "Pho Bo";
    foods[1].price = 40000;
    foods[1].quantity = 15;

    foods[2].id = "F03";
    foods[2].name = "Com Ga";
    foods[2].price = 45000;
    foods[2].quantity = 10;

    foods[3].id = "F04";
    foods[3].name = "Bun Bo";
    foods[3].price = 40000;
    foods[3].quantity = 12;


    // =================================================
    // DANH SACH DON HANG CO SAN
    // =================================================
    Order orders[100];

    int orderCount = 4;

    orders[0].id = "DH_An_1234";
    orders[0].customerName = "Nguyen Van An";
    orders[0].phone = "0912341234";
    orders[0].address = "Go Vap";
    orders[0].foodName = "Banh Mi";
    orders[0].quantity = 2;
    orders[0].status = "Dang chuan bi";

    orders[1].id = "DH_Binh_5678";
    orders[1].customerName = "Tran Van Binh";
    orders[1].phone = "0987655678";
    orders[1].address = "Quan 3";
    orders[1].foodName = "Pho Bo";
    orders[1].quantity = 1;
    orders[1].status = "Dang giao";

    orders[2].id = "DH_An_4321";
    orders[2].customerName = "Nguyen Van An";
    orders[2].phone = "0909124321";
    orders[2].address = "Tan Binh";
    orders[2].foodName = "Banh Mi";
    orders[2].quantity = 3;
    orders[2].status = "Hoan thanh";

    orders[3].id = "DH_Linh_1111";
    orders[3].customerName = "Le Thi Linh";
    orders[3].phone = "0911111111";
    orders[3].address = "Quan 1";
    orders[3].foodName = "Com Ga";
    orders[3].quantity = 2;
    orders[3].status = "Dang giao";


    // =================================================
    // 1. NHAP VA HIEN THI TEN CUA HANG
    // =================================================
    step1();


    // =================================================
    // 2. CHUAN HOA TEN MON AN
    // =================================================
    step2();


    // =================================================
    // 3. TAO MA DON HANG
    // =================================================
    step3();


    // =================================================
    // 4. KIEM TRA MON AN
    // =================================================
    step4(foods, foodCount);



    // =================================================
    // 6. THAY DOI TRANG THAI DON HANG
    // =================================================
    step6(orders, orderCount);


    // =================================================
    // 7. TIM DON HANG THEO TEN KHACH HANG
    // =================================================
    step7(orders, orderCount);


    // =================================================
    // 9. THONG KE MON AN BAN CHAY
    // =================================================
    step9(orders, orderCount);


    // =================================================
    // 10. TAO THONG BAO GIAO HANG
    // =================================================
    step10();


    return 0;
}