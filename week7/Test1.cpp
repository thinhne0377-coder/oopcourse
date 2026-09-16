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
// FUNCTION NHAP 1 COMPUTER

void nhapComputer(Computer &c)
{
    cout << "Nhap ID: ";
    cin >> c.id;
    cin.ignore();

    cout << "Nhap ten may: ";
    getline(cin, c.tenMay);

    cout << "Nhap HDH: ";
    getline(cin, c.hdh);

    cout << "Nhap username: ";
    getline(cin, c.username);

    cout << "Nhap password: ";
    getline(cin, c.pwd);

    cout << "Nhap model: ";
    getline(cin, c.model);

    cout << "Nhap year: ";
    cin >> c.year;
}
// 1. GET COMPUTER BY ID
Computer* getComputerById(Computer ds[], int n, int id)
{
    for (int i = 0; i < n; i++)
    {
        if (ds[i].id == id)
        {
            return &ds[i];
        }
    }

    return nullptr;
}
