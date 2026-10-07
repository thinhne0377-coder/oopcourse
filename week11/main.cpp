#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// ======================================================
// CHUYEN CHUOI VE CHU THUONG
// ======================================================
string toLower(string s) {
    for (size_t i = 0; i < s.length(); i++) {
        s[i] = tolower((unsigned char)s[i]);
    }
    return s;
}

// ======================================================
// CLASS DATE
// ======================================================
class Date {
private:
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;

public:

    // Constructor mac dinh
    Date() {
        year = 2000;
        month = 1;
        day = 1;
        hour = 0;
        minute = 0;
        second = 0;
    }

    // Constructor co tham so
    Date(int y, int m, int d, int h = 0, int mi = 0, int s = 0) {
        year = y;
        month = m;
        day = d;
        hour = h;
        minute = mi;
        second = s;
    }

    // Nhap ngay gio
    void input() {
        cout << "Nhap nam: ";
        cin >> year;

        cout << "Nhap thang: ";
        cin >> month;

        cout << "Nhap ngay: ";
        cin >> day;

        cout << "Nhap gio: ";
        cin >> hour;

        cout << "Nhap phut: ";
        cin >> minute;

        cout << "Nhap giay: ";
        cin >> second;

        cin.ignore();
    }

    // Xuat ngay gio
    void display() const {
        cout << year << "/"
             << (month < 10 ? "0" : "") << month << "/"
             << (day < 10 ? "0" : "") << day << " "
             << (hour < 10 ? "0" : "") << hour << ":"
             << (minute < 10 ? "0" : "") << minute << ":"
             << (second < 10 ? "0" : "") << second;
    }

    int getYear() const {
        return year;
    }

    int getMonth() const {
        return month;
    }

    int getDay() const {
        return day;
    }
};

// ======================================================
// CLASS STUDENT
// ======================================================
class Student {
private:
    string name;
    string address;
    Date birthdate;
    string cccd;

public:

    // ==================================================
    // CONSTRUCTORS
    // ==================================================

    // 1. Student()
    Student() {
        name = "";
        address = "";
        birthdate = Date();
        cccd = "";
    }

    // 2. Student(string)
    Student(string n) {
        name = n;
        address = "";
        birthdate = Date();
        cccd = "";
    }

    // 3. Student(Date)
    Student(Date d) {
        name = "";
        address = "";
        birthdate = d;
        cccd = "";
    }

    // 4. Student(string, string)
    Student(string n, string addr) {
        name = n;
        address = addr;
        birthdate = Date();
        cccd = "";
    }

    // 5. Student(string, string, Date)
    Student(string n, string addr, Date d) {
        name = n;
        address = addr;
        birthdate = d;
        cccd = "";
    }

    // 6. Student(string, string, Date, string)
    Student(string n, string addr, Date d, string id) {
        name = n;
        address = addr;
        birthdate = d;
        cccd = id;
    }

    // ==================================================
    // NHAP THONG TIN SINH VIEN
    // ==================================================
    void setStudentInfo() {
        cout << "Nhap ho ten: ";
        getline(cin, name);

        cout << "Nhap dia chi: ";
        getline(cin, address);

        cout << "Nhap ngay gio sinh:" << endl;
        birthdate.input();

        cout << "Nhap CCCD: ";
        getline(cin, cccd);
    }

    // ==================================================
    // XUAT THONG TIN SINH VIEN
    // ==================================================
    void displayStudentInfo() const {
        cout << "==============================" << endl;
        cout << "       STUDENT INFO" << endl;
        cout << "==============================" << endl;

        cout << "Name     : " << name << endl;
        cout << "Address  : " << address << endl;

        cout << "Birthdate: ";
        birthdate.display();
        cout << endl;

        cout << "CCCD     : " << cccd << endl;

        cout << "Age      : " << getAge() << endl;

        cout << "------------------------------" << endl;
    }

    // ==================================================
    // GETTER
    // ==================================================
    string getName() const {
        return name;
    }

    string getAddress() const {
        return address;
    }

    Date getBirthdate() const {
        return birthdate;
    }

    string getCccd() const {
        return cccd;
    }

    // ==================================================
    // TINH TUOI
    // ==================================================
    int getAge(int currentYear = 2026) const {
        return currentYear - birthdate.getYear();
    }
};

// ======================================================
// TIM SINH VIEN THEO CCCD
// ======================================================
Student getStudent(Student list[], int n, string cccd) {

    for (int i = 0; i < n; i++) {

        if (list[i].getCccd() == cccd) {
            return list[i];
        }
    }

    return Student();
}

// ======================================================
// LAY THONG TIN SINH VIEN THEO CCCD
// ======================================================
Student getStudentInfo(Student list[], int n, string cccd) {
    return getStudent(list, n, cccd);
}

// ======================================================
// TIM SINH VIEN THEO TEN
// ======================================================
Student* getStudents(
    Student list[],
    int n,
    string name,
    int &count
) {
    count = 0;

    string searchName = toLower(name);

    // Dem so sinh vien
    for (int i = 0; i < n; i++) {

        string studentName = toLower(list[i].getName());

        if (studentName.find(searchName) != string::npos) {
            count++;
        }
    }

    if (count == 0) {
        return nullptr;
    }

    // Tao mang ket qua
    Student* result = new Student[count];

    int index = 0;

    for (int i = 0; i < n; i++) {

        string studentName = toLower(list[i].getName());

        if (studentName.find(searchName) != string::npos) {
            result[index] = list[i];
            index++;
        }
    }

    return result;
}

// ======================================================
// TIM SINH VIEN THEO TUOI
// ======================================================
Student* getStudentsbyAge(
    Student list[],
    int n,
    int age,
    int &count,
    int currentYear = 2026
) {
    count = 0;

    // Dem so sinh vien
    for (int i = 0; i < n; i++) {

        if (list[i].getAge(currentYear) == age) {
            count++;
        }
    }

    if (count == 0) {
        return nullptr;
    }

    // Tao mang ket qua
    Student* result = new Student[count];

    int index = 0;

    for (int i = 0; i < n; i++) {

        if (list[i].getAge(currentYear) == age) {
            result[index] = list[i];
            index++;
        }
    }

    return result;
}

// ======================================================
// MAIN
// ======================================================
int main() {

    // ==================================================
    // TAO SINH VIEN
    // ==================================================

    Student student1;

    Student student2("huong");

    Student student3(
        "",
        "vo van ngan"
    );

    Student student4(
        "Nguyen Van An",
        "123 Vo Van Ngan",
        Date(2004, 5, 15, 8, 30, 0),
        "079204001234"
    );

    Student student5(
        "Tran Thi Huong",
        "Thu Duc",
        Date(2004, 9, 20, 14, 0, 0),
        "079204005678"
    );

    // ==================================================
    // TAO MANG SINH VIEN
    // ==================================================

    Student students[100];

    int n = 5;

    students[0] = student1;
    students[1] = student2;
    students[2] = student3;
    students[3] = student4;
    students[4] = student5;

    // ==================================================
    // HIEN THI DANH SACH
    // ==================================================

    cout << "========================================" << endl;
    cout << "   DANH SACH SINH VIEN BAN DAU" << endl;
    cout << "========================================" << endl;

    for (int i = 0; i < n; i++) {

        cout << endl;
        cout << "Sinh vien " << i + 1 << ":" << endl;

        students[i].displayStudentInfo();
    }

    // ==================================================
    // TIM THEO CCCD
    // ==================================================

    cout << endl;
    cout << "========================================" << endl;
    cout << "   TIM SINH VIEN THEO CCCD" << endl;
    cout << "========================================" << endl;

    Student foundByCccd =
        getStudent(
            students,
            n,
            "079204001234"
        );

    if (!foundByCccd.getCccd().empty()) {

        cout << "Tim thay sinh vien:" << endl;

        foundByCccd.displayStudentInfo();

    } else {

        cout << "Khong tim thay sinh vien!" << endl;
    }

    // ==================================================
    // TIM THEO TEN
    // ==================================================

    cout << endl;
    cout << "========================================" << endl;
    cout << "   TIM SINH VIEN THEO TEN" << endl;
    cout << "========================================" << endl;

    int countName = 0;

    Student* foundByName =
        getStudents(
            students,
            n,
            "huong",
            countName
        );

    if (foundByName != nullptr) {

        cout << "So sinh vien tim thay: "
             << countName << endl;

        for (int i = 0; i < countName; i++) {
            foundByName[i].displayStudentInfo();
        }

        delete[] foundByName;

    } else {

        cout << "Khong tim thay sinh vien nao!" << endl;
    }

    // ==================================================
    // TIM THEO TUOI
    // ==================================================

    cout << endl;
    cout << "========================================" << endl;
    cout << "   TIM SINH VIEN THEO TUOI" << endl;
    cout << "========================================" << endl;

    int countAge = 0;

    Student* foundByAge =
        getStudentsbyAge(
            students,
            n,
            22,
            countAge
        );

    if (foundByAge != nullptr) {

        cout << "So sinh vien 22 tuoi: "
             << countAge << endl;

        for (int i = 0; i < countAge; i++) {
            foundByAge[i].displayStudentInfo();
        }

        delete[] foundByAge;

    } else {

        cout << "Khong tim thay sinh vien nao!" << endl;
    }

    return 0;
}