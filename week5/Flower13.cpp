#include <iostream>
#include <string>
using namespace std;

struct Flower {
    string name;
    double price;
    int quantity;
    string type;
};
Flower flowers[20];
int n;
do {
    cout << "How many flowers? ";
    cin >> n;

    if (n < 1 || n > 20) {
        cout << "Invalid! Enter from 1 to 20.\n";
    }
} while (n < 1 || n > 20);
