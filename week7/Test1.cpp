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
// 2. GET COMPUTER BY NAME
Computer* getComputerByName(Computer ds[], int n, string tenMay)
{
    for (int i = 0; i < n; i++)
    {
        if (ds[i].tenMay == tenMay)
        {
            return &ds[i];
        }
    }

    return nullptr;
}
// 3. GET COMPUTERS
void getComputers(Computer ds[], int n, int x)
{
    bool found = false;

    for (int i = 0; i < n; i++)
    {
        if (ds[i].year >= x)
        {
            ds[i].print();
            found = true;
        }
    }

    if (!found)
    {
        cout << "Khong tim thay computer!" << endl;
    }
}
// 4. GET USERNAME AND PASSWORD BY ID
void getUsernameAndPwd(Computer ds[], int n, int id)
{
    Computer* c = getComputerById(ds, n, id);

    if (c != nullptr)
    {
        cout << "Username: " << c->username << endl;
        cout << "Password: " << c->pwd << endl;
    }
    else
    {
        cout << "Khong tim thay Computer co ID = "
             << id << endl;
    }
}
// CLASS LAB
class Lab
{
private:
    string maPhong;

public:

    // Constructor
    Lab(string ma)
    {
        maPhong = ma;
    }

    // showLabInfo()
    void showLabInfo()
    {
        cout << "\n========== LAB ==========" << endl;
        cout << "Ma phong: " << maPhong << endl;
        cout << "Chuc nang: Phong may tinh" << endl;
        cout << "=========================" << endl;
    }
};