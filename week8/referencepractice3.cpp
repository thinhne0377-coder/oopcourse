#include <iostream>
using namespace std;

int main() {

    // ==========================================
    // PRACTICE 3 - PART 1
    // Predict the Output Using References
    // ==========================================

    int a = 5;
    int &r = a;     // r is a reference to a

    r = 10;         // modify a through reference

    cout << a << endl;   // (1)
    cout << r << endl;   // (2)


    // ==========================================
    // PRACTICE 3 - PART 2
    // Try a Variation
    // ==========================================

    int x = 3;
    int &y = x;     // y is a reference to x

    x = 7;
    y = 2;

    cout << x << " " << y << endl;


    return 0;
}