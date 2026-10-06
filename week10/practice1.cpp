#include <iostream>
#include <string>
#include <algorithm>  
using namespace std;

#define MAX 100

class Food {
public:
    string id;
    string name;
    double price;
    int quantity;

    void inputSingle() {
        cin.ignore(); 
        cout << "Food's id: ";
        getline(cin, id);

        cout << "Food's name: ";
        getline(cin, name);

        cout << "Food's price: ";
        cin >> price;

        cout << "Quantity: ";
        cin >> quantity;
    }

    void displaySingle(int index) {
        cout << "Food " << index << ": " << endl;
        cout << "  ID         : " << id << endl;
        cout << "  Name       : " << name << endl;
        cout << "  Price      : " << price << endl;
        cout << "  Quantity   : " << quantity << endl;
    }
};

class FoodManager {
    int foodCount  = 0;
    Food foods[MAX];

public:
    void inputList() {
        cout << "Enter the number of food: ";
        cin >> foodCount;

        if (foodCount > MAX) {
            cout << "Exceeds maximum limit! Setting count to " << MAX << endl;
            foodCount = MAX;
        }

        for (int i = 0; i < foodCount; i++) {
            cout << "\nInput food " << i + 1 << ": " << endl;
            foods[i].inputSingle();
        }
    }

    void displayList() {
        cout << "\n***********************" << endl;
        if (foodCount == 0) {
            cout << "No food available in the list." << endl;
        } else {
            for (int i = 0; i < foodCount; i++) {
                foods[i].displaySingle(i + 1);
                cout << "-----------------------" << endl;
            }
        }
        cout << "***********************" << endl;
    }

    int findFoodIndex(string key) {
        cout << "Enter the id or name of the food u wanna find: ";
        getline (cin, key);
        for (int i = 0; i < foodCount; i++) {
            if (foods[i].id == key ||(foods[i].name) == key) {
                return i; 
            }
        }
        return -1; // Không tìm thấy
    }

    // Hàm cập nhật giá và số lượng món ăn
    void updateFood(string key) {
        int idx = findFoodIndex(key);
        if (idx != -1) {
            cout << "\n --> Food found: " << foods[idx].name << endl;
            
            cout << "Enter new price: ";
            cin >> foods[idx].price;

            cout << "Enter new quantity: ";
            cin >> foods[idx].quantity;

            cout << " --> Updated food info successfully!" << endl;
        } else {
            cout << " --> Food not found!" << endl;
        }
    }
};

int main() {
    FoodManager manager; // Tạo đối tượng quản lý

    cout << "===========================" << endl;
    cout << "  FOOD MANAGEMENT SYSTEM   " << endl;
    cout << "===========================" << endl;

    // 1. Nhập danh sách món ăn
    manager.inputList();

    // 2. Hiển thị danh sách vừa nhập
    manager.displayList();

    // 3. Thử nghiệm tính năng Tìm kiếm & Cập nhật
    string searchKey;
    cin.ignore(); // Xóa bộ nhớ đệm
    cout << "\nEnter ID or Name of food to update: ";
    getline(cin, searchKey);

    manager.updateFood(searchKey);

    // 4. Hiển thị lại danh sách sau khi cập nhật
    cout << "\n--- List after update ---";
    manager.displayList();

    return 0;
}