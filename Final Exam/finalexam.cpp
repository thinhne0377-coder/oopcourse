#include <iostream>
#include <vector>
#include <memory>
#include <map>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

// ==================== BASE CLASS ====================
class UtilityBill {
private:
    string billID;
    string customerName;
    string customerAddress;
    int billingMonth;
    int billingYear;

public:
    UtilityBill(string id, string name, string address,
                int month, int year) {
        billID = id;
        customerName = name;
        customerAddress = address;
        billingMonth = month;
        billingYear = year;
    }

    virtual ~UtilityBill() {}

    // Getter methods
    string getBillID() const {
        return billID;
    }

    string getCustomerName() const {
        return customerName;
    }

    string getCustomerAddress() const {
        return customerAddress;
    }

    int getBillingMonth() const {
        return billingMonth;
    }

    int getBillingYear() const {
        return billingYear;
    }

    // Pure virtual functions: POLYMORPHISM
    virtual double calculateAmount() const = 0;

    virtual string getServiceName() const = 0;

    virtual string getUsageInfo() const = 0;

    // Display common bill information
    virtual void display() const {
        cout << left
             << setw(10) << billID
             << setw(20) << customerName
             << setw(22) << customerAddress
             << setw(8) << billingMonth
             << setw(8) << billingYear
             << setw(15) << getServiceName()
             << setw(25) << getUsageInfo()
             << fixed << setprecision(0)
             << setw(15) << calculateAmount()
             << " VND" << endl;
    }
};

// ==================== ELECTRICITY BILL ====================
class ElectricityBill : public UtilityBill {
private:
    double consumption;
    const double price = 2500;

public:
    ElectricityBill(string id, string name, string address,
                    int month, int year, double kwh)
        : UtilityBill(id, name, address, month, year) {
        consumption = kwh;
    }

    double calculateAmount() const override {
        return consumption * price;
    }

    string getServiceName() const override {
        return "Electricity";
    }

    string getUsageInfo() const override {
        return to_string(consumption) + " kWh";
    }
};

// ==================== WATER BILL ====================
class WaterBill : public UtilityBill {
private:
    double consumption;
    const double price = 10000;

public:
    WaterBill(string id, string name, string address,
              int month, int year, double m3)
        : UtilityBill(id, name, address, month, year) {
        consumption = m3;
    }

    double calculateAmount() const override {
        return consumption * price;
    }

    string getServiceName() const override {
        return "Water";
    }

    string getUsageInfo() const override {
        return to_string(consumption) + " m3";
    }
};

// ==================== INTERNET BILL ====================
class InternetBill : public UtilityBill {
private:
    const double monthlyFee = 200000;

public:
    InternetBill(string id, string name, string address,
                 int month, int year)
        : UtilityBill(id, name, address, month, year) {
    }

    double calculateAmount() const override {
        return monthlyFee;
    }

    string getServiceName() const override {
        return "Internet";
    }

    string getUsageInfo() const override {
        return "Monthly package";
    }
};

// ==================== MAIN FUNCTION ====================
int main() {
    vector<unique_ptr<UtilityBill>> bills;

    // Create 10 bills: Electricity, Water and Internet
    bills.push_back(make_unique<ElectricityBill>(
        "B001", "Nguyen An", "Thu Duc", 1, 2026, 150));

    bills.push_back(make_unique<WaterBill>(
        "B002", "Tran Binh", "District 1", 1, 2026, 20));

    bills.push_back(make_unique<InternetBill>(
        "B003", "Le Cuong", "District 3", 1, 2026));

    bills.push_back(make_unique<ElectricityBill>(
        "B004", "Pham Dung", "District 7", 2, 2026, 200));

    bills.push_back(make_unique<WaterBill>(
        "B005", "Hoang Giang", "Thu Duc", 2, 2026, 25));

    bills.push_back(make_unique<InternetBill>(
        "B006", "Vu Hieu", "Binh Thanh", 2, 2026));

    bills.push_back(make_unique<ElectricityBill>(
        "B007", "Do Khanh", "Go Vap", 3, 2026, 180));

    bills.push_back(make_unique<WaterBill>(
        "B008", "Bui Long", "District 5", 3, 2026, 30));

    bills.push_back(make_unique<InternetBill>(
        "B009", "Dang Minh", "Thu Duc", 3, 2026));

    bills.push_back(make_unique<ElectricityBill>(
        "B010", "Mai Nam", "District 10", 3, 2026, 250));

    // Display all bills
    cout << "========== UTILITY BILL MANAGEMENT SYSTEM =========="
         << endl << endl;

    cout << left
         << setw(10) << "Bill ID"
         << setw(20) << "Customer"
         << setw(22) << "Address"
         << setw(8) << "Month"
         << setw(8) << "Year"
         << setw(15) << "Service"
         << setw(25) << "Usage/Package"
         << setw(15) << "Amount"
         << endl;

    cout << string(123, '-') << endl;

    double grandTotal = 0;

    map<string, int> billCount;
    map<string, double> categoryTotal;

    // POLYMORPHISM:
    // Each object calculates its own bill amount
    for (const auto& bill : bills) {
        bill->display();

        string category = bill->getServiceName();
        double amount = bill->calculateAmount();

        billCount[category]++;
        categoryTotal[category] += amount;
        grandTotal += amount;
    }

    // Display summary grouped by service category
    cout << endl;
    cout << "========== UTILITY BILLING SUMMARY =========="
         << endl;

    cout << left
         << setw(20) << "Service"
         << setw(20) << "Number of Bills"
         << setw(25) << "Total Amount (VND)"
         << endl;

    cout << string(65, '-') << endl;

    for (const auto& item : billCount) {
        cout << left
             << setw(20) << item.first
             << setw(20) << item.second
             << fixed << setprecision(0)
             << setw(25) << categoryTotal[item.first]
             << endl;
    }

    // Display grand total
    cout << string(65, '-') << endl;

    cout << "Total number of bills: "
         << bills.size() << endl;

    cout << "Grand Total: "
         << fixed << setprecision(0)
         << grandTotal << " VND" << endl;

    return 0;
}