
```cpp
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// 1. Class Employee (lop cha)
class Employee {
protected:
    string cccd;
    string sdt;
    string address;

public:
    // Constructor mac dinh
    Employee() {
        cccd = "";
        sdt = "";
        address = "";
    }

    // Constructor co tham so
    Employee(string c, string s, string a) {
        cccd = c;
        sdt = s;
        address = a;
    }

    // Getter
    string getCCCD() const {
        return cccd;
    }

    string getSDT() const {
        return sdt;
    }

    string getAddress() const {
        return address;
    }

    // Setter
    void setCCCD(string c) {
        cccd = c;
    }

    void setSDT(string s) {
        sdt = s;
    }

    void setAddress(string a) {
        address = a;
    }

    // Hien thi thong tin Employee
    void displayInfo() const {
        cout << "CCCD: " << cccd << endl;
        cout << "SDT: " << sdt << endl;
        cout << "Address: " << address << endl;
    }
};

// 2. Class HourlyEmployee (ke thua Employee)
class HourlyEmployee : public Employee {
private:
    int soGioLamViec;
    double donGia;

public:
    // Constructor mac dinh
    HourlyEmployee() : Employee() {
        soGioLamViec = 0;
        donGia = 0.0;
    }

    // Constructor co tham so
    HourlyEmployee(string c, string s, string a,
                   int soGio, double dg)
        : Employee(c, s, a) {
        soGioLamViec = soGio;
        donGia = dg;
    }

    // Getter
    int getSoGioLamViec() const {
        return soGioLamViec;
    }

    double getDonGia() const {
        return donGia;
    }

    // Setter
    void setSoGioLamViec(int g) {
        soGioLamViec = g;
    }

    void setDonGia(double dg) {
        donGia = dg;
    }

    // Tinh luong nhan vien theo gio
    double tinhLuong() const {
        return soGioLamViec * donGia;
    }

    // Hien thi thong tin HourlyEmployee
    void displayInfo() const {
        Employee::displayInfo();

        cout << "So gio lam viec: "
             << soGioLamViec << endl;
        cout << "Don gia: "
             << fixed << setprecision(0)
             << donGia << endl;
        cout << "Luong: "
             << tinhLuong() << endl;
    }
};

// 3. Class MonthlyEmployee (ke thua Employee)
class MonthlyEmployee : public Employee {
private:
    double luongCoBan;
    double phuCap;
    double heSoThuong;

public:
    // Constructor mac dinh
    MonthlyEmployee() : Employee() {
        luongCoBan = 0.0;
        phuCap = 0.0;
        heSoThuong = 0.0;
    }

    // Constructor co tham so
    MonthlyEmployee(string c, string s, string a,
                    double lcb, double pc, double hs)
        : Employee(c, s, a) {
        luongCoBan = lcb;
        phuCap = pc;
        heSoThuong = hs;
    }

    // Getter
    double getLuongCoBan() const {
        return luongCoBan;
    }

    double getPhuCap() const {
        return phuCap;
    }

    double getHeSoThuong() const {
        return heSoThuong;
    }

    // Setter
    void setLuongCoBan(double lcb) {
        luongCoBan = lcb;
    }

    void setPhuCap(double pc) {
        phuCap = pc;
    }

    void setHeSoThuong(double hs) {
        heSoThuong = hs;
    }

    // Tinh luong nhan vien theo thang
    double tinhLuong() const {
        return luongCoBan + phuCap
               + luongCoBan * heSoThuong;
    }

    // Hien thi thong tin MonthlyEmployee
    void displayInfo() const {
        Employee::displayInfo();

        cout << "Luong co ban: "
             << fixed << setprecision(0)
             << luongCoBan << endl;
        cout << "Phu cap: "
             << phuCap << endl;
        cout << "He so thuong: "
             << setprecision(1)
             << heSoThuong << endl;
        cout << "Luong: "
             << fixed << setprecision(0)
             << tinhLuong() << endl;
    }
};

// 4. Ham main()
int main() {
    cout << fixed << setprecision(0);

    // Tao doi tuong Employee
    Employee e1(
        "079123456789",
        "Nguyen Van A",
        "Ho Chi Minh"
    );

    // Tao doi tuong HourlyEmployee
    HourlyEmployee h1(
        "079876543210",
        "Tran Thi B",
        "Ha Noi",
        160,
        50000
    );

    // Tao doi tuong MonthlyEmployee
    MonthlyEmployee m1(
        "079987654321",
        "Le Minh C",
        "Da Nang",
        15000000,
        2000000,
        1.2
    );

    // Hien thi thong tin Employee
    cout << "----- Thong tin Employee -----" << endl;
    e1.displayInfo();

    // Hien thi thong tin HourlyEmployee
    cout << "\n----- Thong tin HourlyEmployee -----"
         << endl;
    h1.displayInfo();

    // Hien thi thong tin MonthlyEmployee
    cout << "\n----- Thong tin MonthlyEmployee -----"
         << endl;
    m1.displayInfo();

    return 0;
}
```