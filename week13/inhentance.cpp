#include <iostream>
#include <string>
using namespace std;

class People {
private:
    string cccd;
    string name;
    string address;

public:
// Constructors không tham số
    People () {
        cccd = "00000000000000";
        name = "Unknown";
        address = "Unknown";
    }
// Constructor có tham số
    People(string c, string n, string a){
        cccd = c;
        name = n;
        address = a;
    }

    string getCCCD() const { return cccd; }
    string getName() const { return name; }
    string getAddress() const { return address; }
    void setCCCD(string c) { cccd = c; }
    void setName(string n) { name = n; }
    void setAddress(string a) { address = a; }
};

class Student : public People {
private:
    string mssv;
    int yearEntrance;
public:
    Student() : People() {
        mssv = "Unknown";
        yearEntrance = 0;
    }

    Student(string c, string n, string a, string m, int y) : People(c, n, a) {
        mssv = m;
        yearEntrance = y;
    }

    string getMSSV() const { return mssv; }
    int getYearEntrance() const { return yearEntrance; }
    void setMSSV(string m) { mssv = m; }
    void setYearEntrance(int y) { yearEntrance = y; }
};

class FIEstudents : public Student {
private:
   int credits;
public:
    FIEstudents() : Student() {
        credits = 0;
    }

    FIEstudents(string c, string n, string a, string m, int y, int cr) : Student(c, n, a, m, y) {
        credits = cr;
    }

    int getCredits() const { return credits; }
    void setCredits(int cr) { credits = cr; }

    void displayInfo() const {
        cout << "CCCD: " << getCCCD() << endl;
        cout << " | Name: " << getName() << endl;
        cout << " | Address: " << getAddress() << endl;
        cout << " | MSSV: " << getMSSV() << endl;
        cout << " | Year Entrance: " << getYearEntrance() << endl;
        cout << " | Credits: " << credits << endl;
        cout << "-----------------------------" << endl;

    }
};

int main() {
    People p1();
    People p2("23456789012345", "Tran Thi B", "Hanoi");

    Student s1();
    Student s2("34567890123456", "Nguyen Van C", "HCMC", "B12345", 2020);

    FIEstudents f1;
    FIEstudents f2("45678901234567", "Le Thi D", "Da Nang", "C67890", 2021, 90);

    cout << "=== Thông tin đối tượng f1 ===" << endl;
    f1.displayInfo();
    cout << "=== Thông tin đối tượng f2 ===" << endl;
    f2.displayInfo();

    return 0;
    
}