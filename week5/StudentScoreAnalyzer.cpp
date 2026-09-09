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

    double scores[20];

    for (int i = 0; i < N; i++) {

        do {
            cout << "Nhap diem cho hoc sinh "
                 << i + 1 << ": ";

            cin >> scores[i];

            if (scores[i] < 0 || scores[i] > 10) {
                cout << "Diem khong hop le! "
                     << "Vui long nhap tu 0 den 10.\n";
            }

        } while (scores[i] < 0 || scores[i] > 10);
    }


    // =====================================
    // 1. COUNT EXCELLENT STUDENTS
    // =====================================
            