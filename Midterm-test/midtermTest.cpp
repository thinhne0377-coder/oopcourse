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
    int getID () const {return id;}
    string getName () const {return name;}
    string getColor () const {return color;}
    string getCharacteristic () const {return characteristic;}

    // Setter
    void setID (int i) {id = i;}
    void setName (string n) {name = n;}
    void setColor (string c) {color = c;}
    void setCharacteristic (string ch) {characteristic = ch;}

    // Display
    void displayFishInfo() const {
        cout << " ID               : " << id << endl;
        cout << " | Name           : " << name << endl;
        cout << " | Color          : " << color << endl;
        cout << " | Characteristic : " << characteristic << endl;   
    }
};

int main(){
    // 5 ca ban dau
    vector<Fish> fishList = {
        Fish(100, "Kevin", "Purple", "Wearing glasses"),
        Fish(113, "N/A", "N/A", "N/A"),
        Fish(114, "Olise", "N/A", "N/A"),
        Fish(115, "Iniesta", "Blue", "N/A"),
        Fish(116, "Musiala", "Red", "Curly Hair")
    };

    // Q6: Them 10 loai ca canh moi
    fishList.push_back(Fish(101, "Goldfish", "Red", "Friendly"));
    fishList.push_back(Fish(102, "Betta", "Blue", "Aggressive"));
    fishList.push_back(Fish(103, "Guppy", "Red", "Small size"));
    fishList.push_back(Fish(104, "Angelfish", "Yellow", "Long fins"));
    fishList.push_back(Fish(105, "Neon Tetra", "Blue", "Glowing body"));
    fishList.push_back(Fish(106, "Clownfish", "Orange", "Active"));
    fishList.push_back(Fish(107, "Blue Tang", "Blue", "Fast swimmer"));
    fishList.push_back(Fish(108, "Discus", "Yellow", "Flat body"));
    fishList.push_back(Fish(109, "Koi", "Orange", "Large size"));
    fishList.push_back(Fish(110, "Molly", "Black", "Easy to care"));

    // Q6: Nhom va hien thi ca theo mau sac
    cout << "\n===== GROUP FISH BY COLOR =====\n";
    vector<string> colors;
    for (const Fish& f : fishList) {
        bool exists = false;
        for (const string& c : colors) {
            if (c == f.getColor()) {
                exists = true;
                break;
            }
        }
        if (!exists && f.getColor() != "" && f.getColor() != "N/A") {
            colors.push_back(f.getColor());
        }
    }

    for (const string& color : colors) {
        cout << "\n--- COLOR: " << color << " ---\n";
        for (const Fish& f : fishList) {
            if (f.getColor() == color) {
                f.displayFishInfo();
            }
        }
    }

    return 0;
}