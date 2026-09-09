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
for (int i = 0; i < n; i++) {
    cout << "\nFlower " << i + 1 << ":\n";

    cout << "Name: ";
    cin >> ws;
    getline(cin, flowers[i].name);

    do {
        cout << "Price: ";
        cin >> flowers[i].price;

        if (flowers[i].price <= 0) {
            cout << "Price must be > 0!\n";
        }
    } while (flowers[i].price <= 0);

    do {
        cout << "Quantity: ";
        cin >> flowers[i].quantity;

        if (flowers[i].quantity < 0) {
            cout << "Quantity must be >= 0!\n";
        }
    } while (flowers[i].quantity < 0);

    cout << "Type: ";
    cin >> ws;
    getline(cin, flowers[i].type);
}
cout << "\n===== FLOWER SHOP =====\n";

cout << "No\tName\tPrice\tQty\tType\n";

for (int i = 0; i < n; i++) {
    cout << i + 1 << "\t"
         << flowers[i].name << "\t"
         << flowers[i].price << "\t"
         << flowers[i].quantity << "\t"
         << flowers[i].type << endl;
}
int maxPriceIndex = 0;

for (int i = 1; i < n; i++) {
    if (flowers[i].price > flowers[maxPriceIndex].price) {
        maxPriceIndex = i;
    }
}

cout << "\nMost expensive flower: "
     << flowers[maxPriceIndex].name
     << " (" << flowers[maxPriceIndex].price << ")\n";
int minPriceIndex = 0;

for (int i = 1; i < n; i++) {
    if (flowers[i].price < flowers[minPriceIndex].price) {
        minPriceIndex = i;
    }
}

cout << "Cheapest flower: "
     << flowers[minPriceIndex].name
     << " (" << flowers[minPriceIndex].price << ")\n";
