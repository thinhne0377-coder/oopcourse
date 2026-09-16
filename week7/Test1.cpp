#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <utility>

using namespace std;

// =====================================================
// STRUCT USER
// =====================================================
struct User
{
    string username;
    string pwd;
};

// =====================================================
// STRUCT COMPUTER
// =====================================================
struct Computer
{
    string id;
    string name;
    string os;
    User user;
    string model;
    int year;
};

// =====================================================
// STRUCT LAB
// =====================================================
struct Lab
{
    string roomCode;
    string function;
};

// =====================================================
// 1. NHAP THONG TIN LAB VA COMPUTER
// =====================================================
void inputLabAndComputers(Lab &lab, Computer computers[], int &n)
{
    cout << "========================================\n";
    cout << "          INPUT LAB INFORMATION\n";
    cout << "========================================\n";

    cout << "Enter Room Code: ";
    getline(cin >> ws, lab.roomCode);

    cout << "Enter Lab Function: ";
    getline(cin >> ws, lab.function);

    // Nhap so luong Computer
    do
    {
        cout << "\nEnter number of computers (1 <= N <= 20): ";
        cin >> n;

        if (n < 1 || n > 20)
        {
            cout << "Invalid number! Please enter from 1 to 20.\n";
        }

    } while (n < 1 || n > 20);

    // Nhap thong tin Computer
    for (int i = 0; i < n; i++)
    {
        cout << "\n========================================\n";
        cout << " Enter information for Computer "
             << i + 1 << "\n";
        cout << "========================================\n";

        cout << "ID: ";
        getline(cin >> ws, computers[i].id);

        cout << "Name: ";
        getline(cin >> ws, computers[i].name);

        cout << "OS: ";
        getline(cin >> ws, computers[i].os);

        cout << "Username: ";
        getline(cin >> ws, computers[i].user.username);

        cout << "Password: ";
        getline(cin >> ws, computers[i].user.pwd);

        cout << "Model: ";
        getline(cin >> ws, computers[i].model);

        cout << "Year: ";
        cin >> computers[i].year;
    }
}

// =====================================================
// HIEN THI THONG TIN LAB
// =====================================================
void showLabInfo(const Lab &lab)
{
    cout << "\n========================================\n";
    cout << "             LAB INFORMATION\n";
    cout << "========================================\n";

    cout << "Room Code : " << lab.roomCode << endl;
    cout << "Function  : " << lab.function << endl;
}

// =====================================================
// HAM HIEN THI 1 COMPUTER
// =====================================================
void printComputer(const Computer &c)
{
    cout << "\n----------------------------------------\n";
    cout << "ID       : " << c.id << endl;
    cout << "Name     : " << c.name << endl;
    cout << "OS       : " << c.os << endl;
    cout << "Username : " << c.user.username << endl;
    cout << "Password : " << c.user.pwd << endl;
    cout << "Model    : " << c.model << endl;
    cout << "Year     : " << c.year << endl;
    cout << "----------------------------------------\n";
}

// =====================================================
// 2. Computer getComputerById(id)
//
// Tim Computer theo ID
//
// Neu tim thay:
//      return computer
//
// Neu khong tim thay:
//      return Computer rong
// =====================================================
Computer getComputerById(
    Computer computers[],
    int n,
    string id)
{
    for (int i = 0; i < n; i++)
    {
        if (computers[i].id == id)
        {
            return computers[i];
        }
    }

    // Khong tim thay
    Computer emptyComputer;
    emptyComputer.id = "";

    return emptyComputer;
}

// =====================================================
// 1. void getComputerInfo(id)
//
// Tim Computer theo ID va IN thong tin
// =====================================================
void getComputerInfo(
    Computer computers[],
    int n,
    string id)
{
    Computer c = getComputerById(computers, n, id);

    if (c.id == "")
    {
        cout << "\nComputer with ID = " << id
             << " not found!\n";
        return;
    }

    cout << "\n========================================\n";
    cout << "          COMPUTER INFORMATION\n";
    cout << "========================================\n";

    printComputer(c);
}

// =====================================================
// 3. Computer[] getComputers(x)
//
// Trong C++ khong the viet:
// Computer[] getComputers()
//
// Ta dung vector<Computer> de thay cho Computer[]
//
// O day x la YEAR.
// Lay tat ca Computer co year == x.
// =====================================================
vector<Computer> getComputers(
    Computer computers[],
    int n,
    int x)
{
    vector<Computer> result;

    for (int i = 0; i < n; i++)
    {
        if (computers[i].year == x)
        {
            result.push_back(computers[i]);
        }
    }

    return result;
}

// =====================================================
// 4. getOsAndPwd(id)
//
// Lay OS va Password cua Computer theo ID
//
// pair<string, string>
// first  = OS
// second = Password
// =====================================================
pair<string, string> getOsAndPwd(
    Computer computers[],
    int n,
    string id)
{
    Computer c = getComputerById(computers, n, id);

    if (c.id == "")
    {
        return make_pair("", "");
    }

    return make_pair(c.os, c.user.pwd);
}

// =====================================================
// HIEN THI DANH SACH COMPUTER
// =====================================================
void showAllComputers(
    Computer computers[],
    int n)
{
    cout << "\n========================================\n";
    cout << "             COMPUTER LIST\n";
    cout << "========================================\n";

    for (int i = 0; i < n; i++)
    {
        cout << "\nComputer " << i + 1 << ":";
        printComputer(computers[i]);
    }
}

// =====================================================
// MAIN
// =====================================================
int main()
{
    Lab lab;
    Computer computers[20];
    int n = 0;

    // -------------------------------------------------
    // NHAP DU LIEU
    // -------------------------------------------------
    inputLabAndComputers(lab, computers, n);

    // -------------------------------------------------
    // HIEN THI THONG TIN LAB
    // -------------------------------------------------
    showLabInfo(lab);

    // -------------------------------------------------
    // HIEN THI TAT CA COMPUTER
    // -------------------------------------------------
    showAllComputers(computers, n);

    // =================================================
    // TEST FUNCTION 1
    // void getComputerInfo(id)
    // =================================================
    string searchId;

    cout << "\n========================================\n";
    cout << "        1. GET COMPUTER INFO\n";
    cout << "========================================\n";

    cout << "Enter Computer ID: ";
    getline(cin >> ws, searchId);

    getComputerInfo(computers, n, searchId);

    // =================================================
    // TEST FUNCTION 2
    // Computer getComputerById(id)
    // =================================================
    cout << "\n========================================\n";
    cout << "        2. GET COMPUTER BY ID\n";
    cout << "========================================\n";

    Computer c = getComputerById(
        computers,
        n,
        searchId
    );

    if (c.id == "")
    {
        cout << "Computer not found!\n";
    }
    else
    {
        cout << "Computer found:\n";
        printComputer(c);
    }

    // =================================================
    // TEST FUNCTION 3
    // Computer[] getComputers(x)
    // =================================================
    int year;

    cout << "\n========================================\n";
    cout << "        3. GET COMPUTERS BY YEAR\n";
    cout << "========================================\n";

    cout << "Enter year: ";
    cin >> year;

    vector<Computer> result =
        getComputers(computers, n, year);

    if (result.empty())
    {
        cout << "No computer found in year "
             << year << ".\n";
    }
    else
    {
        cout << "\nComputers in year "
             << year << ":\n";

        for (int i = 0; i < result.size(); i++)
        {
            printComputer(result[i]);
        }
    }

    // =================================================
    // TEST FUNCTION 4
    // getOsAndPwd(id)
    // =================================================
    cout << "\n========================================\n";
    cout << "        4. GET OS AND PASSWORD\n";
    cout << "========================================\n";

    pair<string, string> info =
        getOsAndPwd(computers, n, searchId);

    if (info.first == "" && info.second == "")
    {
        cout << "Computer not found!\n";
    }
    else
    {
        cout << "OS       : " << info.first << endl;
        cout << "Password : " << info.second << endl;
    }

    return 0;
}