#include <iostream>
#include <string>

using namespace std;

// ==================================================
// KHAI BAO STRUCT COMPUTER
// ==================================================

struct Computer
{
    int id;
    string tenMay;
    string hdh;
    string username;
    string pwd;
    string model;
    int year;
 // Ham print
    void print()
    {
        cout << "==============================" << endl;
        cout << "ID       : " << id << endl;
        cout << "Ten may  : " << tenMay << endl;
        cout << "HDH      : " << hdh << endl;
        cout << "Username : " << username << endl;
        cout << "Password : " << pwd << endl;
        cout << "Model    : " << model << endl;
        cout << "Year     : " << year << endl;
        cout << "==============================" << endl;
    }
};
