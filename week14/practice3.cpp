
#include <iostream>
#include <string>
#include <iomanip>

#define MAX 100

using namespace std;

// ================= DRINKS  =================
class Drinks {
protected:
    string name;
    int day, month, year;
    int quantity;
    double price;

public:
    Drinks() {
        name = "";
        day = month = year = 0;
        quantity = 0;
        price = 0;
    }

    Drinks(string n, int d, int m, int y, int q, double p) {
        name = n;
        day = d;
        month = m;
        year = y;
        quantity = q;
        price = p;
    }

    bool isSameDate(int d, int m, int y) const {
        return day == d && month == m && year == y;
    }

    virtual double calculateRevenue() const {
        return quantity * price;
    }

    virtual void input() {
        cout << "Name (Coffee/Tea/Smoothies/Juices): ";
        cin >> name;
        cout << "Day Month Year: ";
        cin >> day >> month >> year;
        cout << "Quantity: ";
        cin >> quantity;
        cout << "Price: ";
        cin >> price;
    }

    virtual void displayInfo() const {
        cout << name << " | "
             << day << "/" << month << "/" << year
             << " | Quantity: " << quantity
             << " | Price: " << price
             << " | Revenue: " << calculateRevenue() << endl;
    }

    virtual ~Drinks() {}
};

// ================= FOODS =================
class Foods {
protected:
    string name;
    int day, month, year;
    int quantity;
    double price;

public:
    Foods() {
        name = "";
        day = month = year = 0;
        quantity = 0;
        price = 0;
    }

    Foods(string n, int d, int m, int y, int q, double p) {
        name = n;
        day = d;
        month = m;
        year = y;
        quantity = q;
        price = p;
    }

    bool isSameDate(int d, int m, int y) const {
        return day == d && month == m && year == y;
    }

    virtual double calculateRevenue() const {
        return quantity * price;
    }

    virtual void input() {
        cout << "Name (Cake/Breads): ";
        cin >> name;
        cout << "Day Month Year: ";
        cin >> day >> month >> year;
        cout << "Quantity: ";
        cin >> quantity;
        cout << "Price: ";
        cin >> price;
    }

    virtual void displayInfo() const {
        cout << name << " | "
             << day << "/" << month << "/" << year
             << " | Quantity: " << quantity
             << " | Price: " << price
             << " | Revenue: " << calculateRevenue() << endl;
    }

    virtual ~Foods() {}
};

// ================= MAIN =================
int main() {
    Drinks* drinks[MAX];
    Foods* foods[MAX];

    int nDrinks, nFoods;

    // Nhap Drinks
    cout << "Enter number of Drinks: ";
    cin >> nDrinks;

    for (int i = 0; i < nDrinks; i++) {
        drinks[i] = new Drinks();

        cout << "\nDrink " << i + 1 << endl;
        drinks[i]->input();
    }

    // Nhap Foods
    cout << "\nEnter number of Foods: ";
    cin >> nFoods;

    for (int i = 0; i < nFoods; i++) {
        foods[i] = new Foods();

        cout << "\nFood " << i + 1 << endl;
        foods[i]->input();
    }

    // Nhap ngay can tinh doanh thu
    int d, m, y;

    cout << "\nEnter date (dd/mm/yyyy): ";
    char slash1, slash2;
    cin >> d >> slash1 >> m >> slash2 >> y;

    double totalDrinks = 0;
    double totalFoods = 0;

    // Tinh doanh thu Drinks
    for (int i = 0; i < nDrinks; i++) {
        if (drinks[i]->isSameDate(d, m, y)) {
            totalDrinks += drinks[i]->calculateRevenue();
        }
    }

    // Tinh doanh thu Foods
    for (int i = 0; i < nFoods; i++) {
        if (foods[i]->isSameDate(d, m, y)) {
            totalFoods += foods[i]->calculateRevenue();
        }
    }

    // Xuat ket qua theo yeu cau
    cout << fixed << setprecision(2);
    cout << "\n" << d << "/" << m << "/" << y << endl;
    cout << "- Drinks: " << totalDrinks << endl;
    cout << "- Foods: " << totalFoods << endl;

    // Giai phong bo nho
    for (int i = 0; i < nDrinks; i++) {
        delete drinks[i];
    }

    for (int i = 0; i < nFoods; i++) {
        delete foods[i];
    }

    return 0;
}
