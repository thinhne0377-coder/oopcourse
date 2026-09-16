#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// =====================================
// STRUCT USER
// =====================================
struct User {
    string username;
    string pwd;
};

// =====================================
// STRUCT COMPUTER
// =====================================
struct Computer {
    string id;
    string name;
    string os;
    User user;
    string model;
    int year;
};

// =====================================
// STRUCT LAB
// =====================================
struct Lab {
    string roomCode;
    string function;
};

// =====================================
// NHAP THONG TIN LAB VA COMPUTER
// =====================================
void inputLabAndComputers(Lab &lab, Computer computers[], int &n)
{
    cout << "=== INPUT LAB INFO ===\n";

    cout << "Enter Room Code: ";
    getline(cin, lab.roomCode);

    cout << "Enter Lab Function: ";
    getline(cin, lab.function);

    // Nhap so luong may tinh
    do {
        cout << "\nEnter number of computers (1 <= N <= 20): ";
        cin >> n;

        if (n < 1 || n > 20) {
            cout << "Invalid number! Please enter from 1 to 20.\n";
        }

    } while (n < 1 || n > 20);

    cin.ignore();

    // Nhap thong tin computer
    for (int i = 0; i < n; i++)
    {
        cout << "\n--- Enter info for Computer "
             << i + 1 << " ---\n";

        cout << "ID: ";
        getline(cin, computers[i].id);

        cout << "Name: ";
        getline(cin, computers[i].name);

        cout << "OS: ";
        getline(cin, computers[i].os);

        cout << "Username: ";
        getline(cin, computers[i].user.username);

        cout << "Password: ";
        getline(cin, computers[i].user.pwd);

        cout << "Model: ";
        getline(cin, computers[i].model);

        cout << "Year: ";
        cin >> computers[i].year;

        cin.ignore();
    }
}

// =====================================
// HIEN THI THONG TIN LAB
// =====================================
void showLabInfo(const Lab &lab)
{
    cout << "\n=== LAB INFORMATION ===\n";

    cout << "Room Code: " << lab.roomCode << endl;
    cout << "Function : " << lab.function << endl;
}

// =====================================
// 1) void getComputerInfo(id)
// Tim va in thong tin Computer theo ID
// =====================================
void getComputerInfo(
    const Computer computers[],
    int n,
    string targetId)
{
    bool found = false;

    for (int i = 0; i < n; i++)
    {
        if (computers[i].id == targetId)
        {
            cout << "\n=== COMPUTER INFORMATION ===\n";

            cout << "ID       : " << computers[i].id << endl;
            cout << "Name     : " << computers[i].name << endl;
            cout << "OS       : " << computers[i].os << endl;
            cout << "Username : " << computers[i].user.username << endl;
            cout << "Password : " << computers[i].user.pwd << endl;
            cout << "Model    : " << computers[i].model << endl;
            cout << "Year     : " << computers[i].year << endl;

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nComputer with ID '"
             << targetId
             << "' not found.\n";
    }
}

// =====================================
// 2) Computer getComputerById(id)
// Tim va TRA VE doi tuong Computer
// =====================================
Computer getComputerById(
    const Computer computers[],
    int n,
    string targetId)
{
    for (int i = 0; i < n; i++)
    {
        if (computers[i].id == targetId)
        {
            return computers[i];
        }
    }

    // Khong tim thay
    return Computer{
        "",
        "N/A",
        "N/A",
        {"N/A", "N/A"},
        "N/A",
        0
    };
}

// =====================================
// 3) Computer[] getComputers()
// Tra ve con tro den mang Computer
// =====================================
const Computer* getComputers(
    const Computer computers[])
{
    return computers;
}

// =====================================
// 4) getUserAndPwd(id)
// Lay User gom username + password
// thong qua ID Computer
// =====================================
User getUserAndPassword(
    const Computer computers[],
    int n,
    string targetId)
{
    for (int i = 0; i < n; i++)
    {
        if (computers[i].id == targetId)
        {
            return computers[i].user;
        }
    }

    // Khong tim thay
    return User{"N/A", "N/A"};
}

// =====================================
// MAIN
// =====================================
int main()
{
    Lab lab;

    Computer computers[20];

    int n = 0;

    // =================================
    // NHAP DU LIEU
    // =================================
    inputLabAndComputers(lab, computers, n);

    // =================================
    // HIEN THI LAB
    // =================================
    showLabInfo(lab);

    // =================================
    // 1) getComputerInfo(id)
    // =================================
    string searchId;

    cout << "\nEnter Computer ID to print info: ";
    getline(cin, searchId);

    getComputerInfo(
        computers,
        n,
        searchId
    );

    // =================================
    // 2) getComputerById(id)
    // =================================
    cout << "\nEnter Computer ID to return Computer object: ";
    getline(cin, searchId);

    Computer comp =
        getComputerById(
            computers,
            n,
            searchId
        );

    cout << "\n=== RETURNED COMPUTER OBJECT ===\n";

    cout << "ID    : " << comp.id << endl;
    cout << "Name  : " << comp.name << endl;
    cout << "OS    : " << comp.os << endl;
    cout << "Model : " << comp.model << endl;
    cout << "Year  : " << comp.year << endl;

    // =================================
    // 3) getComputers()
    // =================================
    cout << "\n=== ALL COMPUTERS ===\n";

    const Computer* list =
        getComputers(computers);

    for (int i = 0; i < n; i++)
    {
        cout << i + 1
             << ". ID: " << list[i].id
             << " | Name: " << list[i].name
             << " | OS: " << list[i].os
             << endl;
    }

    // =================================
    // 4) getUserAndPassword(id)
    // =================================
    cout << "\nEnter Computer ID to get Username & Password: ";
    getline(cin, searchId);

    User u =
        getUserAndPassword(
            computers,
            n,
            searchId
        );

    cout << "\n=== USER INFORMATION ===\n";

    cout << "Username : " << u.username << endl;
    cout << "Password : " << u.pwd << endl;

    return 0;
}