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
int maxQuantityIndex = 0;

for (int i = 1; i < n; i++) {
    if (flowers[i].quantity > flowers[maxQuantityIndex].quantity) {
        maxQuantityIndex = i;
    }
}

cout << "Largest quantity: "
     << flowers[maxQuantityIndex].name
     << " (" << flowers[maxQuantityIndex].quantity << ")\n";
int totalQuantity = 0;

for (int i = 0; i < n; i++) {
    totalQuantity += flowers[i].quantity;
}

cout << "Total quantity: " << totalQuantity << endl;
double sumPrice = 0;

for (int i = 0; i < n; i++) {
    sumPrice += flowers[i].price;
}

double averagePrice = sumPrice / n;

cout << "Average price: " << averagePrice << endl;
string searchType;
int count = 0;

cout << "Enter type: ";
cin >> ws;
getline(cin, searchType);

for (int i = 0; i < n; i++) {
    if (flowers[i].type == searchType) {
        count++;
    }
}

cout << "Number of " << searchType << ": " << count << endl;
string searchType;

cout << "Enter type: ";
cin >> ws;
getline(cin, searchType);

bool found = false;

for (int i = 0; i < n; i++) {
    if (flowers[i].type == searchType) {
        cout << flowers[i].name << " - "
             << flowers[i].price << " - "
             << flowers[i].quantity << endl;

        found = true;
    }
}

if (!found) {
    cout << "No flower found.\n";
}
string searchName;

cout << "Enter flower name: ";
cin >> ws;
getline(cin, searchName);

bool found = false;

for (int i = 0; i < n; i++) {
    if (flowers[i].name == searchName) {
        cout << "\nFound!\n";
        cout << "Name: " << flowers[i].name << endl;
        cout << "Price: " << flowers[i].price << endl;
        cout << "Quantity: " << flowers[i].quantity << endl;
        cout << "Type: " << flowers[i].type << endl;

        found = true;
        break;
    }
}

if (!found) {
    cout << "Flower not found.\n";
}
string name;
bool exists = false;

cout << "Enter flower name: ";
cin >> ws;
getline(cin, name);

for (int i = 0; i < n; i++) {
    if (flowers[i].name == name) {
        exists = true;
        break;
    }
}

if (exists)
    cout << "Yes, flower exists.\n";
else
    cout << "No, flower does not exist.\n";
int countLow = 0;

for (int i = 0; i < n; i++) {
    if (flowers[i].quantity < 5) {
        countLow++;
    }
}

cout << "Flowers with quantity < 5: "
     << countLow << endl;
double minPrice, maxPrice;

cout << "Minimum price: ";
cin >> minPrice;

cout << "Maximum price: ";
cin >> maxPrice;

int countRange = 0;

for (int i = 0; i < n; i++) {
    if (flowers[i].price >= minPrice &&
        flowers[i].price <= maxPrice) {
        countRange++;
    }
}

cout << "Number of flowers in range: "
     << countRange << endl;
double totalValue = 0;

for (int i = 0; i < n; i++) {
    totalValue += flowers[i].price * flowers[i].quantity;
}

cout << "Total value: " << totalValue << endl;
int maxValueIndex = 0;

for (int i = 1; i < n; i++) {
    double currentValue =
        flowers[i].price * flowers[i].quantity;

    double maxValue =
        flowers[maxValueIndex].price *
        flowers[maxValueIndex].quantity;

    if (currentValue > maxValue) {
        maxValueIndex = i;
    }
}

cout << "Most valuable flower: "
     << flowers[maxValueIndex].name << endl;
for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {

        if (flowers[j].price > flowers[j + 1].price) {
            Flower temp = flowers[j];
            flowers[j] = flowers[j + 1];
            flowers[j + 1] = temp;
        }
    }
}
for (int i = 0; i < n; i++) {
    cout << flowers[i].name << " - "
         << flowers[i].price << endl;
}
Flower temp = flowers[j];
flowers[j] = flowers[j + 1];
flowers[j + 1] = temp;
for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {

        if (flowers[j].name > flowers[j + 1].name) {
            Flower temp = flowers[j];
            flowers[j] = flowers[j + 1];
            flowers[j + 1] = temp;
        }
    }
}
Flower tempArray[20];

for (int i = 0; i < n; i++) {
    tempArray[i] = flowers[i];
}

for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {

        if (tempArray[j].price < tempArray[j + 1].price) {
            Flower temp = tempArray[j];
            tempArray[j] = tempArray[j + 1];
            tempArray[j + 1] = temp;
        }
    }
}

cout << "Top 3 most expensive:\n";

int limit = (n < 3) ? n : 3;

for (int i = 0; i < limit; i++) {
    cout << tempArray[i].name << " - "
         << tempArray[i].price << endl;
}
string keyword;

cout << "Enter keyword: ";
cin >> keyword;

for (int i = 0; i < n; i++) {
    if (flowers[i].name.find(keyword) != string::npos) {
        cout << flowers[i].name << endl;
    }
}
