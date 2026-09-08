#include <iostream>
using namespace std;

int main() {
    int n;
    int tong = 0;

    cout << "Nhap n: ";
    cin >> n;

    while (n > 0) {
        int chuSo = n % 10;
        tong += chuSo;
        n /= 10;
    }

    cout << "Tong cac chu so = " << tong;

    return 0;
}