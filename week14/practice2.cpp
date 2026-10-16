```cpp
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// ==================== CLASS EMPLOYEE ====================
class Employee {
private:
    string cccd;
    string phone;
    string address;

public:
    Employee() {
        cccd = "";
        phone = "";
        address = "";
    }

    Employee(string c, string p, string a) {
        cccd = c;
        phone = p;
        address = a;
    }

    // Getter
    string getCCCD() const {
        return cccd;
    }

    string getPhone() const {
        return phone;
    }

    string getAddress() const {
        return address;
    }

    // Setter
    void setCCCD(string c) {
        cccd = c;
    }

    void setPhone(string p) {
        phone = p;
    }

    void setAddress(string a) {
        address = a;
    }

    virtual double calculateSalary(int month, int year) = 0;

    virtual void displayInfo() {
        cout << "CCCD: " << cccd << endl;
        cout << "Phone: " << phone << endl;
        cout << "Address: " << address << endl;
    }

    virtual ~Employee() = default;
};

// ==================== CLASS HOURLY EMPLOYEE ====================
class HourlyEmployee : public Employee {
private:
    int hours;
    double salaryPerHour;
    int month, year;

public:
    HourlyEmployee() : Employee() {
        hours = 0;
        salaryPerHour = 0;
        month = 0;
        year = 0;
    }

    HourlyEmployee(string c, string p, string a,
                   int h, double s, int m, int y)
        : Employee(c, p, a) {
        hours = h;
        salaryPerHour = s;
        month = m;
        year = y;
    }

    int getHours() const {
        return hours;
    }

    double getSalaryPerHour() const {
        return salaryPerHour;
    }

    int getMonth() const {
        return month;
    }

    int getYear() const {
        return year;
    }

    void setHours(int h) {
        hours = h;
    }

    void setSalaryPerHour(double s) {
        salaryPerHour = s;
    }

    void setMonth(int m) {
        month = m;
    }

    void setYear(int y) {
        year = y;
    }

    double calculateSalary(int m, int y) override {
        if (m == month && y == year) {
            return hours * salaryPerHour;
        }
        return 0;
    }

    void displayInfo() override {
        cout << "\n--- HOURLY EMPLOYEE ---" << endl;
        Employee::displayInfo();
        cout << "Hours: " << hours << endl;
        cout << "Salary per hour: " << salaryPerHour << endl;
        cout << "Month: " << month << "/" << year << endl;
    }
};

// ==================== CLASS MONTHLY EMPLOYEE ====================
class MonthlyEmployee : public Employee {
private:
    double monthlySalary;
    int month, year;

public:
    MonthlyEmployee() : Employee() {
        monthlySalary = 0;
        month = 0;
        year = 0;
    }

    MonthlyEmployee(string c, string p, string a,
                    double s, int m, int y)
        : Employee(c, p, a) {
        monthlySalary = s;
        month = m;
        year = y;
    }

    double getMonthlySalary() const {
        return monthlySalary;
    }

    int getMonth() const {
        return month;
    }

    int getYear() const {
        return year;
    }

    void setMonthlySalary(double s) {
        monthlySalary = s;
    }

    void setMonth(int m) {
        month = m;
    }

    void setYear(int y) {
        year = y;
    }

    double calculateSalary(int m, int y) override {
        if (m == month && y == year) {
            return monthlySalary;
        }
        return 0;
    }

    void displayInfo() override {
        cout << "\n--- MONTHLY EMPLOYEE ---" << endl;
        Employee::displayInfo();
        cout << "Monthly salary: " << monthlySalary << endl;
        cout << "Month: " << month << "/" << year << endl;
    }
};

// ==================== CLASS DAILY EMPLOYEE ====================
class DailyEmployee : public Employee {
private:
    int numberOfDays;
    double salaryPerDay;
    int month, year;

public:
    DailyEmployee() : Employee() {
        numberOfDays = 0;
        salaryPerDay = 0;
        month = 0;
        year = 0;
    }

    DailyEmployee(string c, string p, string a,
                  int d, double s, int m, int y)
        : Employee(c, p, a) {
        numberOfDays = d;
        salaryPerDay = s;
        month = m;
        year = y;
    }

    int getNumberOfDays() const {
        return numberOfDays;
    }

    double getSalaryPerDay() const {
        return salaryPerDay;
    }

    int getMonth() const {
        return month;
    }

    int getYear() const {
        return year;
    }

    void setNumberOfDays(int d) {
        numberOfDays = d;
    }

    void setSalaryPerDay(double s) {
        salaryPerDay = s;
    }

    void setMonth(int m) {
        month = m;
    }

    void setYear(int y) {
        year = y;
    }

    double calculateSalary(int m, int y) override {
        if (m == month && y == year) {
            return numberOfDays * salaryPerDay;
        }
        return 0;
    }

    void displayInfo() override {
        cout << "\n--- DAILY EMPLOYEE ---" << endl;
        Employee::displayInfo();
        cout << "Number of days: " << numberOfDays << endl;
        cout << "Salary per day: " << salaryPerDay << endl;
        cout << "Month: " << month << "/" << year << endl;
    }
};

// ==================== CALCULATE YEARLY SALARY ====================
double calculateYearlySalary(Employee* employees[], int n, int year) {
    double totalSalary = 0;

    for (int i = 0; i < n; i++) {
        for (int month = 1; month <= 12; month++) {
            totalSalary += employees[i]->calculateSalary(month, year);
        }
    }

    return totalSalary;
}

// ==================== MAIN ====================
int main() {
    HourlyEmployee h(
        "001", "0901", "HCM",
        160, 50000, 10, 2026
    );

    MonthlyEmployee m(
        "002", "0902", "Dong Nai",
        15000000, 10, 2026
    );

    DailyEmployee d(
        "003", "0903", "Ha Noi",
        22, 400000, 10, 2026
    );

    // Mang con tro lop cha
    Employee* employees[] = { &h, &m, &d };
    int n = 3;

    cout << fixed << setprecision(0);

    // Hien thi thong tin nhan vien
    h.displayInfo();
    m.displayInfo();
    d.displayInfo();

    // Tinh luong thang 10/2026
    cout << "\n========== MONTHLY SALARY ==========" << endl;

    double totalMonthlySalary = 0;

    for (int i = 0; i < n; i++) {
        double salary = employees[i]->calculateSalary(10, 2026);
        cout << "Employee " << i + 1
             << ": " << salary << " VND" << endl;

        totalMonthlySalary += salary;
    }

    cout << "Total salary October 2026: "
         << totalMonthlySalary << " VND" << endl;

    // Tinh luong theo nam
    cout << "\n========== YEARLY SALARY ==========" << endl;

    double yearlySalary = calculateYearlySalary(
        employees, n, 2026
    );

    cout << "Total salary in 2026: "
         << yearlySalary << " VND" << endl;

    return 0;
}
```