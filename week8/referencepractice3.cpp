#include <iostream>
using namespace std;

int main()
{
    int a = 5;

    // r là reference (tham chiếu) đến a
    int& r = a;

    // Thay đổi giá trị của a thông qua reference r
    r = 10;

    // In giá trị của a
    cout << a << endl;

    // In giá trị của r
    cout << r << endl;

    return 0;
}