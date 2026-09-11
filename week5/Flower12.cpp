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
    int totalQuantity = 0;
    double totalPrice = 0;

    for (int i = 0; i < n; i++) {
        totalQuantity += quantity[i];
        totalPrice += price[i];
    }

    double averagePrice = totalPrice / n;

    cout << "\n===== ANALYSIS =====\n";

    cout << "Most expensive flower: "
         << name[maxIndex]
         << " (" << price[maxIndex] << ")\n";

    cout << "Cheapest flower: "
         << name[minIndex]
         << " (" << price[minIndex] << ")\n";

    cout << "Total quantity: "
         << totalQuantity << endl;

    cout << "Average price: "
         << averagePrice << endl;

    // =========================
    // COUNT BY TYPE
    // =========================
     string types[MAX];
    int counts[MAX] = {0};

    int typeCount = 0;

    for (int i = 0; i < n; i++) {

        int found = -1;

        for (int j = 0; j < typeCount; j++) {

            if (types[j] == type[i]) {
                found = j;
                break;
            }
        }

        if (found == -1) {

            types[typeCount] = type[i];
            counts[typeCount] = 1;
            typeCount++;

        } else {

            counts[found]++;
        }
    }

    cout << "\n===== COUNT BY TYPE =====\n";

    for (int i = 0; i < typeCount; i++) {
        cout << types[i]
             << " : "
             << counts[i]
             << endl;
    }

    // =========================
    // SEARCH
    // =========================
char choice;

    do {

        string searchName;

        cout << "\nEnter flower name to search: ";
        cin >> searchName;

        int foundIndex = -1;

        for (int i = 0; i < n; i++) {

            if (name[i] == searchName) {
                foundIndex = i;
                break;
            }
        }

        if (foundIndex != -1) {

            cout << "Found!\n";
            cout << "Price: "
                 << price[foundIndex] << endl;

            cout << "Quantity: "
                 << quantity[foundIndex] << endl;

            cout << "Type: "
                 << type[foundIndex] << endl;

        } else {

            cout << "Flower not found.\n";
        }

        cout << "\nSearch another flower? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "\nProgram ended.\n";

    return 0;
}