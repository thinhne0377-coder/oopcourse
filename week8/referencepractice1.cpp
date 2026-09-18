#include <iostream>
using namespace std;

int main()
{
    // Step 1: Create an integer variable x and assign 10
    int x = 10;

    // Step 2: Create a reference rx to x
    int& rx = x;

    // Step 3: Modify the value using the reference
    rx = 20;

    // Step 4: Display the values of x and rx
    cout << "x = " << x << endl;
    cout << "rx = " << rx << endl;

    return 0;
}