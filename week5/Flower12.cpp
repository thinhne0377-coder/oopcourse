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
    for (int i = 0; i < n; i++) {

        cout << "\nFlower " << i + 1 << ":\n";

        cout << "Name: ";
        cin >> name[i];

        cout << "Price: ";
        cin >> price[i];

        while (price[i] <= 0) {
            cout << "Price must be > 0. Enter again: ";
            cin >> price[i];
        }

        cout << "Quantity: ";
        cin >> quantity[i];

        while (quantity[i] < 0) {
            cout << "Quantity must be >= 0. Enter again: ";
            cin >> quantity[i];
        }

        cout << "Type: ";
        cin >> type[i];
    }

    // =========================
    // DISPLAY
    // =========================