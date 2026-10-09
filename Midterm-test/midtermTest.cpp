
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ==================== CLASS CATEGORY ====================
class Category {
private:
    int categoryId;
    string categoryName;
    string description;

public:
    // Default constructor
    Category() {
        categoryId = 0;
        categoryName = "";
        description = "";
    }

    // Constructor with 3 parameters
    Category(int id, string name, string desc) {
        categoryId = id;
        categoryName = name;
        description = desc;
    }

    // Getter
    int getCategoryId() const {
        return categoryId;
    }

    string getCategoryName() const {
        return categoryName;
    }

    string getDescription() const {
        return description;
    }

    // Setter
    void setCategoryId(int id) {
        categoryId = id;
    }

    void setCategoryName(string name) {
        categoryName = name;
    }

    void setDescription(string desc) {
        description = desc;
    }

    // Display
    void displayCategoryInfo() const {
        cout << "Category ID   : " << categoryId << endl;
        cout << "Category Name : " << categoryName << endl;
        cout << "Description   : " << description << endl;
        cout << "-----------------------------------" << endl;
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
    // Default constructor
    Fish() {
        id = 0;
        name = "";
        color = "";
        characteristic = "";
        categoryId = 0;
    }

    // Constructor with 1 parameter
    Fish(int i) {
        id = i;
        name = "";
        color = "";
        characteristic = "";
        categoryId = 0;
    }

    // Constructor with 2 parameters
    Fish(int i, string n) {
        id = i;
        name = n;
        color = "";
        characteristic = "";
        categoryId = 0;
    }

    // Constructor with 3 parameters
    Fish(int i, string n, string c) {
        id = i;
        name = n;
        color = c;
        characteristic = "";
        categoryId = 0;
    }

    // Constructor with 4 parameters
    Fish(int i, string n, string c, string ch) {
        id = i;
        name = n;
        color = c;
        characteristic = ch;
        categoryId = 0;
    }

    // Constructor with 5 parameters
    Fish(int i, string n, string c, string ch, int catId) {
        id = i;
        name = n;
        color = c;
        characteristic = ch;
        categoryId = catId;
    }

    // Getter
    int getID() const {
        return id;
    }

    string getName() const {
        return name;
    }

    string getColor() const {
        return color;
    }

    string getCharacteristic() const {
        return characteristic;
    }

    int getCategoryId() const {
        return categoryId;
    }

    // Setter
    void setID(int i) {
        id = i;
    }

    void setName(string n) {
        name = n;
    }

    void setColor(string c) {
        color = c;
    }

    void setCharacteristic(string ch) {
        characteristic = ch;
    }

    void setCategoryId(int catId) {
        categoryId = catId;
    }

    // Display fish information
    void displayFishInfo() const {
        cout << "Fish ID         : " << id << endl;
        cout << "Fish Name       : " << name << endl;
        cout << "Fish Color      : " << color << endl;
        cout << "Characteristic  : " << characteristic << endl;
        cout << "Category ID     : " << categoryId << endl;
        cout << "-----------------------------------" << endl;
    }
};

// ==================== MAIN ====================
int main() {
    // QUESTION 1-5:
    // Create 5 fish using 5 different constructors
    Fish fish1;
    Fish fish2(113);
    Fish fish3(114, "Olise");
    Fish fish4(115, "Iniesta", "Blue");
    Fish fish5(116, "Musiala", "Red", "Curly Hair");

    // Assign category IDs
    fish1.setCategoryId(1);
    fish2.setCategoryId(1);
    fish3.setCategoryId(2);
    fish4.setCategoryId(3);
    fish5.setCategoryId(3);

    // Display original information
    cout << "========== FIVE FISHES INFO ==========" << endl;

    fish1.displayFishInfo();
    fish2.displayFishInfo();
    fish3.displayFishInfo();
    fish4.displayFishInfo();
    fish5.displayFishInfo();

    // Update information using setters
    cout << "\n========== UPDATE FISH1 ==========" << endl;

    fish1.setID(100);
    fish1.setName("Kevin");
    fish1.setColor("Purple");
    fish1.setCharacteristic("Wearing glasses");

    // Retrieve updated information using getters
    cout << "\n========== USING GETTERS ==========" << endl;

    cout << "ID             : " << fish1.getID() << endl;
    cout << "Name           : " << fish1.getName() << endl;
    cout << "Color          : " << fish1.getColor() << endl;
    cout << "Characteristic : "
         << fish1.getCharacteristic() << endl;

    // Display again to verify changes
    cout << "\n========== VERIFY UPDATED FISH1 ==========" << endl;
    fish1.displayFishInfo();

    // ==================== QUESTION 6 ====================
    // Create a list containing the first 5 fish
    vector<Fish> fishList;

    fishList.push_back(fish1);
    fishList.push_back(fish2);
    fishList.push_back(fish3);
    fishList.push_back(fish4);
    fishList.push_back(fish5);

    // Add 10 more ornamental fish
    fishList.push_back(
        Fish(101, "Goldfish", "Red", "Friendly", 1));

    fishList.push_back(
        Fish(102, "Betta", "Blue", "Aggressive", 3));

    fishList.push_back(
        Fish(103, "Guppy", "Red", "Small size", 1));

    fishList.push_back(
        Fish(104, "Angelfish", "Yellow", "Long fins", 3));

    fishList.push_back(
        Fish(105, "Neon Tetra", "Blue", "Glowing body", 3));

    fishList.push_back(
        Fish(106, "Clownfish", "Orange", "Active", 2));

    fishList.push_back(
        Fish(107, "Blue Tang", "Blue", "Fast swimmer", 2));

    fishList.push_back(
        Fish(108, "Discus", "Yellow", "Flat body", 3));

    fishList.push_back(
        Fish(109, "Koi", "Orange", "Large size", 1));

    fishList.push_back(
        Fish(110, "Molly", "Black", "Easy to care for", 1));

    // Display all 15 fish
    cout << "\n========== QUESTION 6: ALL FISH ==========" << endl;

    for (const Fish& f : fishList) {
        f.displayFishInfo();
    }

    // Group and display fish by color
    cout << "\n========== GROUP FISH BY COLOR ==========" << endl;

    vector<string> colors;

    // Collect unique colors
    for (const Fish& f : fishList) {
        bool exists = false;

        for (const string& c : colors) {
            if (c == f.getColor()) {
                exists = true;
                break;
            }
        }

        if (!exists && f.getColor() != "") {
            colors.push_back(f.getColor());
        }
    }

    // Display fish in each color group
    for (const string& color : colors) {
        cout << "\n--- COLOR: " << color << " ---" << endl;

        for (const Fish& f : fishList) {
            if (f.getColor() == color) {
                cout << "ID: " << f.getID()
                     << " | Name: " << f.getName()
                     << " | Color: " << f.getColor()
                     << endl;
            }
        }
    }

    // ==================== QUESTION 7 ====================
    // Create at least 3 categories
    vector<Category> categories;

    categories.push_back(
        Category(1, "Freshwater Fish", "Ca nuoc ngot"));

    categories.push_back(
        Category(2, "Saltwater Fish", "Ca nuoc man"));

    categories.push_back(
        Category(3, "Tropical Fish", "Ca nhiet doi"));

    // Display all categories
    cout << "\n========== ALL CATEGORIES ==========" << endl;

    for (const Category& cat : categories) {
        cat.displayCategoryInfo();
    }

    // Select a category using keyboard input
    int selectedCatId;

    cout << "\nEnter category ID (1-3): ";
    cin >> selectedCatId;

    bool categoryFound = false;

    for (const Category& cat : categories) {
        if (cat.getCategoryId() == selectedCatId) {
            categoryFound = true;

            cout << "\n========== SELECTED CATEGORY ==========" << endl;
            cat.displayCategoryInfo();

            cout << "\n========== FISH IN THIS CATEGORY ==========" << endl;

            bool fishFound = false;

            for (const Fish& f : fishList) {
                if (f.getCategoryId() == selectedCatId) {
                    f.displayFishInfo();
                    fishFound = true;
                }
            }

            if (!fishFound) {
                cout << "No fish in this category." << endl;
            }

            break;
        }
    }

    if (!categoryFound) {
        cout << "Category not found!" << endl;
    }

    return 0;
}