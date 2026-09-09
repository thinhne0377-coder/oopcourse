#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // =====================================
    // NHAP SO LUONG HOC SINH
    // =====================================

    int N;

    do {
        cout << "Nhap so luong hoc sinh: ";
        cin >> N;

        if (N < 2 || N > 20) {
            cout << "So luong khong hop le! "
                 << "Vui long nhap tu 2 den 20.\n";
        }

    } while (N < 2 || N > 20);


    // =====================================
    // NHAP DIEM
    // =====================================

            