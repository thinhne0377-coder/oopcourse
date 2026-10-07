#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// ======================================================
// HAM CHUYEN CHUOI VE CHU THUONG
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

    // Nhap Date
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

    // Xuat Date
    void display() const {
        cout << year << "/";

        if (month < 10)
            cout << "0";
        cout << month << "/";

        if (day < 10)
            cout << "0";
        cout << day << " ";

        if (hour < 10)
            cout << "0";
        cout << hour << ":";

        if (minute < 10)
            cout << "0";
        cout << minute << ":";

        if (second < 10)
            cout << "0";
        cout << second;
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
    // CAC CONSTRUCTOR
    // ==================================================

    // 1. Constructor mac dinh
    Student() {
        name = "";
        address = "";
        birthdate = Date();
        cccd = "";
    }

    // 2. Constructor voi name
    Student(string n) {
        name = n;
        address = "";
        birthdate = Date();
        cccd = "";
    }

    // 3. Constructor voi Date
    Student(Date d) {
        name = "";
        address = "";
        birthdate = d;
        cccd = "";
    }

    // 4. Constructor voi name + address
    Student(string name, string address) {
        this->name = name;
        this->address = address;
        birthdate = Date();
        cccd = "";
    }

    // 5. Constructor voi name + address + birthdate
    Student(string name, string address, Date birthdate) {
        this->name = name;
        this->address = address;
        this->birthdate = birthdate;
        cccd = "";
    }

    // 6. Constructor day du
    Student(string name, string address, Date birthdate, string cccd) {
        this->name = name;
        this->address = address;
        this->birthdate = birthdate;
        this->cccd = cccd;
    }

    // ==================================================
    // NHAP THONG TIN SINH VIEN
    // ==================================================
    void setStudentInfo() {
        cout << "Nhap ho ten: ";
        getline(cin, name);

        cout << "Nhap dia chi: ";
        getline(cin, address);

        cout << "Nhap ngay gio sinh:\n";
        birthdate.input();

        cout << "Nhap CCCD: ";
        getline(cin, cccd);
    }

    // ==================================================
    // XUAT THONG TIN SINH VIEN
    // ==================================================
    void displayStudentInfo() const {
        cout << "Ho ten   : " << name << endl;
        cout << "Dia chi  : " << address << endl;

        cout << "Ngay sinh: ";
        birthdate.display();
        cout << endl;

        cout << "CCCD     : " << cccd << endl;

        cout << "----------------------------------------" << endl;
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

    // Khong tim thay
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

    string keyword = toLower(name);

    // Dem so sinh vien tim thay
    for (int i = 0; i < n; i++) {
        string studentName = toLower(list[i].getName());

        if (studentName.find(keyword) != string::npos) {
            count++;
        }
    }

    if (count == 0) {
        return nullptr;
    }

    // Cap phat mang ket qua
    Student* result = new Student[count];

    int index = 0;

    for (int i = 0; i < n; i++) {
        string studentName = toLower(list[i].getName());

        if (studentName.find(keyword) != string::npos) {
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

    // Cap phat mang ket qua
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
    // TAO CAC DOI TUONG STUDENT
    // ==================================================

    Student student1;

    Student student2("huong");

    Student student3("", "vo van ngan");

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
    // HIEN THI DANH SACH SINH VIEN
    // ==================================================

    cout << "==========================================" << endl;
    cout << "     DANH SACH SINH VIEN BAN DAU" << endl;
    cout << "==========================================" << endl;

    for (int i = 0; i < n; i++) {
        cout << "\nSinh vien " << i + 1 << ":" << endl;
        students[i].displayStudentInfo();
    }

    // ==================================================
    // TIM THEO CCCD
    // ==================================================

    cout << "\n==========================================" << endl;
    cout << "     TIM SINH VIEN THEO CCCD" << endl;
    cout << "==========================================" << endl;

    string cccdSearch = "079204001234";

    Student foundByCccd =
        getStudent(students, n, cccdSearch);

    if (!foundByCccd.getCccd().empty()) {
        cout << "Tim thay sinh vien:\n";
        foundByCccd.displayStudentInfo();
    }
    else {
        cout << "Khong tim thay sinh vien!" << endl;
    }

    // ==================================================
    // TIM THEO TEN
    // ==================================================

    cout << "\n==========================================" << endl;
    cout << "     TIM SINH VIEN THEO TEN" << endl;
    cout << "==========================================" << endl;

    string nameSearch = "huong";

    int countName = 0;

    Student* foundByName =
        getStudents(
            students,
            n,
            nameSearch,
            countName
        );

    if (foundByName != nullptr) {

        cout << "So sinh vien tim thay: "
             << countName << endl;

        for (int i = 0; i < countName; i++) {
            foundByName[i].displayStudentInfo();
        }

        delete[] foundByName;
    }
    else {
        cout << "Khong tim thay sinh vien nao!" << endl;
    }

    // ==================================================
    // TIM THEO TUOI
    // ==================================================

    cout << "\n==========================================" << endl;
    cout << "     TIM SINH VIEN THEO TUOI" << endl;
    cout << "==========================================" << endl;

    int ageSearch = 22;

    int countAge = 0;

    Student* foundByAge =
        getStudentsbyAge(
            students,
            n,
            ageSearch,
            countAge
        );

    if (foundByAge != nullptr) {

        cout << "So sinh vien "
             << ageSearch
             << " tuoi: "
             << countAge << endl;

        for (int i = 0; i < countAge; i++) {
            foundByAge[i].displayStudentInfo();
        }

        delete[] foundByAge;
    }
    else {
        cout << "Khong tim thay sinh vien nao!" << endl;
    }

    return 0;
}