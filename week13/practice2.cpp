#include <iostream>
using namespace std;

// ===== 1. Lớp People =====
class People {
private:
    string cccd;
    string name;
    string address;
public:
    // Constructor mặc định
    People() {
        cccd = "000000000000";
        name = "Unknown";
        address = "Unknown";
    }

    // Constructor có tham số
    People(string c, string n, string a) {
        cccd = c;
        name = n;
        address = a;
    }

    // Hàm hiển thị thông tin
    void displayInfo() const {
        cout << "CCCD: " << cccd << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
    }
};

// ===== 2. Lớp Student kế thừa từ People =====
class Student : public People {
private:
    string mssv;
    int yearEntrance;
public:
    // Constructor mặc định
    Student() : People() {
        mssv = "N/A";
        yearEntrance = 0;
    }

    // Constructor có tham số
    Student(string c, string n, string a, string m, int y) : People(c, n, a) {
        mssv = m;
        yearEntrance = y;
    }

    // Hàm hiển thị thông tin
    void displayInfo() const {
        People::displayInfo();
        cout << "MSSV: " << mssv << endl;
        cout << "YearEntrance: " << yearEntrance << endl;
    }
};

// ===== 3. Lớp FIEStudent kế thừa từ Student =====
class FIEStudent : public Student {
private:
    int credits;
public:
    // Constructor mặc định
    FIEStudent() : Student() {
        credits = 0;
    }

    // Constructor có tham số
    FIEStudent(string c, string n, string a, string m, int y, int cr)
        : Student(c, n, a, m, y) {
        credits = cr;
    }

    // Hàm hiển thị thông tin
    void displayInfo() const {
        Student::displayInfo();
        cout << "Credits: " << credits << endl;
    }
};

// ===== 4. Hàm main =====
int main() {
    // == 1. Tạo các đối tượng People ==
    People p1; // mặc định
    People p2("079123456789", "Nguyen Van A", "Ho Chi Minh"); // có tham số

    // == 2. Tạo các đối tượng Student ==
    Student s1; // mặc định
    Student s2("079123456789", "Tran Thi B", "Ha Noi", "SV001", 2023); // có tham số

    // == 3. Tạo các đối tượng FIEStudent ==
    FIEStudent f1; // mặc định
    FIEStudent f2("079987654321", "Le Minh C", "Da Nang", "FIE2023001", 2023, 120); // có tham số

    // == 4. Hiển thị thông tin ==
    cout << "---- Thong tin doi tuong p1 (People - mac dinh) ----" << endl;
    p1.displayInfo();
    cout << endl;

    cout << "---- Thong tin doi tuong p2 (People - co tham so) ----" << endl;
    p2.displayInfo();
    cout << endl;

    cout << "---- Thong tin doi tuong s1 (Student - mac dinh) ----" << endl;
    s1.displayInfo();
    cout << endl;

    cout << "---- Thong tin doi tuong s2 (Student - co tham so) ----" << endl;
    s2.displayInfo();
    cout << endl;

    cout << "---- Thong tin doi tuong f1 (FIEStudent - mac dinh) ----" << endl;
f1.displayInfo();
    cout << endl;

    cout << "---- Thong tin doi tuong f2 (FIEStudent - co tham so) ----" << endl;
    f2.displayInfo();
    cout << endl;

    return 0;
}
