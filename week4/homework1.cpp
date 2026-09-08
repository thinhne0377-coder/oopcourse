#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
//tìm số lớn nhất trong 3 số a,b,c

int max_num(int a, int b, int c);

int main()
{
    int a,b,c;
    cout << "Nhap 3 so a,b,c: ";
    cin >> a >> b >> c;
    cout << endl;
    
    cout << "So lon nhat trong 3 so la: " << max_num(a,b,c);
    return 0;
}

int max_num(int a, int b, int c)
{
    int max1=a;
    int max2=b;

    if (a<b)
    {
        max1=b; max2=a;
    }
    
    if (max1 < c)
    {
        max1=c;
    }
    return max1;
}