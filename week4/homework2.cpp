#include <iostream>
using namespace std;
//tính n!
long long giaithua(int n);

int main()
{

    int n;

    do {
        cout << "Nhap so n de tinh giai thua: "; cin >> n;
        if (n<=0) cout << "Vui long nhap lai n" << endl;
    } while (n<=0);



    cout << "so can tim: " << giaithua(n) << endl;

    return 0;
}
long long giaithua(int n)
{
    long long giaithua=1;
    for (int i=1;i<=n;i++)
    {
        giaithua=giaithua*i;
    }
    return giaithua;

}