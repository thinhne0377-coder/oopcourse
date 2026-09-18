#include <iostream>
using namespace std;

// ======================================================
// 1. MODIFY THROUGH A REFERENCE
// ======================================================
void practice1()
{
    int n = 7;
    int& r = n;

    r = 15;

    cout << n << " " << r << endl;
}

// ======================================================
// 2. USE A REFERENCE PARAMETER
// ======================================================
void addFive(int& x)
{
    x += 5;
}

void practice2()
{
    int a = 10;

    addFive(a);

    cout << a << endl;
}

// ======================================================
// 3. SWAP USING REFERENCES
// ======================================================
void swapValues(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

void practice3()
{
    int a = 4, b = 9;

    swapValues(a, b);

    cout << a << " " << b << endl;
}

// ======================================================
// 4. REFERENCE VS VALUE
// ======================================================
void changeValue(int x)
{
    x = 100;
}

void changeRef(int& x)
{
    x = 200;
}

void practice4()
{
    int a = 5;

    changeValue(a);
    cout << "After changeValue: " << a << endl;

    changeRef(a);
    cout << "After changeRef: " << a << endl;
}

// ======================================================
// MAIN
// ======================================================
int main()
{
    cout << "===== PRACTICE 4 =====" << endl;

    cout << "\n1. Modify through a Reference:" << endl;
    practice1();

    cout << "\n2. Use a Reference Parameter:" << endl;
    practice2();

    cout << "\n3. Swap using References:" << endl;
    practice3();

    cout << "\n4. Reference vs Value:" << endl;
    practice4();

    return 0;
}