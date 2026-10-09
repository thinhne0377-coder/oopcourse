#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Fish {
private:
    int id;
    string name;
    string color;
    string characteristic;
public:
    // Constructors: các hàm khởi tạo dữ liệu
    Fish(){
        id = 0;
        name = "";
        color = "";
        characteristic = "";
    }
    // A constructor with 1 parameter
    Fish (int i){
        id = i;
        name = "";
        color = "";
        characteristic = "";
    }
    // A constructor with 2 parameters
    Fish (int i, string n){
        id = i;
        name = n;
        color = "";
        characteristic = "";
    }
    // A constructor with 3 parameters
    Fish (int i, string n, string c){
        id = i;
        name = n;
        color = c;
        characteristic = "";
    }
    // A constructor with all 4 parameters
    Fish (int i, string n, string c, string ch){
        id = i;
        name = n;
        color = c;
        characteristic = ch;
    }

    // Getter
    int getID () {return id;}
    string getName () {return name;}
    string getColor () {return color;}
    string getCharacteristic () {return characteristic;}

    // Setter
    void setID (int i) {id = i;}
    void setName (string n) {name = n;}
    void setColor (string c) {color = c;}
    void setCharacteristic (string ch) {characteristic = ch;}

    // Display
    void displayFishInfo(){
        cout << " ID               : " << id << endl;
        cout << " | Name           : " << name << endl;
        cout << " | Color          : " << color << endl;
        cout << " | Characteristic : " << characteristic << endl;   
    }
};

int main(){
    // 1. Create 5 Fish objects
    Fish fish1;
    Fish fish2 (113);
    Fish fish3 (114, "Olise");
    Fish fish4 (115, "Iniesta", "Blue");
    Fish fish5 (116, "Musiala", "Red", "Curly Hair");

    // 2. Call displayFishInfo() to display the information of all 5 objects.
    cout << "===== 5 FISHES INFO =====" << endl;
    fish1.displayFishInfo();
    fish2.displayFishInfo();
    fish3.displayFishInfo();
    fish4.displayFishInfo();
    fish5.displayFishInfo();

    // 3. Use the setter methods to update the name, color, and characteristics of one object
    fish1.setID (100);
    fish1.setName ("Kevin");
    fish1.setColor ("Purple");
    fish1.setCharacteristic ("Wearing glasses");

    // 4. Use the getter methods to retrieve and print the information of the updated object.
    cout << "\n ===== USING GETTER TO GET FISH1 INFO =====" << endl;
    cout << " ID            : " << fish1.getID() << endl;
    cout << " Name          : " << fish1.getName() << endl;
    cout << " Color         : " << fish1.getColor() << endl;
    cout << " Characteristc : " << fish1.getCharacteristic() << endl;

    // 5. Call displayFishInfo() again to verify the changes.
    cout << "\n === CHECK FISH1 INFO BY displayFishInfo() ===" << endl;
    fish1.displayFishInfo();
    
    return 0;
}