#include <iostream>
#include <cmath>
using namespace std;
// tính lũy thùa x mũ n
void tinhluythua(float x, int n);


int main()
{
    float x;
    cout <<"Nhap co so x: "; cin >>x;
    int n;
    cout <<"Nhap so mu n: "; cin >>n;

    tinhluythua(x,n);




    return 0;
}

void tinhluythua(float x, int n)
{
    float tich=1;
    if (x==0 && n==0) 
    {
        cout << "Vo ly" << endl;
        return;
    }

    for (int i=1;i<=n;i++)
    {
        tich=tich*x;
    }

    cout << "luy thua x mu n la: "<< tich;
}