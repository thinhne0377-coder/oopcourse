
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// ==================== CLASS EMPLOYEE ====================
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
        cout << "Ho ten: " << name << endl;
    }

    virtual double calculateSalary() const {
        return 0;
    }

    virtual double calculateSalary(int month, int year) const {
        return 0;
    }

    virtual ~Employee() {}
};

// ==================== CLASS HOURLYEMPLOYEE ====================
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
        year = 2026;
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

    double calculateSalary() const override {
        return hours * salaryPerHour;
    }

    double calculateSalary(int month, int year) const override {
        if (this->month == month && this->year == year)
            return calculateSalary();
        return 0;
    }

    void display() const override {
        cout << "\nLoai nhan vien: Hourly Employee\n";
        Employee::display();
        cout << "So gio lam: " << hours << endl;
        cout << "Luong moi gio: " << salaryPerHour << endl;
        cout << "Thang: " << month << endl;
        cout << "Nam: " << year << endl;
        cout << "Luong: " << calculateSalary() << " VND\n";
    }
};

// ==================== CLASS MONTHLYEMPLOYEE ====================
class MonthlyEmployee : public Employee {
private:
    int month;
    int year;
    double monthlySalary;

public:
    MonthlyEmployee() : Employee() {
        month = 1;
        year = 2026;
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

    void setMonthlySalary(double salary) {
        if (salary >= 0)
            monthlySalary = salary;
    }

    double calculateSalary() const override {
        return monthlySalary;
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
        cout << "\nLoai nhan vien: Monthly Employee\n";
        Employee::display();
        cout << "Luong thang: " << monthlySalary << " VND\n";
        cout << "Thang: " << month << endl;
        cout << "Nam: " << year << endl;
        cout << "Luong: " << calculateSalary() << " VND\n";
    }
};

// ==================== CLASS DAILYEMPLOYEE ====================
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
        year = 2026;
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

    void setNumberOfDays(int days) {
        if (days >= 0)
            numberOfDays = days;
    }

    void setMonth(int month) {
        if (month >= 1 && month <= 12)
            this->month = month;
    }

    void setYear(int year) {
        if (year > 0)
            this->year = year;
    }

    void setSalaryPerDay(double salary) {
        if (salary >= 0)
            salaryPerDay = salary;
    }

    double calculateSalary() const override {
        return numberOfDays * salaryPerDay;
    }

    double calculateSalary(int month, int year) const override {
        if (this->month == month && this->year == year)
            return calculateSalary();
        return 0;
    }

    void display() const override {
        cout << "\nLoai nhan vien: Daily Employee\n";
        Employee::display();
        cout << "So ngay lam: " << numberOfDays << endl;
        cout << "Luong moi ngay: " << salaryPerDay << endl;
        cout << "Thang: " << month << endl;
        cout << "Nam: " << year << endl;
        cout << "Luong: " << calculateSalary() << " VND\n";
    }
};

// ==================== MAIN ====================
int main() {
    cout << fixed << setprecision(0);

    int month, year;

    cout << "========== NHAP THANG VA NAM CAN TINH LUONG ==========\n";
    cout << "Nhap thang (1-12): ";
    cin >> month;

    cout << "Nhap nam: ";
    cin >> year;

    if (month < 1 || month > 12 || year <= 0) {
        cout << "Thang hoac nam khong hop le!\n";
        return 1;
    }

    // Nhap HourlyEmployee
    string name1;
    double hours, salaryPerHour;
    int month1, year1;

    cout << "\n========== HOURLY EMPLOYEE ==========\n";
    cin.ignore(10000, '\n');

    cout << "Nhap ho ten: ";
    getline(cin, name1);

    cout << "Nhap so gio lam: ";
    cin >> hours;

    cout << "Nhap luong moi gio: ";
    cin >> salaryPerHour;

    cout << "Nhap thang: ";
    cin >> month1;

    cout << "Nhap nam: ";
    cin >> year1;

    HourlyEmployee hourly(name1, hours, salaryPerHour, month1, year1);

    // Nhap MonthlyEmployee
    string name2;
    double monthlySalary;
    int month2, year2;

    cout << "\n========== MONTHLY EMPLOYEE ==========\n";
    cin.ignore(10000, '\n');

    cout << "Nhap ho ten: ";
    getline(cin, name2);

    cout << "Nhap luong thang: ";
    cin >> monthlySalary;

    cout << "Nhap thang: ";
    cin >> month2;

    cout << "Nhap nam: ";
    cin >> year2;

    MonthlyEmployee monthly(name2, monthlySalary, month2, year2);

    // Nhap DailyEmployee
    string name3;
    int numberOfDays, month3, year3;
    double salaryPerDay;

    cout << "\n========== DAILY EMPLOYEE ==========\n";
    cin.ignore(10000, '\n');

    cout << "Nhap ho ten: ";
    getline(cin, name3);

    cout << "Nhap so ngay lam: ";
    cin >> numberOfDays;

    cout << "Nhap luong moi ngay: ";
    cin >> salaryPerDay;

    cout << "Nhap thang: ";
    cin >> month3;

    cout << "Nhap nam: ";
    cin >> year3;

    DailyEmployee daily(name3, numberOfDays, salaryPerDay, month3, year3);

    // Hien thi thong tin
    cout << "\n\n========== THONG TIN NHAN VIEN ==========\n";
    hourly.display();
    monthly.display();
    daily.display();

    // Tinh luong theo thang va nam da chon
    cout << "\n========== TONG KET LUONG ==========\n";
    cout << "Thang can tinh: " << month
         << "/" << year << "\n";

    double salaryHourly = hourly.calculateSalary(month, year);
    double salaryMonthly = monthly.calculateSalary(month, year);
    double salaryDaily = daily.calculateSalary(month, year);

    cout << "Luong HourlyEmployee: "
         << salaryHourly << " VND\n";

    cout << "Luong MonthlyEmployee: "
         << salaryMonthly << " VND\n";

    cout << "Luong DailyEmployee: "
         << salaryDaily << " VND\n";

    cout << "Tong luong: "
         << salaryHourly + salaryMonthly + salaryDaily
         << " VND\n";

    cout << "\nTong luong nam cua MonthlyEmployee: "
         << monthly.calculateYearSalary(year) << " VND\n";

    return 0;
}
