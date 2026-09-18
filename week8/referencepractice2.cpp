#include <iostream>
using namespace std;

// Function swap hai gia tri bang Reference
void swapValues(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

int main()
{
    // Khai bao hai bien
    int a = 5;
    int b = 10;

    // Hien thi truoc khi swap
    cout << "Before: a = " << a << ", b = " << b << endl;

    // Goi ham swap
    swapValues(a, b);

    // Hien thi sau khi swap
    cout << "After: a = " << a << ", b = " << b << endl;

    return 0;
}