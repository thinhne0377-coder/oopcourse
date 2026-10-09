
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

    // Input fish information
    void input(int fishId, int categoryId) {
        id = fishId;
        this->categoryId = categoryId;

        cout << "Enter fish name: ";
        getline(cin >> ws, name);

        cout << "Enter fish color: ";
        getline(cin, color);

        cout << "Enter fish characteristic: ";
        getline(cin, characteristic);
    }

    // Display fish information
    void displayFishInfo() {
        cout << "Fish ID: " << id << endl;
        cout << "Fish name: " << name << endl;
        cout << "Color: " << color << endl;
        cout << "Characteristic: " << characteristic << endl;
        cout << "Category ID: " << categoryId << endl;
    }
};

// ==================== CLASS CATEGORY ====================
class Category {
private:
    int categoryId;
    string categoryName;
    string description;

public:
    Category() {
        categoryId = 0;
        categoryName = "";
        description = "";
    }

    Category(int id, string name, string description) {
        categoryId = id;
        categoryName = name;
        this->description = description;
    }

    // Getters
    int getCategoryId() {
        return categoryId;
    }

    string getCategoryName() {
        return categoryName;
    }

    string getDescription() {
        return description;
    }

    // Setters
    void setCategoryId(int id) {
        categoryId = id;
    }

    void setCategoryName(string name) {
        categoryName = name;
    }

    void setDescription(string description) {
        this->description = description;
    }

    // Input category information
    void input(int id) {
        categoryId = id;

        cout << "Enter category name: ";
        getline(cin >> ws, categoryName);

        cout << "Enter category description: ";
        getline(cin, description);
    }

    // Display category information
    void displayCategoryInfo() {
        cout << "Category ID: " << categoryId << endl;
        cout << "Category name: " << categoryName << endl;
        cout << "Description: " << description << endl;
    }
};

// ==================== CLASS FISHSHOP ====================
class FishShop {
private:
    int id;
    string name;
    string address;
    string owner;
    Date startdate;
    Category categories[4];
    Fish fishes[40];

public:
    // Default constructor
    FishShop() {
        id = 0;
        name = "";
        address = "";
        owner = "";
    }

    // Getters
    int getId() {
        return id;
    }

    string getName() {
        return name;
    }

    string getAddress() {
        return address;
    }

    string getOwner() {
        return owner;
    }

    Date getStartdate() {
        return startdate;
    }

    Category getCategory(int index) {
        if (index >= 0 && index < 4) {
            return categories[index];
        }
        return Category();
    }

    Fish getFish(int index) {
        if (index >= 0 && index < 40) {
            return fishes[index];
        }
        return Fish();
    }

    // Setters
    void setId(int id) {
        this->id = id;
    }

    void setName(string name) {
        this->name = name;
    }

    void setAddress(string address) {
        this->address = address;
    }

    void setOwner(string owner) {
        this->owner = owner;
    }

    void setStartdate(Date startdate) {
        this->startdate = startdate;
    }

    void setCategory(int index, Category category) {
        if (index >= 0 && index < 4) {
            categories[index] = category;
        }
    }

    void setFish(int index, Fish fish) {
        if (index >= 0 && index < 40) {
            fishes[index] = fish;
        }
    }

    // Input shop information
    void inputShopInfo() {
        cout << "\n===== INPUT FISH SHOP INFORMATION =====" << endl;

        cout << "Enter shop ID: ";
        cin >> id;

        cout << "Enter shop name: ";
        getline(cin >> ws, name);

        cout << "Enter shop address: ";
        getline(cin, address);

        cout << "Enter shop owner: ";
        getline(cin, owner);

        cout << "Enter shop start date:" << endl;
        startdate.input();
    }

    // Input 4 categories and 10 fish per category
    void inputCategoriesAndFishes() {
        cout << "\n===== INPUT 4 CATEGORIES =====" << endl;

        for (int i = 0; i < 4; i++) {
            cout << "\n--- Category " << i + 1 << " ---" << endl;
            categories[i].input(i + 1);
        }

        int fishId = 1;

        cout << "\n===== INPUT FISH INFORMATION =====" << endl;

        for (int i = 0; i < 4; i++) {
            cout << "\nCATEGORY: "
                 << categories[i].getCategoryName() << endl;

            for (int j = 0; j < 10; j++) {
                cout << "\n--- Fish " << fishId
                     << " of category "
                     << categories[i].getCategoryId()
                     << " ---" << endl;

                fishes[fishId - 1].input(
                    fishId,
                    categories[i].getCategoryId()
                );

                fishId++;
            }
        }
    }

    // Display shop information
    void displayInfo() {
        cout << "\n========================================" << endl;
        cout << "       FISH SHOP INFORMATION" << endl;
        cout << "========================================" << endl;

        cout << "Shop ID: " << id << endl;
        cout << "Shop name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Owner: " << owner << endl;
        cout << "Start date: ";
        startdate.display();
        cout << endl;
    }

    // Display all categories
    void displayCategories() {
        cout << "\n===== CATEGORY INFORMATION =====" << endl;

        for (int i = 0; i < 4; i++) {
            cout << "\n--- Category " << i + 1 << " ---" << endl;
            categories[i].displayCategoryInfo();
        }
    }

    // Display all fish
    void displayFishes() {
        cout << "\n===== ALL FISH INFORMATION =====" << endl;

        for (int i = 0; i < 40; i++) {
            cout << "\n--- Fish " << i + 1 << " ---" << endl;
            fishes[i].displayFishInfo();
        }
    }

    // Display fish belonging to a category
    void displayFishByCategory(int selectedCategoryId) {
        bool found = false;

        cout << "\n===== FISH IN CATEGORY "
             << selectedCategoryId << " =====" << endl;

        for (int i = 0; i < 40; i++) {
            if (fishes[i].getCategoryId() == selectedCategoryId) {
                fishes[i].displayFishInfo();
                cout << "------------------------" << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "No fish found in this category." << endl;
        }
    }
};

// ==================== MAIN FUNCTION ====================
int main() {
    FishShop shop;

    // 1. Create a fish shop and input its information
    shop.inputShopInfo();

    // 2. Input 4 categories and 10 fish for each category
    shop.inputCategoriesAndFishes();

    // 3. Display shop information
    shop.displayInfo();

    // 4. Display all categories
    shop.displayCategories();

    // 5. Display all 40 fish
    shop.displayFishes();

    // 6. Select a category and display its fish
    int selectedCategoryId;

    cout << "\nEnter category ID to view its fish (1-4): ";
    cin >> selectedCategoryId;

    if (selectedCategoryId >= 1 && selectedCategoryId <= 4) {
        shop.displayFishByCategory(selectedCategoryId);
    } else {
        cout << "Invalid category ID!" << endl;
    }

    return 0;
}