
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// ==================== 1. CLASS EMPLOYEE ====================
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

    // Ham huy ao
    virtual ~Employee() {}

    // Hien thi thong tin
    virtual void displayInfo() const {
        cout << "CCCD: " << cccd << endl;
        cout << "SDT: " << sdt << endl;
        cout << "Address: " << address << endl;
    }

    // Ham tinh luong ao
    virtual double tinhLuong() const {
        return 0;
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
};

// ==================== 2. CLASS HOURLYEMPLOYEE ====================
class HourlyEmployee : public Employee {
private:
    int soGioLamViec;
    double donGia;

public:
    // Constructor mac dinh
    HourlyEmployee() : Employee() {
        soGioLamViec = 0;
        donGia = 0;
    }

    // Constructor co tham so
    HourlyEmployee(string c, string s, string a,
                   int soGio, double donGia)
        : Employee(c, s, a) {
        soGioLamViec = soGio;
        this->donGia = donGia;
    }

    // Ghi de ham displayInfo()
    void displayInfo() const override {
        Employee::displayInfo();

        cout << "So gio lam viec: "
             << soGioLamViec << endl;

        cout << "Don gia: "
             << donGia << endl;

        cout << "Luong: "
             << tinhLuong() << endl;
    }

    // Luong = so gio lam viec * don gia
    double tinhLuong() const override {
        return soGioLamViec * donGia;
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
};

// ==================== 3. CLASS MONTHLYEMPLOYEE ====================
class MonthlyEmployee : public Employee {
private:
    double luongCoBan;
    double phuCap;
    double heSoThuong;

public:
    // Constructor mac dinh
    MonthlyEmployee() : Employee() {
        luongCoBan = 0;
        phuCap = 0;
        heSoThuong = 0;
    }

    // Constructor co tham so
    MonthlyEmployee(string c, string s, string a,
                    double lcb, double pc, double hs)
        : Employee(c, s, a) {
        luongCoBan = lcb;
        phuCap = pc;
        heSoThuong = hs;
    }

    // Ghi de ham displayInfo()
    void displayInfo() const override {
        Employee::displayInfo();

        cout << "Luong co ban: "
             << luongCoBan << endl;

        cout << "Phu cap: "
             << phuCap << endl;

        cout << "He so thuong: "
             << heSoThuong << endl;

        cout << "Luong: "
             << tinhLuong() << endl;
    }

    // Luong = luong co ban + phu cap
    //       + luong co ban * he so thuong
    double tinhLuong() const override {
        return luongCoBan + phuCap
               + luongCoBan * heSoThuong;
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
};

// ==================== 4. HIEN THI DANH SACH ====================
void hienThiDanhSach(const vector<Employee*>& ds) {
    for (int i = 0; i < (int)ds.size(); i++) {
        cout << "\nNhan vien thu " << i + 1 << endl;
        cout << "------------------------" << endl;
        ds[i]->displayInfo();
    }
}

// ==================== 5. TONG QUY LUONG ====================
double tongQuyLuong(const vector<Employee*>& ds) {
    double tong = 0;

    for (Employee* p : ds) {
        tong += p->tinhLuong();
    }

    return tong;
}

// ==================== 6. TIM LUONG CAO NHAT ====================
Employee* timLuongCaoNhat(const vector<Employee*>& ds) {
    if (ds.empty()) {
        return nullptr;
    }

    Employee* maxNV = ds[0];

    for (Employee* p : ds) {
        if (p->tinhLuong() > maxNV->tinhLuong()) {
            maxNV = p;
        }
    }

    return maxNV;
}

// ==================== 7. TIM LUONG THAP NHAT ====================
Employee* timLuongThapNhat(const vector<Employee*>& ds) {
    if (ds.empty()) {
        return nullptr;
    }

    Employee* minNV = ds[0];

    for (Employee* p : ds) {
        if (p->tinhLuong() < minNV->tinhLuong()) {
            minNV = p;
        }
    }

    return minNV;
}

// ==================== 8. DEM NHAN VIEN TUNG LOAI ====================
void demTheoLoai(const vector<Employee*>& ds) {
    int demHourly = 0;
    int demMonthly = 0;

    for (Employee* p : ds) {
        if (dynamic_cast<HourlyEmployee*>(p) != nullptr) {
            demHourly++;
        }
        else if (dynamic_cast<MonthlyEmployee*>(p) != nullptr) {
            demMonthly++;
        }
    }

    cout << "So HourlyEmployee: " << demHourly << endl;
    cout << "So MonthlyEmployee: " << demMonthly << endl;
}

// ==================== 9. LOC NHAN VIEN THEO LUONG ====================
void locLuongLonHon(const vector<Employee*>& ds, double nguong) {
    bool co = false;

    for (Employee* p : ds) {
        if (p->tinhLuong() > nguong) {
            p->displayInfo();
            cout << "------------------------" << endl;
            co = true;
        }
    }

    if (!co) {
        cout << "Khong co nhan vien nao co luong lon hon "
             << nguong << endl;
    }
}

// ==================== 10. SAP XEP LUONG GIAM DAN ====================
void sapXepGiamDan(vector<Employee*>& ds) {
    sort(ds.begin(), ds.end(),
         [](Employee* a, Employee* b) {
             return a->tinhLuong() > b->tinhLuong();
         });
}

// ==================== HAM MAIN ====================
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

    // ===== HIEN THI THONG TIN 3 DOI TUONG =====
    cout << "========== THONG TIN EMPLOYEE ==========" << endl;
    e1.displayInfo();

    cout << "\n========== THONG TIN HOURLYEMPLOYEE ==========" << endl;
    h1.displayInfo();

    cout << "\n========== THONG TIN MONTHLYEMPLOYEE ==========" << endl;
    m1.displayInfo();

    // Tao them nhan vien de thuc hanh
    HourlyEmployee h2(
        "079111111111",
        "Pham Van D",
        "Hue",
        100,
        60000
    );

    MonthlyEmployee m2(
        "079222222222",
        "Do Thi E",
        "Can Tho",
        8000000,
        1000000,
        0.5
    );

    // Danh sach nhan vien dung da hinh
    vector<Employee*> ds;

    ds.push_back(&h1);
    ds.push_back(&m1);
    ds.push_back(&h2);
    ds.push_back(&m2);

    // ===== TONG QUY LUONG =====
    cout << "\n========== TONG QUY LUONG ==========" << endl;
    cout << "Tong quy luong: "
         << tongQuyLuong(ds) << " VND" << endl;

    // ===== NHAN VIEN LUONG CAO NHAT =====
    cout << "\n========== LUONG CAO NHAT ==========" << endl;
    Employee* maxNV = timLuongCaoNhat(ds);

    if (maxNV != nullptr) {
        maxNV->displayInfo();
    }

    // ===== NHAN VIEN LUONG THAP NHAT =====
    cout << "\n========== LUONG THAP NHAT ==========" << endl;
    Employee* minNV = timLuongThapNhat(ds);

    if (minNV != nullptr) {
        minNV->displayInfo();
    }

    // ===== DEM SO LUONG TUNG LOAI =====
    cout << "\n========== DEM NHAN VIEN ==========" << endl;
    demTheoLoai(ds);

    // ===== LOC NHAN VIEN THEO LUONG =====
    double nguong;

    cout << "\nNhap nguong luong: ";
    cin >> nguong;

    cout << "\n========== NHAN VIEN LUONG LON HON "
         << nguong << " ==========" << endl;

    locLuongLonHon(ds, nguong);

    // ===== SAP XEP LUONG GIAM DAN =====
    sapXepGiamDan(ds);

    cout << "\n========== DANH SACH LUONG GIAM DAN ==========" << endl;
    hienThiDanhSach(ds);

    return 0;
}
