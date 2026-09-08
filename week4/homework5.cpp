#include <iostream>
using namespace std;
// đảo ngược số
void daongcso(int n);

int main()
{

    int n;
    cout << "Nhap so n: "; cin >> n;
    daongcso(n);

    return 0;
}

void daongcso(int n)
{
    int a[100];
    int i=0;
    int b=n;

    while (b>0)
    {
        a[i]=b%10;
        b=b/10;
        i++;
    }
    
    for (int j=0;j<i;j++)
    {
        cout << a[j];
    } 
    cout << endl;
}