
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// ==================== 1. CLASS VEHICLE ====================
class Vehicle {
private:
    string id;
    string brand;
    double dailyPrice;

public:
    // Default constructor
    Vehicle() {
        id = "";
        brand = "";
        dailyPrice = 0;
    }

    // Parameterized constructor
    Vehicle(string id, string brand, double dailyPrice) {
        this->id = id;
        this->brand = brand;
        this->dailyPrice = dailyPrice;
    }

    // Getter
    string getId() const {
        return id;
    }

    string getBrand() const {
        return brand;
    }

    double getDailyPrice() const {
        return dailyPrice;
    }

    // Setter
    void setId(string id) {
        this->id = id;
    }

    void setBrand(string brand) {
        this->brand = brand;
    }

    void setDailyPrice(double dailyPrice) {
        this->dailyPrice = dailyPrice;
    }

    // Display common information
    virtual void displayInfo() const {
        cout << "Ma phuong tien: " << id << endl;
        cout << "Hang xe: " << brand << endl;
        cout << "Don gia/ngay: " << dailyPrice << " VND" << endl;
    }

    // Calculate rental fee
    virtual double calculateRentalFee(int days) const = 0;

    // Virtual destructor
    virtual ~Vehicle() {}
};

// ==================== 2. CLASS CAR ====================
class Car : public Vehicle {
private:
    int seats;

public:
    // Default constructor
    Car() : Vehicle() {
        seats = 4;
    }

    // Parameterized constructor
    Car(string id, string brand, double dailyPrice, int seats)
        : Vehicle(id, brand, dailyPrice) {
        this->seats = seats;
    }

    // Getter
    int getSeats() const {
        return seats;
    }

    // Setter
    void setSeats(int seats) {
        this->seats = seats;
    }

    // Override displayInfo
    void displayInfo() const override {
        cout << "\n===== O TO =====" << endl;
        Vehicle::displayInfo();
        cout << "So cho ngoi: " << seats << endl;
    }

    // Discount 10% if renting from 7 days
    double calculateRentalFee(int days) const override {
        double fee = days * getDailyPrice();

        if (days >= 7) {
            fee *= 0.9;
        }

        return fee;
    }
};

// ==================== 3. CLASS MOTORBIKE ====================
class Motorbike : public Vehicle {
private:
    int engineCapacity;

public:
    // Default constructor
    Motorbike() : Vehicle() {
        engineCapacity = 110;
    }

    // Parameterized constructor
    Motorbike(string id, string brand, double dailyPrice,
              int engineCapacity)
        : Vehicle(id, brand, dailyPrice) {
        this->engineCapacity = engineCapacity;
    }

    // Getter
    int getEngineCapacity() const {
        return engineCapacity;
    }

    // Setter
    void setEngineCapacity(int engineCapacity) {
        this->engineCapacity = engineCapacity;
    }

    // Override displayInfo
    void displayInfo() const override {
        cout << "\n===== XE MAY =====" << endl;
        Vehicle::displayInfo();
        cout << "Dung tich xi lanh: "
             << engineCapacity << " cc" << endl;
    }

    // Discount 5% if renting from 5 days
    double calculateRentalFee(int days) const override {
        double fee = days * getDailyPrice();

        if (days >= 5) {
            fee *= 0.95;
        }

        return fee;
    }
};

// ==================== 4. CLASS TRUCK ====================
class Truck : public Vehicle {
private:
    double transportFee;

public:
    // Default constructor
    Truck() : Vehicle() {
        transportFee = 0;
    }

    // Parameterized constructor
    Truck(string id, string brand, double dailyPrice,
          double transportFee)
        : Vehicle(id, brand, dailyPrice) {
        this->transportFee = transportFee;
    }

    // Getter
    double getTransportFee() const {
        return transportFee;
    }

    // Setter
    void setTransportFee(double transportFee) {
        this->transportFee = transportFee;
    }

    // Override displayInfo
    void displayInfo() const override {
        cout << "\n===== XE TAI =====" << endl;
        Vehicle::displayInfo();
        cout << "Phi van chuyen co dinh: "
             << transportFee << " VND" << endl;
    }

    // Rental fee = days * daily price + fixed transport fee
    double calculateRentalFee(int days) const override {
        return days * getDailyPrice() + transportFee;
    }
};

// ==================== 5. MAIN ====================
int main() {
    cout << fixed << setprecision(0);

    vector<Vehicle*> vehicles;

    // Create sample vehicles
    vehicles.push_back(new Car("C01", "Toyota", 1000000, 7));
    vehicles.push_back(new Car("C02", "Honda", 800000, 5));

    vehicles.push_back(new Motorbike("M01", "Honda", 150000, 125));
    vehicles.push_back(new Motorbike("M02", "Yamaha", 200000, 155));

    vehicles.push_back(new Truck("T01", "Hyundai", 1500000, 500000));
    vehicles.push_back(new Truck("T02", "Isuzu", 2000000, 800000));

    int days;

    cout << "======================================" << endl;
    cout << "       QUAN LY THUE PHUONG TIEN       " << endl;
    cout << "======================================" << endl;

    cout << "Nhap so ngay thue: ";
    cin >> days;

    if (days <= 0) {
        cout << "So ngay thue phai lon hon 0!" << endl;

        for (Vehicle* v : vehicles) {
            delete v;
        }

        return 0;
    }

    double totalRevenue = 0;
    double maxFee = -1;
    Vehicle* mostExpensive = nullptr;

    // Display information and calculate revenue
    for (Vehicle* v : vehicles) {
        v->displayInfo();

        double fee = v->calculateRentalFee(days);

        cout << "So ngay thue: " << days << endl;
        cout << "Phi thue: " << fee << " VND" << endl;

        totalRevenue += fee;

        if (fee > maxFee) {
            maxFee = fee;
            mostExpensive = v;
        }
    }

    // Total revenue
    cout << "\n======================================" << endl;
    cout << "TONG DOANH THU THUE XE: "
         << totalRevenue << " VND" << endl;

    // Find vehicle with highest rental fee
    cout << "\nPHUONG TIEN CO PHI THUE CAO NHAT:" << endl;

    if (mostExpensive != nullptr) {
        mostExpensive->displayInfo();
        cout << "Phi thue cao nhat: "
             << maxFee << " VND" << endl;
    }

    // Free allocated memory
    for (Vehicle* v : vehicles) {
        delete v;
    }

    vehicles.clear();

    return 0;
}
