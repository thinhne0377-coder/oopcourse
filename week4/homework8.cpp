#include <iostream>
using namespace std;
//BCNN
int UCLN(int a, int b);
long long BCNN(long long a, long long b);


int main()
{

    int a,b;
    cout << "Nhap so a,b: "; cin >> a >> b;
    cout << "BCNN cua a va b: " << BCNN(a,b) << endl;


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

long long BCNN(long long a, long long b)
{
	a = abs(a); b = abs(b);
	if (a == 0 || b == 0) return 0;
	return a / UCLN((int)a, (int)b) * b;
}