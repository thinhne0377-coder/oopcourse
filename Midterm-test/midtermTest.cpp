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

};

int main(){
    return 0;
}