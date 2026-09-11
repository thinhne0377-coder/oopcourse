#include <iostream>
using namespace std;

// Ham tim so lon hon
int maxValue(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{
    // Khai bao 2 bien
    int a, b;

    // Nhap a
    cout << "Nhap so a: ";
    cin >> a;

    // Nhap b
    cout << "Nhap so b: ";
    cin >> b;

    // Goi ham maxValue va luu ket qua
    int max = maxValue(a, b);

    // In ket qua
    cout << "So lon hon la: " << max << endl;

    return 0;
}