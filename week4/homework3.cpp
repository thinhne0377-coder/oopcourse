#include <iostream>
using namespace std;
//check số đó có là số hoàn hảo k

bool sohoanhao(int n);

int main()
{

    int n;

    do {
        cout << "Nhap so n: "; cin >> n;
        if (n<=0) cout << "Day k phai so hoan hao" << endl;
    } while (n<=0);

    if (sohoanhao(n)) cout << "Day la so hoan hao" << endl;
    else cout << "Day k phai la so hoan hao" << endl;


    return 0;
}

bool sohoanhao(int n)
{
    int sum=0;
    for (int i=1;i<n;i++)
    {
        if (n%i==0) sum=sum+i;
    }

    if (sum==n) return true;
    else return false;
}