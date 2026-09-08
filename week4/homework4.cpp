#include <iostream>
using namespace std;

int main() {
    int n, temp, dao = 0;

    cout << "Nhap n: ";
    cin >> n;

    temp = n;

    while (temp > 0) {
        int chuSo = temp % 10;
        dao = dao * 10 + chuSo;
        temp /= 10;
    }

    if (dao == n)
        cout << n << " la so doi xung";
    else
        cout << n << " khong phai la so doi xung";

    return 0;
}