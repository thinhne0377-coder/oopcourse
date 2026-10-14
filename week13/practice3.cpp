```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

// ==================================================
// 1. CLASS EMPLOYEE (LOP CHA)
// ==================================================
class Employee {
protected:
    string cccd;
    string sdt;
    string address;

public:
    Employee() {
        cccd = "";
        sdt = "";
        address = "";
    }

    Employee(string c, string s, string a) {
        cccd = c;
        sdt = s;
        address = a;
    }

    virtual ~Employee() {}

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

    // Tinh luong cua Employee
    virtual double tinhLuong() const {
        return 0.0;
    }

    // Hien thi thong tin
    virtual void displayInfo() const {
        cout << "CCCD: " << cccd << endl;
        cout << "SDT: " << sdt << endl;
        cout << "Address: " << address << endl;
    }

    virtual string getLoai() const {
        return "Employee";
    }
};

// ==================================================
// 2. CLASS HOURLYEMPLOYEE
// ==================================================
class HourlyEmployee : public Employee {
private:
    int soGioLamViec;
    double donGia;

public:
    HourlyEmployee() : Employee() {
        soGioLamViec = 0;
        donGia = 0.0;
    }

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

    // Cau 1: Tinh luong theo gio
    double tinhLuong() const override {
        return soGioLamViec * donGia;
    }

    // Cau 2: Hien thi thong tin
    void displayInfo() const override {
        cout << "Loai: HourlyEmployee" << endl;
        Employee::displayInfo();
        cout << "So gio lam viec: "
             << soGioLamViec << endl;
        cout << "Don gia: " << donGia << endl;
        cout << "Luong: " << tinhLuong() << endl;
    }

    string getLoai() const override {
        return "HourlyEmployee";
    }
};

// ==================================================
// 3. CLASS MONTHLYEMPLOYEE
// ==================================================
class MonthlyEmployee : public Employee {
private:
    double luongCoBan;
    double phuCap;
    double heSoThuong;

public:
    MonthlyEmployee() : Employee() {
        luongCoBan = 0.0;
        phuCap = 0.0;
        heSoThuong = 0.0;
    }

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

    // Cau 1: Tinh luong theo thang
    double tinhLuong() const override {
        return luongCoBan + phuCap
             + luongCoBan * heSoThuong;
    }

    // Cau 2: Hien thi thong tin
    void displayInfo() const override {
        cout << "Loai: MonthlyEmployee" << endl;
        Employee::displayInfo();
        cout << "Luong co ban: " << luongCoBan << endl;
        cout << "Phu cap: " << phuCap << endl;
        cout << "He so thuong: " << heSoThuong << endl;
        cout << "Luong: " << tinhLuong() << endl;
    }

    string getLoai() const override {
        return "MonthlyEmployee";
    }
};

// ==================================================
// 4. HAM HIEN THI DANH SACH
// ==================================================
void hienThiDanhSach(const vector<Employee*>& ds) {
    if (ds.empty()) {
        cout << "Danh sach rong!" << endl;
        return;
    }

    for (size_t i = 0; i < ds.size(); i++) {
        cout << "\n========== NHAN VIEN "
             << i + 1 << " ==========" << endl;
        ds[i]->displayInfo();
    }
}

// ==================================================
// 5. CAU 4: TINH TONG QUY LUONG
// ==================================================
double tinhTongQuyLuong(const vector<Employee*>& ds) {
    double tong = 0;

    for (const Employee* nv : ds) {
        tong += nv->tinhLuong();
    }

    return tong;
}

// ==================================================
// 6. CAU 5: TIM LUONG CAO NHAT VA THAP NHAT
// ==================================================
void timLuongCaoThap(const vector<Employee*>& ds) {
    if (ds.empty()) {
        cout << "Danh sach rong!" << endl;
        return;
    }

    double luongMax = ds[0]->tinhLuong();
    double luongMin = ds[0]->tinhLuong();

    for (const Employee* nv : ds) {
        if (nv->tinhLuong() > luongMax) {
            luongMax = nv->tinhLuong();
        }

        if (nv->tinhLuong() < luongMin) {
            luongMin = nv->tinhLuong();
        }
    }

    cout << "\nNhan vien co luong cao nhat:"
         << endl;

    for (const Employee* nv : ds) {
        if (nv->tinhLuong() == luongMax) {
            nv->displayInfo();
            cout << "------------------------" << endl;
        }
    }

    cout << "\nNhan vien co luong thap nhat:"
         << endl;

    for (const Employee* nv : ds) {
        if (nv->tinhLuong() == luongMin) {
            nv->displayInfo();
            cout << "------------------------" << endl;
        }
    }
}

// ==================================================
// 7. CAU 6: DEM SO LUONG TUNG LOAI NHAN VIEN
// ==================================================
void demNhanVien(const vector<Employee*>& ds) {
    int demEmployee = 0;
    int demHourly = 0;
    int demMonthly = 0;

    for (const Employee* nv : ds) {
        if (nv->getLoai() == "HourlyEmployee") {
            demHourly++;
        } else if (nv->getLoai() == "MonthlyEmployee") {
            demMonthly++;
        } else {
            demEmployee++;
        }
    }

    cout << "So Employee: " << demEmployee << endl;
    cout << "So HourlyEmployee: " << demHourly << endl;
    cout << "So MonthlyEmployee: " << demMonthly << endl;
    cout << "Tong so nhan vien: " << ds.size() << endl;
}

// ==================================================
// 8. CAU 7: TIM NHAN VIEN CO LUONG LON HON MUC NHAP
// ==================================================
void timNhanVienTheoLuong(const vector<Employee*>& ds,
                          double mucLuong) {
    bool timThay = false;

    for (const Employee* nv : ds) {
        if (nv->tinhLuong() > mucLuong) {
            nv->displayInfo();
            cout << "------------------------" << endl;
            timThay = true;
        }
    }

    if (!timThay) {
        cout << "Khong co nhan vien nao co luong lon hon "
             << mucLuong << endl;
    }
}

// ==================================================
// 9. CAU 8: SAP XEP LUONG GIAM DAN
// ==================================================
void sapXepLuongGiamDan(vector<Employee*>& ds) {
    sort(ds.begin(), ds.end(),
         [](const Employee* a, const Employee* b) {
             return a->tinhLuong() > b->tinhLuong();
         });

    cout << "\nDanh sach sau khi sap xep luong giam dan:"
         << endl;

    hienThiDanhSach(ds);
}

// ==================================================
// 10. HAM MAIN
// ==================================================
int main() {
    cout << fixed << setprecision(0);

    // Danh sach nhan vien
    vector<Employee*> ds;

    // Tao 2 Employee
    ds.push_back(new Employee(
        "001", "0901111111", "Ho Chi Minh"));

    ds.push_back(new Employee(
        "002", "0902222222", "Ha Noi"));

    // Tao 2 HourlyEmployee
    ds.push_back(new HourlyEmployee(
        "003", "0903333333", "Ha Noi",
        160, 50000));

    ds.push_back(new HourlyEmployee(
        "004", "0904444444", "Da Nang",
        120, 60000));

    // Tao 2 MonthlyEmployee
    ds.push_back(new MonthlyEmployee(
        "005", "0905555555", "Da Nang",
        15000000, 2000000, 1.2));

    ds.push_back(new MonthlyEmployee(
        "006", "0906666666", "Can Tho",
        12000000, 1500000, 0.5));

    // Cau 2 va 3: Hien thi danh sach nhan vien
    cout << "========== CAU 2, 3 ==========" << endl;
    hienThiDanhSach(ds);

    // Cau 4: Tong quy luong
    cout << "\n========== CAU 4 ==========" << endl;
    cout << "Tong quy luong: "
         << tinhTongQuyLuong(ds) << endl;

    // Cau 5: Luong cao nhat va thap nhat
    cout << "\n========== CAU 5 ==========" << endl;
    timLuongCaoThap(ds);

    // Cau 6: Dem tung loai nhan vien
    cout << "\n========== CAU 6 ==========" << endl;
    demNhanVien(ds);

    // Cau 7: Tim nhan vien theo muc luong
    cout << "\n========== CAU 7 ==========" << endl;

    double mucLuong;
    cout << "Nhap muc luong can tim: ";

    if (!(cin >> mucLuong)) {
        cout << "Muc luong khong hop le!" << endl;

        for (Employee* nv : ds) {
            delete nv;
        }
        return 1;
    }

    cout << "\nNhan vien co luong lon hon "
         << mucLuong << ":" << endl;

    timNhanVienTheoLuong(ds, mucLuong);

    // Cau 8: Sap xep luong giam dan
    cout << "\n========== CAU 8 ==========" << endl;
    sapXepLuongGiamDan(ds);

    // Giai phong bo nho
    for (Employee* nv : ds) {
        delete nv;
    }

    ds.clear();

    return 0;
}
```