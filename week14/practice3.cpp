
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// ==================== LOP CHA PRODUCT ====================
class Product {
protected:
    string id;
    string name;
    double price;
    int quantity;
    string date;

public:
    Product() {
        id = "";
        name = "";
        price = 0;
        quantity = 0;
        date = "";
    }

    Product(string id, string name, double price,
            int quantity, string date) {
        this->id = id;
        this->name = name;
        this->price = price;
        this->quantity = quantity;
        this->date = date;
    }

    virtual ~Product() {}

    virtual string getGroup() const = 0;
    virtual string getType() const = 0;

    virtual void input() {
        cout << "Nhap ma san pham: ";
        getline(cin >> ws, id);

        cout << "Nhap ten san pham: ";
        getline(cin, name);

        cout << "Nhap don gia: ";
        cin >> price;

        while (price < 0) {
            cout << "Don gia khong hop le. Nhap lai: ";
            cin >> price;
        }

        cout << "Nhap so luong ban: ";
        cin >> quantity;

        while (quantity < 0) {
            cout << "So luong khong hop le. Nhap lai: ";
            cin >> quantity;
        }

        cout << "Nhap ngay ban (dd/mm/yyyy): ";
        cin >> date;
    }

    virtual void display() const {
        cout << left
             << setw(12) << id
             << setw(18) << name
             << setw(12) << price
             << setw(12) << quantity
             << setw(15) << date
             << setw(15) << getRevenue()
             << setw(12) << getGroup()
             << '\n';
    }

    double getRevenue() const {
        return price * quantity;
    }

    string getDate() const {
        return date;
    }
};

// ==================== LOP CHA DRINKS ====================
class Drinks : public Product {
public:
    Drinks() : Product() {}

    string getGroup() const override {
        return "Drinks";
    }
};

// ==================== CAC LOAI DO UONG ====================
class Coffee : public Drinks {
public:
    string getType() const override {
        return "Coffee";
    }
};

class Tea : public Drinks {
public:
    string getType() const override {
        return "Tea";
    }
};

class Smoothies : public Drinks {
public:
    string getType() const override {
        return "Smoothies";
    }
};

class Juices : public Drinks {
public:
    string getType() const override {
        return "Juices";
    }
};

// ==================== LOP CHA FOODS ====================
class Foods : public Product {
public:
    Foods() : Product() {}

    string getGroup() const override {
        return "Foods";
    }
};

// ==================== CAC LOAI THUC AN ====================
class Cake : public Foods {
public:
    string getType() const override {
        return "Cake";
    }
};

class Breads : public Foods {
public:
    string getType() const override {
        return "Breads";
    }
};

// ==================== LOP QUAN LY ====================
class Shop {
private:
    vector<Product*> products;

public:
    ~Shop() {
        for (Product* p : products) {
            delete p;
        }
    }

    void addProduct() {
        int choice;
        Product* p = nullptr;

        cout << "\n===== CHON LOAI SAN PHAM =====\n";
        cout << "1. Coffee\n";
        cout << "2. Tea\n";
        cout << "3. Smoothies\n";
        cout << "4. Juices\n";
        cout << "5. Cake\n";
        cout << "6. Breads\n";
        cout << "Lua chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            p = new Coffee();
            break;
        case 2:
            p = new Tea();
            break;
        case 3:
            p = new Smoothies();
            break;
        case 4:
            p = new Juices();
            break;
        case 5:
            p = new Cake();
            break;
        case 6:
            p = new Breads();
            break;
        default:
            cout << "Loai san pham khong hop le!\n";
            return;
        }

        p->input();
        products.push_back(p);

        cout << "Them san pham thanh cong!\n";
    }

    void displayProducts() const {
        if (products.empty()) {
            cout << "Danh sach san pham rong!\n";
            return;
        }

        cout << "\n================ DANH SACH SAN PHAM ================\n";
        cout << left
             << setw(12) << "Ma"
             << setw(18) << "Ten"
             << setw(12) << "Don gia"
             << setw(12) << "So luong"
             << setw(15) << "Ngay ban"
             << setw(15) << "Doanh thu"
             << setw(12) << "Nhom"
             << '\n';

        for (const Product* p : products) {
            p->display();
        }
    }

    // Da hinh: tinh doanh thu theo nhom va ngay
    double calculateRevenue(
        const string& group,
        const string& date
    ) const {
        double total = 0;

        for (const Product* p : products) {
            if (p->getGroup() == group &&
                p->getDate() == date) {
                total += p->getRevenue();
            }
        }

        return total;
    }

    // Tinh doanh thu tung nhom theo ngay
    void revenueByDate() const {
        string date;

        cout << "Nhap ngay can thong ke (dd/mm/yyyy): ";
        cin >> date;

        double drinksRevenue =
            calculateRevenue("Drinks", date);

        double foodsRevenue =
            calculateRevenue("Foods", date);

        cout << fixed << setprecision(2);
        cout << "\n===== DOANH THU NGAY "
             << date << " =====\n";

        cout << "Drinks: "
             << drinksRevenue << '\n';

        cout << "Foods: "
             << foodsRevenue << '\n';

        cout << "Tong doanh thu: "
             << drinksRevenue + foodsRevenue << '\n';
    }

    void menu() {
        int choice;

        do {
            cout << "\n========== MENU ==========\n";
            cout << "1. Them san pham\n";
            cout << "2. Hien thi san pham\n";
            cout << "3. Tinh doanh thu theo ngay\n";
            cout << "0. Thoat\n";
            cout << "Nhap lua chon: ";
            cin >> choice;

            switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                revenueByDate();
                break;
            case 0:
                cout << "Ket thuc chuong trinh!\n";
                break;
            default:
                cout << "Lua chon khong hop le!\n";
            }
        } while (choice != 0);
    }
};

// ==================== HAM MAIN ====================
int main() {
    Shop shop;
    shop.menu();
    return 0;
}

