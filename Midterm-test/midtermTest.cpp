
#include <iostream>
#include <string>

using namespace std;

class Fish {
private:
    int id;
    string name;
    string color;
    string characteristic;

public:
    // Default constructor
    Fish() {
        id = 0;
        name = "";
        color = "";
        characteristic = "";
    }

    // Constructor with 1 parameter
    Fish(int i) {
        id = i;
        name = "";
        color = "";
        characteristic = "";
    }

    // Constructor with 2 parameters
    Fish(int i, string n) {
        id = i;
        name = n;
        color = "";
        characteristic = "";
    }

    // Constructor with 3 parameters
    Fish(int i, string n, string c) {
        id = i;
        name = n;
        color = c;
        characteristic = "";
    }

    // Constructor with 4 parameters
    Fish(int i, string n, string c, string ch) {
        id = i;
        name = n;
        color = c;
        characteristic = ch;
    }

    // Getter methods
    int getID() {
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

    // Setter methods
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

    // Display fish information
    void displayFishInfo() {
        cout << "ID             : " << id << endl;
        cout << "Name           : " << name << endl;
        cout << "Color          : " << color << endl;
        cout << "Characteristic : " << characteristic << endl;
        cout << "-----------------------------" << endl;
    }
};

int main() {
    // 1. Create 5 Fish objects using 5 different constructors
    Fish fish1;
    Fish fish2(113);
    Fish fish3(114, "Olise");
    Fish fish4(115, "Iniesta", "Blue");
    Fish fish5(116, "Musiala", "Red", "Curly Hair");

    // 2. Display information of all 5 objects
    cout << "===== 5 FISHES INFO =====" << endl;

    fish1.displayFishInfo();
    fish2.displayFishInfo();
    fish3.displayFishInfo();
    fish4.displayFishInfo();
    fish5.displayFishInfo();

    // 3. Update name, color, and characteristic of one object
    fish1.setName("Kevin");
    fish1.setColor("Purple");
    fish1.setCharacteristic("Wearing glasses");

    // 4. Use getters to retrieve and print updated information
    cout << "\n===== USING GETTERS TO GET FISH1 INFO =====" << endl;

    cout << "ID             : " << fish1.getID() << endl;
    cout << "Name           : " << fish1.getName() << endl;
    cout << "Color          : " << fish1.getColor() << endl;
    cout << "Characteristic : "
         << fish1.getCharacteristic() << endl;

    // 5. Display again to verify the changes
    cout << "\n===== CHECK FISH1 INFO =====" << endl;

    fish1.displayFishInfo();

    return 0;
}