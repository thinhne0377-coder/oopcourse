#include <iostream>
using namespace std;

int main()
{
    // Step 1: Declare a variable
    int x = 10;

    // Step 2: Create a reference to x
    int& rx = x;

    // Step 3: Modify the value using reference
    rx = 20;

    // Step 4: Display the values
    cout << "x = " << x << endl;
    cout << "rx = " << rx << endl;

    return 0;
}