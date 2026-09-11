#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ==================================================
// STEP 1: Function without parameters and return value
// ==================================================

void showMenu() {
    cout << "\n===== STEP 1: SHOW MENU =====" << endl;
    cout << "==== MENU ====" << endl;
    cout << "1. Display students" << endl;
    cout << "2. Show statistics" << endl;
    cout << "3. Exit" << endl;
    cout << "==============" << endl;
}
// ==================================================
// STEP 2: Function with one parameter, no return value
// ==================================================

void showStudentID(int id) {
    cout << "\n===== STEP 2: SHOW STUDENT ID =====" << endl;
    cout << "Student ID: " << id << endl;
}
// ==================================================
// STEP 3: Function with multiple parameters, no return value
// ==================================================

void printStudentInfo(string name, int id) {
    cout << "\n===== STEP 3: STUDENT INFORMATION =====" << endl;
    cout << "------------------------" << endl;
    cout << "Name : " << name << endl;
    cout << "ID   : " << id << endl;
    cout << "------------------------" << endl;
}
