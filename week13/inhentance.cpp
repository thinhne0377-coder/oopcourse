#include <iostream>
using namespace std;

// 1. Class People (lớp cha)
class People {
private:
    string cccd;
    string name;
    string address;
public:
    // Constructor không tham số - gán giá trị mặc định
    People() {
        cccd = "";
        name = "";
        address = "";
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

// 2. Class Student (kế thừa từ People)
class Student : public People {
private:
    string mssv;
    int yearEntrance;
public:
    // Constructor không tham số - gán giá trị mặc định
    Student() : People() {
        mssv = "";
        yearEntrance = 0;
    }

    // Constructor có tham số
    Student(string c, string n, string a, string m, int y) : People(c, n, a) {
        mssv = m;
        yearEntrance = y;
    }

    // Hàm hiển thị thông tin (ghi đè)
    void displayInfo() const {
        People::displayInfo(); // gọi hàm của lớp cha
        cout << "MSSV: " << mssv << endl;
        cout << "Year Entrance: " << yearEntrance << endl;
    }
};

// 3. Class FIEStudent (kế thừa từ Student)
class FIEStudent : public Student {
private:
    int credits;
public:
    // Constructor không tham số - gán giá trị mặc định
    FIEStudent() : Student() {
        credits = 0;
    }

    // Constructor có tham số
    FIEStudent(string c, string n, string a, string m, int y, int cr)
        : Student(c, n, a, m, y) {
        credits = cr;
    }

    // Hàm hiển thị thông tin (ghi đè)
    void displayInfo() const {
        Student::displayInfo(); // gọi hàm của lớp cha (và People)
        cout << "Credits: " << credits << endl;
    }
};

// 4. Sử dụng trong hàm main()
int main() {
    // Tạo đối tượng People (mặc định)
    People p1;
    cout << "--- People p1 (mặc định) ---" << endl;
    p1.displayInfo();
    cout << endl;

    // Tạo đối tượng People (có tham số)
    People p2("079123456789", "Nguyen Van A", "Ho Chi Minh");
    cout << "--- People p2 (có tham số) ---" << endl;
    p2.displayInfo();
    cout << endl;

    // Tạo đối tượng Student (có tham số)
    Student s1("079123456789", "Tran Thi B", "Ha Noi", "SV001", 2023);
    cout << "--- Student s1 ---" << endl;
    s1.displayInfo();
    cout << endl;

    // Tạo đối tượng FIEStudent (có tham số)
    FIEStudent f1("079987654321", "Le Minh C", "Da Nang", "FIE2023801", 2023, 120);
    cout << "--- FIEStudent f1 ---" << endl;
    f1.displayInfo();
    cout << endl;

    return 0;
}