
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// ==================== EMPLOYEE ====================
class Employee {
private:
    string name;

public:
    Employee() {
        name = "";
    }

    Employee(string name) {
        this->name = name;
    }

    string getName() const {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }

    virtual void display() const {
        cout << "Name: " << name << endl;
    }

    virtual double calculateSalary(int month, int year) const {
        return 0;
    }

    virtual ~Employee() {}
};

// ==================== HOURLY EMPLOYEE ====================
class HourlyEmployee : public Employee {
private:
    double hours;
    double salaryPerHour;
    int month;
    int year;

public:
    HourlyEmployee() : Employee() {
        hours = 0;
        salaryPerHour = 0;
        month = 1;
        year = 2000;
    }

    HourlyEmployee(string name, double hours,
                   double salaryPerHour, int month, int year)
        : Employee(name) {
        this->hours = hours;
        this->salaryPerHour = salaryPerHour;
        this->month = month;
        this->year = year;
    }

    double getHours() const {
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

    void setHours(double hours) {
        if (hours >= 0)
            this->hours = hours;
    }

    void setSalaryPerHour(double salaryPerHour) {
        if (salaryPerHour >= 0)
            this->salaryPerHour = salaryPerHour;
    }

    void setMonth(int month) {
        if (month >= 1 && month <= 12)
            this->month = month;
    }

    void setYear(int year) {
        if (year > 0)
            this->year = year;
    }

    double calculateSalary(int month, int year) const override {
        if (this->month == month && this->year == year)
            return hours * salaryPerHour;

        return 0;
    }

    void display() const override {
        Employee::display();
        cout << "Type: Hourly Employee\n";
        cout << "Hours: " << hours << endl;
        cout << "Salary per hour: " << salaryPerHour << endl;
        cout << "Month: " << month << endl;
        cout << "Year: " << year << endl;
    }
};

// ==================== MONTHLY EMPLOYEE ====================
class MonthlyEmployee : public Employee {
private:
    int month;
    int year;
    double monthlySalary;

public:
    MonthlyEmployee() : Employee() {
        month = 1;
        year = 2000;
        monthlySalary = 0;
    }

    MonthlyEmployee(string name, double monthlySalary,
                    int month, int year)
        : Employee(name) {
        this->monthlySalary = monthlySalary;
        this->month = month;
        this->year = year;
    }

    int getMonth() const {
        return month;
    }

    int getYear() const {
        return year;
    }

    double getMonthlySalary() const {
        return monthlySalary;
    }

    void setMonth(int month) {
        if (month >= 1 && month <= 12)
            this->month = month;
    }

    void setYear(int year) {
        if (year > 0)
            this->year = year;
    }

    void setMonthlySalary(double monthlySalary) {
        if (monthlySalary >= 0)
            this->monthlySalary = monthlySalary;
    }

    double calculateSalary(int month, int year) const override {
        if (this->month == month && this->year == year)
            return monthlySalary;

        return 0;
    }

    double calculateYearSalary(int year) const {
        if (this->year == year)
            return monthlySalary * 12;

        return 0;
    }

    void display() const override {
        Employee::display();
        cout << "Type: Monthly Employee\n";
        cout << "Monthly salary: " << monthlySalary << endl;
        cout << "Month: " << month << endl;
        cout << "Year: " << year << endl;
    }
};

// ==================== DAILY EMPLOYEE ====================
class DailyEmployee : public Employee {
private:
    int numberOfDays;
    int month;
    int year;
    double salaryPerDay;

public:
    DailyEmployee() : Employee() {
        numberOfDays = 0;
        month = 1;
        year = 2000;
        salaryPerDay = 0;
    }

    DailyEmployee(string name, int numberOfDays,
                  double salaryPerDay, int month, int year)
        : Employee(name) {
        this->numberOfDays = numberOfDays;
        this->salaryPerDay = salaryPerDay;
        this->month = month;
        this->year = year;
    }

    int getNumberOfDays() const {
        return numberOfDays;
    }

    int getMonth() const {
        return month;
    }

    int getYear() const {
        return year;
    }

    double getSalaryPerDay() const {
        return salaryPerDay;
    }

    void setNumberOfDays(int numberOfDays) {
        if (numberOfDays >= 0)
            this->numberOfDays = numberOfDays;
    }

    void setMonth(int month) {
        if (month >= 1 && month <= 12)
            this->month = month;
    }

    void setYear(int year) {
        if (year > 0)
            this->year = year;
    }

    void setSalaryPerDay(double salaryPerDay) {
        if (salaryPerDay >= 0)
            this->salaryPerDay = salaryPerDay;
    }

    double calculateSalary(int month, int year) const override {
        if (this->month == month && this->year == year)
            return numberOfDays * salaryPerDay;

        return 0;
    }

    void display() const override {
        Employee::display();
        cout << "Type: Daily Employee\n";
        cout << "Number of days: " << numberOfDays << endl;
        cout << "Salary per day: " << salaryPerDay << endl;
        cout << "Month: " << month << endl;
        cout << "Year: " << year << endl;
    }
};

// ==================== MAIN ====================
int main() {
    cout << fixed << setprecision(0);

    string name;
    int month, year;
    double hours, salaryPerHour;
    double monthlySalary;
    int numberOfDays;
    double salaryPerDay;

    cout << "===== ENTER MONTH AND YEAR TO CALCULATE SALARY =====\n";
    cout << "Enter month (1-12): ";
    cin >> month;

    cout << "Enter year: ";
    cin >> year;

    if (month < 1 || month > 12 || year <= 0) {
        cout << "Invalid month or year!\n";
        return 1;
    }

    // Hourly Employee
    cout << "\n===== HOURLY EMPLOYEE =====\n";
    cin.ignore(10000, '\n');

    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter hours: ";
    cin >> hours;

    cout << "Enter salary per hour: ";
    cin >> salaryPerHour;

    HourlyEmployee hourly(name, hours, salaryPerHour, month, year);

    // Monthly Employee
    cout << "\n===== MONTHLY EMPLOYEE =====\n";
    cin.ignore(10000, '\n');

    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter monthly salary: ";
    cin >> monthlySalary;

    MonthlyEmployee monthly(name, monthlySalary, month, year);

    // Daily Employee
    cout << "\n===== DAILY EMPLOYEE =====\n";
    cin.ignore(10000, '\n');

    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter number of working days: ";
    cin >> numberOfDays;

    cout << "Enter salary per day: ";
    cin >> salaryPerDay;

    DailyEmployee daily(name, numberOfDays, salaryPerDay, month, year);

    // Display information
    cout << "\n===== EMPLOYEE INFORMATION =====\n";

    hourly.display();
    cout << "Salary: "
         << hourly.calculateSalary(month, year) << " VND\n";

    monthly.display();
    cout << "Salary: "
         << monthly.calculateSalary(month, year) << " VND\n";

    daily.display();
    cout << "Salary: "
         << daily.calculateSalary(month, year) << " VND\n";

    // Total salary
    double totalSalary =
        hourly.calculateSalary(month, year) +
        monthly.calculateSalary(month, year) +
        daily.calculateSalary(month, year);

    cout << "\n===== SALARY SUMMARY =====\n";
    cout << "Month/Year: " << month << "/" << year << endl;
    cout << "Total salary: " << totalSalary << " VND\n";

    cout << "Monthly employee annual salary: "
         << monthly.calculateYearSalary(year) << " VND\n";

    return 0;
}
