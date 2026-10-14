#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// ===== 1. Class Employee (lớp cha) =====
class Employee {
private:
    string cccd;
    string sdt;
    string address;
public:
    // Constructor không tham số - gán giá trị mặc định
    Employee() {
        cccd = "";
        sdt = "";
        address = "";
    }

    // Constructor có tham số
    Employee(string c, string p, string a) {
        cccd = c;
        sdt = p;
        address = a;
    }

    // Getters
    string getCCCD() const { return cccd; }
    string getSDT() const { return sdt; }
    string getAddress() const { return address; }

    // Setters
    void setCCCD(string c) { cccd = c; }
    void setSDT(string p) { sdt = p; }
    void setAddress(string a) { address = a; }
};

// ===== 2. Class HourlyEmployee (kế thừa từ Employee) =====
class HourlyEmployee : public Employee {
private:
    int soGioLamViec;
    double donGia;
public:
    // Constructor không tham số
    HourlyEmployee() : Employee() {
        soGioLamViec = 0;
        donGia = 0.0;
    }

    // Constructor có tham số
    HourlyEmployee(string c, string p, string a, int soGio, double dg)
        : Employee(c, p, a) {
        soGioLamViec = soGio;
        donGia = dg;
    }

    // Getters
    int getSoGioLamViec() const { return soGioLamViec; }
    double getDonGia() const { return donGia; }

    // Setters
    void setSoGioLamViec(int g) { soGioLamViec = g; }
    void setDonGia(double dg) { donGia = dg; }
};

// ===== 3. Class MonthlyEmployee (kế thừa từ Employee) =====
class MonthlyEmployee : public Employee {
private:
    double luongCoBan;
    double phuCap;
    double heSoThuong;
public:
    // Constructor không tham số
    MonthlyEmployee() : Employee() {
        luongCoBan = 0.0;
        phuCap = 0.0;
        heSoThuong = 0.0;
    }

    // Constructor có tham số
    MonthlyEmployee(string c, string p, string a, double lcb, double pc, double hs)
        : Employee(c, p, a) {
        luongCoBan = lcb;
        phuCap = pc;
        heSoThuong = hs;
    }

    // Getters
    double getLuongCoBan() const { return luongCoBan; }
    double getPhuCap() const { return phuCap; }
    double getHeSoThuong() const { return heSoThuong; }

    // Setters
    void setLuongCoBan(double lcb) { luongCoBan = lcb; }
    void setPhuCap(double pc) { phuCap = pc; }
    void setHeSoThuong(double hs) { heSoThuong = hs; }
};

// ===== 4. Hàm main =====
int main() {
    // Tạo đối tượng Employee (mặc định)
    Employee e1;

    // Tạo đối tượng HourlyEmployee (có tham số)
    HourlyEmployee h1("079123456789", "0901200343", "Ha Noi", 160, 50000);

    // Tạo đối tượng MonthlyEmployee (có tham số)
    MonthlyEmployee m1("079987654321", "0903040405", "Da Nang", 15000000, 2000000, 1.2);
    cout << fixed << setprecision(0); // Định dạng số thực với 2 chữ số thập phân

    // Hiển thị thông tin (ví dụ)
cout << "== Employee e1 ==" << endl;
    cout << "CCCD: " << e1.getCCCD() << endl;
    cout << "SDT: " << e1.getSDT() << endl;
    cout << "Address: " << e1.getAddress() << endl << endl;

    cout << "== HourlyEmployee h1 ==" << endl;
    cout << "CCCD: " << h1.getCCCD() << endl;
    cout << "SDT: " << h1.getSDT() << endl;
    cout << "Address: " << h1.getAddress() << endl;
    cout << "So gio lam viec: " << h1.getSoGioLamViec() << endl;
    cout << "Don gia: " << h1.getDonGia() << endl << endl;

    cout << "== MonthlyEmployee m1 ==" << endl;
    cout << "CCCD: " << m1.getCCCD() << endl;
    cout << "SDT: " << m1.getSDT() << endl;
    cout << "Address: " << m1.getAddress() << endl;
    cout << "Luong co ban: " << m1.getLuongCoBan() << endl;
    cout << "Phu cap: " << m1.getPhuCap() << endl;
    cout << "He so thuong: " << m1.getHeSoThuong() << endl;

    return 0;
}


