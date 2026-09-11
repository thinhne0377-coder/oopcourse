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
    cout << "\n\n===== FLOWER SHOP =====\n";

    cout << left
         << setw(5) << "No"
         << setw(15) << "Name"
         << setw(10) << "Price"
         << setw(10) << "Qty"
         << setw(15) << "Type"
         << endl;

    for (int i = 0; i < n; i++) {
        cout << left
             << setw(5) << i + 1
             << setw(15) << name[i]
             << setw(10) << price[i]
             << setw(10) << quantity[i]
             << setw(15) << type[i]
             << endl;
    }

    // =========================
    // MOST EXPENSIVE
    // =========================
    int maxIndex = 0;

    for (int i = 1; i < n; i++) {
        if (price[i] > price[maxIndex]) {
            maxIndex = i;
        }
    }

    // =========================
    // CHEAPEST
    // =========================
    int minIndex = 0;

    for (int i = 1; i < n; i++) {
        if (price[i] < price[minIndex]) {
            minIndex = i;
        }
    }

    // =========================
    // ANALYSIS
    // =========================