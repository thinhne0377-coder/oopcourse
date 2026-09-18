#include <iostream>
#include <string>

using namespace std;

// =====================================
// FUNCTION NHAP THONG TIN SINH VIEN
// =====================================
void inputStudentInfo(string &fullName,
                      string &studentId,
                      string &email,
                      string &hometown)
{
    cout << "Enter your full name: ";
    getline(cin, fullName);

    cout << "Enter your student ID: ";
    getline(cin, studentId);

    cout << "Enter your email: ";
    getline(cin, email);

    cout << "Enter your hometown: ";
    getline(cin, hometown);
}

// =====================================
// FUNCTION XUAT THONG TIN SINH VIEN
// =====================================
void outputStudentInfo(const string &fullName,
                       const string &studentId,
                       const string &email,
                       const string &hometown)
{
    cout << "\n===== STUDENT PROFILE =====\n";

    cout << "Full name  : " << fullName << endl;
    cout << "Student ID : " << studentId << endl;
    cout << "Email      : " << email << endl;
    cout << "Hometown   : " << hometown << endl;

    cout << "===========================\n";
}

// =====================================
// MAIN
// =====================================
int main()
{
    // Khai bao bien
    string fullName;
    string studentId;
    string email;
    string hometown;

    // Goi function nhap
    inputStudentInfo(fullName, studentId, email, hometown);

    // Goi function xuat
    outputStudentInfo(fullName, studentId, email, hometown);

    return 0;
}