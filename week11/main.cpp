#include <iostream>
#include <string>

using namespace std;

// =====================================================
// STRUCT DATE
// =====================================================
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

// =====================================================
// CLASS STUDENT
// =====================================================
class Student {

private:
    // Properties
    string name;
    string address;
    Date birthdate;
    string cccd;

public:

    // =================================================
    // CONSTRUCTORS
    // =================================================

    // Constructor mac dinh
    Student() {
        name = "";
        address = "";
        birthdate = Date();
        cccd = "";
    }

    // Constructor 1 tham so
    Student(string n) {
        name = n;
        address = "";
        birthdate = Date();
        cccd = "";
    }

    // Constructor Date
    Student(Date d) {
        name = "";
        address = "";
        birthdate = d;
        cccd = "";
    }

    // Constructor name + address
    Student(string n, string addr) {
        name = n;
        address = addr;
        birthdate = Date();
        cccd = "";
    }

    // Constructor name + address + Date
    Student(string n, string addr, Date d) {
        name = n;
        address = addr;
        birthdate = d;
        cccd = "";
    }

    // Constructor day du
    Student(string n, string addr, Date d, string id) {
        name = n;
        address = addr;
        birthdate = d;
        cccd = id;
    }

    // =================================================
    // GET BIRTH YEAR
    // =================================================

    int getBirthYear() {
        return birthdate.year;
    }

    // =================================================
    // GET ADDRESS
    // =================================================

    string getAddress() {
        return address;
    }

    // =================================================
    // NHAP THONG TIN SINH VIEN
    // =================================================

    void setStudentInfo() {

        cout << "Nhap ten: ";
        getline(cin, name);

        cout << "Nhap dia chi (tinh/thanh pho): ";
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

    // =================================================
    // LAY THONG TIN SINH VIEN THEO CCCD
    // =================================================

    Student getStudentInfo(string search_cccd) {

        if (this->cccd == search_cccd) {
            return *this;
        }

        return Student();
    }

    // =================================================
    // IN THONG TIN SINH VIEN
    // =================================================

    void printInfo() {

        cout << "Ten       : " << name << endl;
        cout << "Tinh      : " << address << endl;

        cout << "Ngay sinh : "
             << birthdate.day << "/"
             << birthdate.month << "/"
             << birthdate.year << endl;

        cout << "CCCD      : " << cccd << endl;

        cout << "----------------------------------------"
             << endl;
    }
};

// =====================================================
// THONG KE SINH VIEN THEO NAM SINH
// =====================================================

void thongKeTheoNamSinh(
    Student arr[],
    int size,
    int targetYear
) {

    int count = 0;

    cout << endl;
    cout << "========================================"
         << endl;

    cout << "THONG KE SINH VIEN SINH NAM "
         << targetYear
         << endl;

    cout << "========================================"
         << endl;

    for (int i = 0; i < size; i++) {

        if (arr[i].getBirthYear() == targetYear) {

            arr[i].printInfo();

            count++;
        }
    }

    cout << "=> Tong so luong sinh vien sinh nam "
         << targetYear
         << ": "
         << count
         << endl;
}

// =====================================================
// THONG KE SINH VIEN THEO TINH
// =====================================================

void thongKeTheoTinh(
    Student arr[],
    int size,
    string targetProvince
) {

    int count = 0;

    cout << endl;
    cout << "========================================"
         << endl;

    cout << "THONG KE SINH VIEN O TINH: "
         << targetProvince
         << endl;

    cout << "========================================"
         << endl;

    for (int i = 0; i < size; i++) {

        if (arr[i].getAddress() == targetProvince) {

            arr[i].printInfo();

            count++;
        }
    }

    cout << "=> Tong so luong sinh vien o "
         << targetProvince
         << ": "
         << count
         << endl;
}

// =====================================================
// MAIN
// =====================================================

int main() {

    // =================================================
    // TAO DANH SACH SINH VIEN
    // =================================================

    Student database[5] = {

        Student(
            "Khang",
            "Ho Chi Minh",
            Date(2007, 12, 1),
            "001"
        ),

        Student(
            "Huong",
            "Dong Nai",
            Date(2000, 5, 10),
            "002"
        ),

        Student(
            "Bao",
            "Ho Chi Minh",
            Date(2001, 8, 15),
            "003"
        ),

        Student(
            "Phuc",
            "Binh Duong",
            Date(2000, 2, 20),
            "004"
        ),

        Student(
            "Linh",
            "Dong Nai",
            Date(2007, 10, 5),
            "005"
        )
    };

    int total_students = 5;

    // =================================================
    // IN DANH SACH SINH VIEN
    // =================================================

    cout << "========================================"
         << endl;

    cout << "          DANH SACH SINH VIEN"
         << endl;

    cout << "========================================"
         << endl;

    for (int i = 0; i < total_students; i++) {

        cout << endl;

        cout << "Sinh vien " << i + 1 << ":" << endl;

        database[i].printInfo();
    }

    // =================================================
    // THONG KE THEO NAM SINH 2000
    // =================================================

    thongKeTheoNamSinh(
        database,
        total_students,
        2000
    );

    // =================================================
    // THONG KE THEO NAM SINH 2001
    // =================================================

    thongKeTheoNamSinh(
        database,
        total_students,
        2001
    );

    // =================================================
    // THONG KE THEO TINH
    // =================================================

    thongKeTheoTinh(
        database,
        total_students,
        "Ho Chi Minh"
    );

    thongKeTheoTinh(
        database,
        total_students,
        "Dong Nai"
    );

    thongKeTheoTinh(
        database,
        total_students,
        "Binh Duong"
    );

    return 0;
}
