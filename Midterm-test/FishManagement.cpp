#include <iostream>
#include <string>
#include <limits>
using namespace std;

// ==================== CLASS DATE ====================
class Date {
private:
    int day;
    int month;
    int year;

public:
    Date() {
        day = 1;
        month = 1;
        year = 2000;
    }

    Date(int day, int month, int year) {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    int getDay() {
        return day;
    }

    int getMonth() {
        return month;
    }

    int getYear() {
        return year;
    }

    void setDay(int day) {
        this->day = day;
    }

    void setMonth(int month) {
        this->month = month;
    }

    void setYear(int year) {
        this->year = year;
    }

    void input() {
        cout << "Enter day: ";
        cin >> day;

        cout << "Enter month: ";
        cin >> month;

        cout << "Enter year: ";
        cin >> year;
    }

    void display() {
        cout << day << "/" << month << "/" << year;
    }
};

// ==================== CLASS FISH ====================
class Fish {
private:
    int id;
    string name;
    string color;
    string characteristic;
    int categoryId;

public:
    Fish() {
        id = 0;
        name = "";
        color = "";
        characteristic = "";
        categoryId = 0;
    }

    Fish(int id, string name, string color,
         string characteristic, int categoryId) {
        this->id = id;
        this->name = name;
        this->color = color;
        this->characteristic = characteristic;
        this->categoryId = categoryId;
    }

    // Getters
    int getId() {
        return id;
    }

    string getName() {
        return name;
    }

    string getColor() {
        return color;
    }

    string getCharacteristic() {
        return characteristic;
    }

    int getCategoryId() {
        return categoryId;
    }

    // Setters
    void setId(int id) {
        this->id = id;
    }

    void setName(string name) {
        this->name = name;
    }

    void setColor(string color) {
        this->color = color;
    }

    void setCharacteristic(string characteristic) {
        this->characteristic = characteristic;
    }

    void setCategoryId(int categoryId) {
        this->categoryId = categoryId;
    }