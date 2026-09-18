#include <iostream>
using namespace std;

// Function swap hai giá trị sử dụng reference
void swapValues(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

int main()
{
    // Khai báo hai biến
    int a = 5;
    int b = 10;

    // Hiển thị trước khi swap
    cout << "Before: a = " << a << ", b = " << b << endl;

    // Gọi function swap
    swapValues(a, b);

    // Hiển thị sau khi swap
    cout << "After: a = " << a << ", b = " << b << endl;

    return 0;
}