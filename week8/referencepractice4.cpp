#include <iostream>
using namespace std;

// =============================
// BAI 1
// =============================
void bai1() {
    cout << "===== BAI 1 =====" << endl;

    int n = 7;
    int& r = n;

    r = 15;

    cout << n << " " << r << endl;
}

// =============================
// BAI 2
// =============================
void addFive(int& x) {
    x += 5;
}

void bai2() {
    cout << "===== BAI 2 =====" << endl;

    int a = 10;

    addFive(a);

    cout << a << endl;
}

// =============================
// BAI 3
// =============================
void swapValues(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

void bai3() {
    cout << "===== BAI 3 =====" << endl;

    int a = 4;
    int b = 9;

    swapValues(a, b);

    cout << a << " " << b << endl;
}

// =============================
// BAI 4
// =============================
void changeValue(int x) {
    x = 100;
}

void changeRef(int& x) {
    x = 200;
}

void bai4() {
    cout << "===== BAI 4 =====" << endl;

    int a = 5;

    changeValue(a);
    cout << "After changeValue: " << a << endl;

    changeRef(a);
    cout << "After changeRef: " << a << endl;
}

// =============================
// MAIN
// =============================
int main() {
    bai1();
    cout << endl;

    bai2();
    cout << endl;

    bai3();
    cout << endl;

    bai4();

    return 0;
}