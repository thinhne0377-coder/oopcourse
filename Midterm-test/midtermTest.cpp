
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

    // Constructor with parameters
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

    // Display category information
    void displayCategoryInfo() const {
        cout << "Category ID: " << categoryId
             << " | Name: " << categoryName
             << " | Description: " << description << endl;
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
        cout << "ID              : " << id << endl;
        cout << "Name            : " << name << endl;
        cout << "Color           : " << color << endl;
        cout << "Characteristic  : " << characteristic << endl;
        cout << "Category ID     : " << categoryId << endl;
        cout << "------------------------------" << endl;
    }
};

// ==================== MAIN FUNCTION ====================
int main() {
    // Create at least 3 categories
    vector<Category> categories = {
        Category(1, "Freshwater Fish", "Ca nuoc ngot"),
        Category(2, "Saltwater Fish", "Ca nuoc man"),
        Category(3, "Tropical Fish", "Ca nhiet doi")
    };

    // Create 5 original fish objects
    // Use different constructors
    vector<Fish> fishList = {
        Fish(),
        Fish(113),
        Fish(114, "Olise"),
        Fish(115, "Iniesta", "Blue"),
        Fish(116, "Musiala", "Red", "Curly Hair")
    };

    // Set information for the first 5 fish
    fishList[0].setID(100);
    fishList[0].setName("Kevin");
    fishList[0].setColor("Purple");
    fishList[0].setCharacteristic("Wearing glasses");
    fishList[0].setCategoryId(1);

    fishList[1].setName("Goldfish");
    fishList[1].setColor("Red");
    fishList[1].setCharacteristic("Friendly");
    fishList[1].setCategoryId(1);

    fishList[2].setColor("Blue");
    fishList[2].setCharacteristic("Small size");
    fishList[2].setCategoryId(2);

    fishList[3].setCharacteristic("Long fins");
    fishList[3].setCategoryId(3);

    fishList[4].setCategoryId(3);

    // Display the original 5 fish
    cout << "\n========== ORIGINAL 5 FISH ==========\n";

    for (const Fish& f : fishList) {
        f.displayFishInfo();
    }

    // Demonstrate getters and setters
    cout << "\n========== GETTER EXAMPLE ==========\n";
    cout << "Fish ID: " << fishList[0].getID() << endl;
    cout << "Fish Name: " << fishList[0].getName() << endl;
    cout << "Fish Color: " << fishList[0].getColor() << endl;
    cout << "Fish Characteristic: "
         << fishList[0].getCharacteristic() << endl;
    cout << "Fish Category ID: "
         << fishList[0].getCategoryId() << endl;

    // Question 6: Add 10 more ornamental fish
    fishList.push_back(
        Fish(101, "Betta", "Blue", "Beautiful fins", 3)
    );

    fishList.push_back(
        Fish(102, "Guppy", "Red", "Small size", 1)
    );

    fishList.push_back(
        Fish(103, "Angelfish", "Yellow", "Long fins", 3)
    );

    fishList.push_back(
        Fish(104, "Neon Tetra", "Blue", "Glowing body", 3)
    );

    fishList.push_back(
        Fish(105, "Clownfish", "Orange", "Active swimmer", 2)
    );

    fishList.push_back(
        Fish(106, "Blue Tang", "Blue", "Fast swimmer", 2)
    );

    fishList.push_back(
        Fish(107, "Discus", "Yellow", "Flat body", 3)
    );

    fishList.push_back(
        Fish(108, "Koi", "Orange", "Large size", 1)
    );

    fishList.push_back(
        Fish(109, "Molly", "Black", "Easy to care", 1)
    );

    fishList.push_back(
        Fish(110, "Swordtail", "Red", "Sword-shaped tail", 1)
    );

    // Display all 15 fish
    cout << "\n========== ALL FISH ==========\n";

    for (const Fish& f : fishList) {
        f.displayFishInfo();
    }

    // Question 6: Group and display fish by color
    cout << "\n========== GROUP FISH BY COLOR ==========\n";

    vector<string> colors;

    // Collect unique colors
    for (const Fish& f : fishList) {
        string currentColor = f.getColor();

        if (currentColor == "" || currentColor == "N/A") {
            continue;
        }

        bool exists = false;

        for (const string& c : colors) {
            if (c == currentColor) {
                exists = true;
                break;
            }
        }

        if (!exists) {
            colors.push_back(currentColor);
        }
    }

    // Display all fish of each color
    for (const string& color : colors) {
        cout << "\n--- COLOR: " << color << " ---\n";

        for (const Fish& f : fishList) {
            if (f.getColor() == color) {
                f.displayFishInfo();
            }
        }
    }

    // Question 7: Display all categories
    cout << "\n========== ALL CATEGORIES ==========\n";

    for (const Category& cat : categories) {
        cat.displayCategoryInfo();
    }

    // Question 7: Select a category and display its fish
    int selectedCatId;

    cout << "\nEnter Category ID to view fish (1-3): ";
    cin >> selectedCatId;

    bool categoryExists = false;
    bool fishFound = false;

    for (const Category& cat : categories) {
        if (cat.getCategoryId() == selectedCatId) {
            categoryExists = true;

            cout << "\n========== FISH IN CATEGORY: "
                 << cat.getCategoryName()
                 << " ==========\n";

            for (const Fish& f : fishList) {
                if (f.getCategoryId() == selectedCatId) {
                    f.displayFishInfo();
                    fishFound = true;
                }
            }

            break;
        }
    }

    if (!categoryExists) {
        cout << "Invalid Category ID!\n";
    } else if (!fishFound) {
        cout << "No fish found in this category!\n";
    }

    return 0;
}