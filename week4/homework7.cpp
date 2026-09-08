#include <iostream>
using namespace std;
//UCLN
int UCLN(int a, int b);


int main()
{
    int a,b;
    cout << "Nhap so a,b: "; cin >> a >> b;
    cout << "UCLN cua a va b: " << UCLN(a,b) << endl;


    return 0;
}

int UCLN(int a, int b)
{
	a = abs(a); b = abs(b);
	if (a == 0) return b;
	if (b == 0) return a;
	while (b != 0) { int r = a % b; a = b; b = r; }
	return a;
}