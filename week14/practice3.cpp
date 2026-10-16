
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// ==================================================
// 1. CLASS DATE
// ==================================================
class Date {
private:
    int day, month, year;

public:
    Date() : day(1), month(1), year(2026) {}

    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    bool isValid() const {
        if (year < 1 || month < 1 || month > 12 || day < 1)
            return false;

        int days[] = {31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31};

        bool leap = (year % 400 == 0) ||
                    (year % 4 == 0 && year % 100 != 0);

        if (leap)
            days[1] = 29;

        return day <= days[month - 1];
    }

    void input() {
        do {
            cout << "Nhap ngay: ";
            cin >> day;
            cout << "Nhap thang: ";
            cin >> month;
            cout << "Nhap nam: ";
            cin >> year;

            if (!isValid())
                cout << "Ngay khong hop le, vui long nhap lai!\n";
        } while (!isValid());
    }

    void display() const {
        cout << setfill('0')
             << setw(2) << day << "/"
             << setw(2) << month << "/"
             << setw(4) << year
             << setfill(' ');
    }

    bool operator==(const Date& other) const {
        return day == other.day &&
               month == other.month &&
               year == other.year;
    }
};

// ==================================================
// 2. CLASS PRODUCT: LOP CHA TRUU TUONG
// ==================================================
class Product {
private:
    int id;
    string name;
    double price;

public:
    Product() : id(0), name(""), price(0) {}

    Product(int id, string name, double price)
        : id(id), name(name), price(price) {}

    int getId() const {
        return id;
    }

    string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

    virtual string getParent() const = 0;

    virtual void displayInfo() const {
        cout << "- " << name << endl;
    }

    virtual ~Product() = default;
};

// ==================================================
// 3. CLASS DRINK: LOP CON
// ==================================================
class Drink : public Product {
public:
    Drink() : Product() {}

    Drink(int id, string name, double price)
        : Product(id, name, price) {}

    string getParent() const override {
        return "Drinks";
    }

    void displayInfo() const override {
        cout << "- " << getName() << endl;
    }
};

// ==================================================
// 4. CLASS FOOD: LOP CON
// ==================================================
class Food : public Product {
public:
    Food() : Product() {}

    Food(int id, string name, double price)
        : Product(id, name, price) {}

    string getParent() const override {
        return "Foods";
    }

    void displayInfo() const override {
        cout << "- " << getName() << endl;
    }
};

// ==================================================
// 5. CLASS ORDER DETAIL
// ==================================================
class OrderDetail {
private:
    int productId;
    int quantity;

public:
    OrderDetail(int id, int q)
        : productId(id), quantity(q) {}

    int getProductId() const {
        return productId;
    }

    int getQuantity() const {
        return quantity;
    }
};

// ==================================================
// 6. CLASS ORDER
// ==================================================
class Order {
private:
    int orderId;
    Date date;
    vector<OrderDetail> details;

public:
    Order(int id, Date d) : orderId(id), date(d) {}

    int getOrderId() const {
        return orderId;
    }

    Date getDate() const {
        return date;
    }

    void addDetail(int productId, int quantity) {
        details.push_back(OrderDetail(productId, quantity));
    }

    const vector<OrderDetail>& getDetails() const {
        return details;
    }
};

// ==================================================
// 7. CLASS SHOP
// ==================================================
class Shop {
private:
    vector<Product*> products;
    vector<Order> orders;

public:
    ~Shop() {
        for (Product* p : products)
            delete p;
    }

    void addProduct(Product* p) {
        products.push_back(p);
    }

    Product* findProduct(int id) const {
        for (Product* p : products) {
            if (p->getId() == id)
                return p;
        }
        return nullptr;
    }

    // Da hinh: goi ham ao qua con tro lop cha
    void displayProducts() const {
        cout << "\nDrinks (Parent)\n";

        for (Product* p : products) {
            if (p->getParent() == "Drinks")
                p->displayInfo();
        }

        cout << "Foods (Parent)\n";

        for (Product* p : products) {
            if (p->getParent() == "Foods")
                p->displayInfo();
        }
    }

    void inputOrders() {
        int n;
        cout << "\nNhap so luong chi tiet ban hang: ";
        cin >> n;

        if (n < 0) {
            cout << "So luong khong hop le!\n";
            return;
        }

        for (int i = 0; i < n; i++) {
            int orderId, productId, quantity;
            Date date;

            cout << "\n--- Chi tiet ban hang " << i + 1 << " ---\n";
            cout << "Nhap ma don hang: ";
            cin >> orderId;

            cout << "Nhap ma san pham: ";
            cin >> productId;

            cout << "Nhap so luong: ";
            cin >> quantity;

            cout << "Nhap ngay ban:\n";
            date.input();

            if (quantity <= 0 || findProduct(productId) == nullptr) {
                cout << "Ma san pham hoac so luong khong hop le!\n";
                continue;
            }

            bool found = false;

            for (Order& order : orders) {
                if (order.getOrderId() == orderId &&
                    order.getDate() == date) {
                    order.addDetail(productId, quantity);
                    found = true;
                    break;
                }
            }

            if (!found) {
                Order newOrder(orderId, date);
                newOrder.addDetail(productId, quantity);
                orders.push_back(newOrder);
            }

            cout << "Them chi tiet don hang thanh cong!\n";
        }
    }

    // Tinh doanh thu theo nhom va ngay
    double calculateRevenue(string parent, Date date) const {
        double total = 0;

        for (const Order& order : orders) {
            if (!(order.getDate() == date))
                continue;

            for (const OrderDetail& detail : order.getDetails()) {
                Product* p = findProduct(detail.getProductId());

                if (p != nullptr && p->getParent() == parent) {
                    total += p->getPrice() * detail.getQuantity();
                }
            }
        }

        return total;
    }

    // Hien thi doanh thu theo ngay
    void displayRevenue(Date date) const {
        cout << "\n===\n";
        cout << "Tinh tong doanh thu theo ngay cua tung nhom tren\n";
        date.display();
        cout << "\n";

        cout << "- Drinks: "
             << fixed << setprecision(0)
             << calculateRevenue("Drinks", date) << " VND\n";

        cout << "- Foods: "
             << calculateRevenue("Foods", date) << " VND\n";
    }

    // Hien thi danh sach don hang
    void displayOrders() const {
        if (orders.empty()) {
            cout << "Chua co don hang nao!\n";
            return;
        }

        cout << "\n===== DANH SACH DON HANG =====\n";

        for (const Order& order : orders) {
            cout << "Ma don hang: " << order.getOrderId()
                 << " | Ngay: ";
            order.getDate().display();
            cout << endl;

            for (const OrderDetail& detail : order.getDetails()) {
                Product* p = findProduct(detail.getProductId());

                if (p != nullptr) {
                    cout << "  San pham: " << p->getName()
                         << " | So luong: " << detail.getQuantity()
                         << " | Thanh tien: "
                         << fixed << setprecision(0)
                         << p->getPrice() * detail.getQuantity()
                         << " VND\n";
                }
            }
        }
    }
};

// ==================================================
// 8. HAM MAIN
// ==================================================
int main() {
    Shop shop;

    // Drinks
    shop.addProduct(new Drink(1, "Coffee", 25000));
    shop.addProduct(new Drink(2, "Tea", 20000));
    shop.addProduct(new Drink(3, "Smoothies", 35000));
    shop.addProduct(new Drink(4, "Juices", 30000));

    // Foods
    shop.addProduct(new Food(5, "Cake", 40000));
    shop.addProduct(new Food(6, "Breads", 15000));

    int choice;

    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Hien thi danh sach san pham\n";
        cout << "2. Nhap don hang\n";
        cout << "3. Hien thi danh sach don hang\n";
        cout << "4. Tinh doanh thu theo ngay\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            shop.displayProducts();
            break;

        case 2:
            shop.inputOrders();
            break;

        case 3:
            shop.displayOrders();
            break;

        case 4: {
            Date date;
            cout << "Nhap ngay can tinh doanh thu:\n";
            date.input();
            shop.displayRevenue(date);
            break;
        }

        case 0:
            cout << "Ket thuc chuong trinh!\n";
            break;

        default:
            cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 0);

    return 0;
}


