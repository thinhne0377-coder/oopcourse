#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// =========================
// DATE
// =========================
struct Date {
    int year;
    int month;
    int day;

    Date() {
        year = 0;
        month = 0;
        day = 0;
    }

    Date(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }
};

// =========================
// STUDENT
// =========================
class Student {
private:
    string name;
    string address;
    Date birthdate;
    string cccd;

public:

    // =========================
    // CONSTRUCTORS
    // =========================

    Student() {
        name = "";
        address = "";
        birthdate = Date();
        cccd = "";
    }

    Student(string n) {
        name = n;
        address = "";
        birthdate = Date();
        cccd = "";
    }

    Student(Date d) {
        name = "";
        address = "";
        birthdate = d;
        cccd = "";
    }

    Student(string n, string addr) {
        name = n;
        address = addr;
        birthdate = Date();
        cccd = "";
    }

    Student(string n, string addr, Date d) {
        name = n;
        address = addr;
        birthdate = d;
        cccd = "";
    }

    Student(string n, string addr, Date d, string id) {
        name = n;
        address = addr;
        birthdate = d;
        cccd = id;
    }

    // =========================
    // NHAP THONG TIN
    // =========================

    void setStudentInfo() {
        cout << "Nhap ten: ";
        getline(cin, name);

        cout << "Nhap dia chi: ";
        getline(cin, address);

        cout << "Nhap nam sinh: ";
        cin >> birthdate.year;

        cout << "Nhap thang sinh: ";
        cin >> birthdate.month;

        cout << "Nhap ngay sinh: ";
        cin >> birthdate.day;

        cin.ignore();

        cout << "Nhap CCCD: ";
        getline(cin, cccd);
    }

    // =========================
    // CHI DISPLAY THONG TIN
    // =========================

    void getStudentInfo() const {
        cout << "-----------------------------" << endl;
        cout << "Ten      : " << name << endl;
        cout << "Dia chi  : " << address << endl;
        cout << "Ngay sinh: "
             << birthdate.day << "/"
             << birthdate.month << "/"
             << birthdate.year << endl;
        cout << "CCCD     : " << cccd << endl;
    }

    // =========================
    // GET
    // =========================

    int getBirthYear() const {
        return birthdate.year;
    }

    int getBirthMonth() const {
        return birthdate.month;
    }

    int getBirthDay() const {
        return birthdate.day;
    }

    string getAddress() const {
        return address;
    }

    string getName() const {
        return name;
    }

    string getCccd() const {
        return cccd;
    }

    // ==================================================
    // LAY DANH SACH THEO NAM SINH
    // KHONG DUOC VOID
    // TRA VE VECTOR
    // ==================================================

    vector<Student> getStudentbyYear(
        int year,
        vector<Student> students
    ) {

        vector<Student> result;

        for (int i = 0; i < students.size(); i++) {

            if (students[i].getBirthYear() == year) {
                result.push_back(students[i]);
            }
        }

        // Liet ke theo ngay sinh
        sort(result.begin(), result.end(),
            [](Student a, Student b) {

                if (a.getBirthMonth() != b.getBirthMonth()) {
                    return a.getBirthMonth() < b.getBirthMonth();
                }

                return a.getBirthDay() < b.getBirthDay();
            }
        );

        return result;
    }

    // ==================================================
    // LAY DANH SACH THEO TINH
    // KHONG DUOC VOID
    // TRA VE VECTOR
    // ==================================================

    vector<Student> getStudentsbyAddress(
        string address,
        vector<Student> students
    ) {

        vector<Student> result;

        for (int i = 0; i < students.size(); i++) {

            if (students[i].getAddress() == address) {
                result.push_back(students[i]);
            }
        }

        return result;
    }
};


// ==================================================
// DISPLAY
// VOID CHI DUNG DE DISPLAY
// ==================================================

void display(vector<Student> students) {

    for (int i = 0; i < students.size(); i++) {
        students[i].getStudentInfo();
    }
}


// ==================================================
// MAIN
// ==================================================

int main() {

    // Tao danh sach sinh vien
    vector<Student> students;

    Student student1(
        "Nguyen Van An",
        "Ho Chi Minh",
        Date(2000, 5, 15),
        "001"
    );

    Student student2(
        "Tran Thi Huong",
        "Dong Nai",
        Date(2000, 3, 10),
        "002"
    );

    Student student3(
        "Le Van Bao",
        "Ho Chi Minh",
        Date(2001, 8, 20),
        "003"
    );

    Student student4(
        "Pham Thi Lan",
        "Dong Nai",
        Date(2001, 1, 5),
        "004"
    );

    Student student5(
        "Nguyen Van Nam",
        "Binh Duong",
        Date(2000, 1, 25),
        "005"
    );

    students.push_back(student1);
    students.push_back(student2);
    students.push_back(student3);
    students.push_back(student4);
    students.push_back(student5);


    // ==================================================
    // THONG KE NAM 2000
    // ==================================================

    cout << "======================================" << endl;
    cout << "SINH VIEN SINH NAM 2000" << endl;
    cout << "======================================" << endl;

    vector<Student> s =
        student1.getStudentbyYear(2000, students);

    display(s);


    // ==================================================
    // THONG KE NAM 2001
    // ==================================================

    cout << "\n======================================" << endl;
    cout << "SINH VIEN SINH NAM 2001" << endl;
    cout << "======================================" << endl;

    vector<Student> s2 =
        student1.getStudentbyYear(2001, students);

    display(s2);


    // ==================================================
    // THONG KE THEO TINH
    // ==================================================

    cout << "\n======================================" << endl;
    cout << "SINH VIEN O HO CHI MINH" << endl;
    cout << "======================================" << endl;

    vector<Student> s3 =
        student1.getStudentsbyAddress(
            "Ho Chi Minh",
            students
        );

    display(s3);


    cout << "\n======================================" << endl;
    cout << "SINH VIEN O DONG NAI" << endl;
    cout << "======================================" << endl;

    vector<Student> s4 =
        student1.getStudentsbyAddress(
            "Dong Nai",
            students
        );

    display(s4);

    return 0;
}