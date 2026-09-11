#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    const int MAX = 20;

    string name[MAX];
    double price[MAX];
    int quantity[MAX];
    string type[MAX];

    int n;

    // =========================
    // INPUT NUMBER OF FLOWERS
    // =========================
    cout << "How many flowers? ";
    cin >> n;

    while (n < 1 || n > MAX) {
        cout << "Invalid! Enter number from 1 to 20: ";
        cin >> n;
    }

    // =========================
    // INPUT FLOWER INFORMATION
    // =========================