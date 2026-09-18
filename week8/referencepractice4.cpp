#include <iostream>
using namespace std;

int main()
{
    int n = 7;

    // r là reference của n
    int& r = n;

    // Thay đổi n thông qua reference r
    r = 15;

    cout << n << " " << r << endl;

    return 0;
}