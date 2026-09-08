#include <iostream>
using namespace std;
// đếm số lượng ước của n
int dem_uoc(int n);

int main()
{
    int n;
   
     do {
        cout << "Nhap so n: "; cin >> n;
        if (n<=0) cout <<"Vui long nhap so duong" << endl;
    } while (n<=0);

    cout << "so luong uoc cua n: " << dem_uoc(n) << endl;
    return 0;
}

int dem_uoc(int n)
{
    int dem=0;
    for (int i=1;i<=n;i++)
    {
        if(n%i==0) dem++;
    }

    return dem;
}