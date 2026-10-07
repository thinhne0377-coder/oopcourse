#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

// =====================================================
// HÀM CHUYỂN CHUỖI VỀ CHỮ THƯỜNG
// =====================================================
string toLower(string s) {
    for (size_t i = 0; i < s.length(); i++) {
        s[i] = tolower((unsigned char)s[i]);
    }
    return s;
}

// =====================================================
// CLASS DATE
// =====================================================
class Date {
private:
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;

public:

    // Constructor mặc định
    Date() {
        year = 2000;
        month = 1;
        day = 1;
        hour = 0;
        minute = 0;
        second = 0;
    }

    // Constructor có tham số
    Date(int y, int m, int d, int h = 0, int mi = 0, int s = 0) {
        year = y;
        month = m;
        day = d;
        hour = h;
        minute = mi;
        second = s;
    }

    // Nhập Date
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

        cin.ignore(1000, '\n');
    }

    // Xuất Date
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
    // CONSTRUCTOR 1
    // Student()
    // =================================================
    Student() {
        name = "";
        address = "";
        birthdate = Date();
        cccd = "";
    }

    // =================================================
    // CONSTRUCTOR 2
    // Student(string n)
    // =================================================
    Student(string n) {
        name = n;
        address = "";
        birthdate = Date();
        cccd = "";
    }

    // =================================================
    // CONSTRUCTOR 3
    // Student(Date d)
    // =================================================
    Student(Date d) {
        name = "";
        address = "";
        birthdate = d;
        cccd = "";
    }

    // =================================================
    // CONSTRUCTOR 4
    // Student(string name, string address)
    // =================================================
    Student(string n, string a) {
        name = n;
        address = a;
        birthdate = Date();
        cccd = "";
    }

    // =================================================
    // CONSTRUCTOR 5
    // Student(string name, string address, Date birthdate)
    // =================================================
    Student(string n, string a, Date d) {
        name = n;
        address = a;
        birthdate = d;
        cccd = "";
    }

    // =================================================
    // CONSTRUCTOR 6
    // Student(string name, string address,
    //          Date birthdate, string cccd)
    // =================================================
    Student(string n, string a, Date d, string id) {
        name = n;
        address = a;
        birthdate = d;
        cccd = id;
    }

    // =================================================
    // SET STUDENT INFO
    // =================================================
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

    // =================================================
    // GET STUDENT THEO CCCD
    // =================================================
    Student getStudent(string id) {

        if (cccd == id) {
            return *this;
        }

        return Student();
    }

    // =================================================
    // GET STUDENT INFO THEO CCCD
    // =================================================
    Student getStudentInfo(string id) {

        return getStudent(id);
    }

    // =================================================
    // GET STUDENTS THEO NAME
    // =================================================
    vector<Student> getStudents(
        vector<Student> list,
        string searchName
    ) {

        vector<Student> result;

        searchName = toLower(searchName);

        for (int i = 0; i < list.size(); i++) {

            string studentName =
                toLower(list[i].getName());

            if (studentName.find(searchName)
                != string::npos) {

                result.push_back(list[i]);
            }
        }

        return result;
    }

    // =================================================
    // GET STUDENTS THEO AGE
    // =================================================
    vector<Student> getStudentsbyAge(
        vector<Student> list,
        int age
    ) {

        vector<Student> result;

        for (int i = 0; i < list.size(); i++) {

            if (list[i].getAge() == age) {
                result.push_back(list[i]);
            }
        }

        return result;
    }

    // =================================================
    // GETTERS
    // =================================================
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

    // =================================================
    // TÍNH TUỔI
    // =================================================
    int getAge(int currentYear = 2026) const {
        return currentYear - birthdate.getYear();
    }

    // =================================================
    // DISPLAY
    // =================================================
    void displayStudentInfo() const {

        cout << "Ho ten   : " << name << endl;
        cout << "Dia chi  : " << address << endl;

        cout << "Ngay sinh: ";
        birthdate.display();
        cout << endl;

        cout << "CCCD     : " << cccd << endl;

        cout << "----------------------------------------"
             << endl;
    }
};

// =====================================================
// HÀM MAIN
// =====================================================
int main() {

    // =================================================
    // 1. TẠO STUDENT THEO CÁC CONSTRUCTOR
    // =================================================

    // Student()
    Student student1;

    // Student(string)
    Student student2("Huong");

    // Student(string, string)
    Student student3("", "Vo Van Ngan");

    // Student(Date)
    Student student4(
        Date(2004, 5, 15, 8, 30, 0)
    );

    // Student(string, string, Date)
    Student student5(
        "Nguyen Van An",
        "123 Vo Van Ngan",
        Date(2004, 5, 15, 8, 30, 0)
    );

    // Student(string, string, Date, string)
    Student student6(
        "Tran Thi Huong",
        "Thu Duc",
        Date(2004, 9, 20, 14, 0, 0),
        "079204005678"
    );

    // =================================================
    // 2. TẠO DANH SÁCH SINH VIÊN
    // =================================================

    vector<Student> students;

    students.push_back(student1);
    students.push_back(student2);
    students.push_back(student3);
    students.push_back(student4);
    students.push_back(student5);
    students.push_back(student6);

    // =================================================
    // 3. HIỂN THỊ DANH SÁCH
    // =================================================

    cout << "========================================"
         << endl;
    cout << "       DANH SACH SINH VIEN"
         << endl;
    cout << "========================================"
         << endl;

    for (int i = 0; i < students.size(); i++) {

        cout << "\nSinh vien " << i + 1 << ":\n";

        students[i].displayStudentInfo();
    }

    // =================================================
    // 4. GET STUDENT THEO CCCD
    // =================================================

    cout << "\n========================================"
         << endl;
    cout << "       GET STUDENT THEO CCCD"
         << endl;
    cout << "========================================"
         << endl;

    string cccdSearch = "079204005678";

    Student found;

    for (int i = 0; i < students.size(); i++) {

        Student temp =
            students[i].getStudent(cccdSearch);

        if (!temp.getCccd().empty()) {
            found = temp;
            break;
        }
    }

    if (!found.getCccd().empty()) {

        cout << "Tim thay sinh vien:\n";

        found.displayStudentInfo();

    }
    else {

        cout << "Khong tim thay sinh vien!\n";
    }

    // =================================================
    // 5. GET STUDENT INFO THEO CCCD
    // =================================================

    cout << "\n========================================"
         << endl;
    cout << "       GET STUDENT INFO"
         << endl;
    cout << "========================================"
         << endl;

    Student result;

    for (int i = 0; i < students.size(); i++) {

        Student temp =
            students[i].getStudentInfo(
                "079204001234"
            );

        if (!temp.getCccd().empty()) {
            result = temp;
            break;
        }
    }

    if (!result.getCccd().empty()) {

        result.displayStudentInfo();

    }
    else {

        cout << "Khong tim thay sinh vien!\n";
    }

    // =================================================
    // 6. GET STUDENTS THEO NAME
    // =================================================

    cout << "\n========================================"
         << endl;
    cout << "       GET STUDENTS THEO TEN"
         << endl;
    cout << "========================================"
         << endl;

    vector<Student> resultByName;

    // Dùng student1 gọi method tìm kiếm
    resultByName =
        student1.getStudents(
            students,
            "huong"
        );

    if (resultByName.size() > 0) {

        cout << "Tim thay "
             << resultByName.size()
             << " sinh vien:\n\n";

        for (int i = 0; i < resultByName.size(); i++) {

            resultByName[i].displayStudentInfo();
        }

    }
    else {

        cout << "Khong tim thay sinh vien!\n";
    }

    // =================================================
    // 7. GET STUDENTS THEO AGE
    // =================================================

    cout << "\n========================================"
         << endl;
    cout << "       GET STUDENTS THEO TUOI"
         << endl;
    cout << "========================================"
         << endl;

    vector<Student> resultByAge;

    resultByAge =
        student1.getStudentsbyAge(
            students,
            22
        );

    if (resultByAge.size() > 0) {

        cout << "Tim thay "
             << resultByAge.size()
             << " sinh vien 22 tuoi:\n\n";

        for (int i = 0; i < resultByAge.size(); i++) {

            resultByAge[i].displayStudentInfo();
        }

    }
    else {

        cout << "Khong tim thay sinh vien!\n";
    }

    return 0;
}