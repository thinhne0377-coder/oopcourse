
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// ==================================================
// 1. CLASS DATE: QUAN LY NGAY, THANG, NAM
// ==================================================
class Date {
private:
    int day, month, year;

public:
    Date() {
        day = 1;
        month = 1;
        year = 2026;
    }

    Date(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    bool isValid() const {
        if (year < 1 || month < 1 || month > 12 || day < 1)
            return false;

        int daysInMonth[] = {
            31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };

        bool leapYear = (year % 400 == 0) ||
                        (year % 4 == 0 && year % 100 != 0);

        if (leapYear)
            daysInMonth[1] = 29;

        return day <= daysInMonth[month - 1];
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
                cout << "Ngay thang nam khong hop le! Nhap lai.\n";

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
protected:
    int id;
    string name;
    double price;

public:
    Product() : id(0), name(""), price(0) {}

    Product(int id, string name, double price) {
        this->id = id;
        this->name = name;
        this->price = price;
    }

    virtual ~Product() {}

    int getId() const { return id; }
    string getName() const { return name; }
    double getPrice() const { return price; }

    // Ham thuan ao
    virtual string getParent() const = 0;

    // Ham ao
    virtual void displayInfo() const {
        cout << "ID: " << id
             << " | Ten: " << name
             << " | Gia: " << fixed << setprecision(0)
             << price << " VND"
             << " | Nhom: " << getParent() << endl;
    }
};

// ==================================================
// 3. CLASS DRINK: KE THUA PRODUCT
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
        cout << "[DRINK] ";
        Product::displayInfo();
    }
};

// ==================================================
// 4. CLASS FOOD: KE THUA PRODUCT
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
        cout << "[FOOD] ";
        Product::displayInfo();
    }
};

// ==================================================
// 5. CLASS ORDER DETAIL: CHI TIET DON HANG
// ==================================================
class OrderDetail {
private:
    int productId;
    int quantity;

public:
    OrderDetail(int productId, int quantity) {
        this->productId = productId;
        this->quantity = quantity;
    }

    int getProductId() const { return productId; }
    int getQuantity() const { return quantity; }
};

// ==================================================
// 6. CLASS ORDER: DON HANG
// ==================================================
class Order {
private:
    int orderId;
    Date date;
    vector<OrderDetail> details;

public:
    Order(int orderId, Date date) {
        this->orderId = orderId;
        this->date = date;
    }

    int getOrderId() const { return orderId; }
    Date getDate() const { return date; }

    void addDetail(int productId, int quantity) {
        details.push_back(OrderDetail(productId, quantity));
    }

    const vector<OrderDetail>& getDetails() const {
        return details;
    }

    void displayInfo() const {
        cout << "Ma don hang: " << orderId << " | Ngay: ";
        date.display();
        cout << endl;
    }
};

// ==================================================
// 7. CLASS SHOP: QUAN LY SAN PHAM VA DOANH THU
// ==================================================
class Shop {
private:
    vector<Product*> products;
    vector<Order> orders;

public:
    // Giai phong bo nho san pham
    ~Shop() {
        for (Product* p : products)
            delete p;
    }

    // Them san pham
    void addProduct(Product* p) {
        products.push_back(p);
    }

    // Them don hang
    void addOrder(const Order& order) {
        orders.push_back(order);
    }

    // Tim san pham theo ma
    Product* findProduct(int id) const {
        for (Product* p : products) {
            if (p->getId() == id)
                return p;
        }
        return nullptr;
    }

    // Hien thi danh sach san pham
    void displayProducts() const {
        cout << "\n========== DRINKS (PARENT) ==========\n";

        for (Product* p : products) {
            if (p->getParent() == "Drinks")
                p->displayInfo();
        }

        cout << "\n========== FOODS (PARENT) ==========\n";

        for (Product* p : products) {
            if (p->getParent() == "Foods")
                p->displayInfo();
        }
    }

    // MINH HOA TINH DA HINH
    void demonstratePolymorphism() const {
        cout << "\n===== DEMONSTRATE POLYMORPHISM =====\n";

        for (Product* p : products) {
            // Goi ham ao qua con tro lop cha.
            // Chuong trinh tu chon Drink hay Food khi chay.
            p->displayInfo();
        }
    }

    // Them chi tiet don hang
    bool addOrderDetail(int orderId, int productId,
                        int quantity, Date date) {
        if (!date.isValid() || quantity <= 0 ||
            findProduct(productId) == nullptr) {
            return false;
        }

        for (Order& order : orders) {
            if (order.getOrderId() == orderId &&
                order.getDate() == date) {
                order.addDetail(productId, quantity);
                return true;
            }
        }

        Order newOrder(orderId, date);
        newOrder.addDetail(productId, quantity);
        addOrder(newOrder);

        return true;
    }

    // Nhap danh sach don hang
    void inputOrders() {
        int n;

        cout << "Nhap so luong chi tiet ban hang: ";
        cin >> n;

        if (cin.fail() || n < 0) {
            cin.clear();
            cin.ignore(10000, '\n');
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

            if (addOrderDetail(orderId, productId, quantity, date)) {
                cout << "Them chi tiet don hang thanh cong!\n";
            } else {
                cout << "Khong them duoc don hang! "
                     << "Kiem tra ma san pham va so luong.\n";
            }
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
        cout << fixed << setprecision(0);

        cout << "\n====================================\n";
        cout << "DOANH THU NGAY ";
        date.display();
        cout << "\n====================================\n";

        cout << "- Drinks: "
             << calculateRevenue("Drinks", date)
             << " VND\n";

        cout << "- Foods: "
             << calculateRevenue("Foods", date)
             << " VND\n";

        cout << "- Tong doanh thu: "
             << calculateRevenue("Drinks", date)
                + calculateRevenue("Foods", date)
             << " VND\n";

        cout << "====================================\n";
    }

    // Hien thi danh sach don hang
    void displayOrders() const {
        if (orders.empty()) {
            cout << "Chua co don hang nao!\n";
            return;
        }

        cout << "\n========== DANH SACH DON HANG ==========\n";

        for (const Order& order : orders) {
            order.displayInfo();

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

    // Them cac loai Drinks
    shop.addProduct(new Drink(1, "Coffee", 25000));
    shop.addProduct(new Drink(2, "Tea", 20000));
    shop.addProduct(new Drink(3, "Smoothies", 35000));
    shop.addProduct(new Drink(4, "Juices", 30000));

    // Them cac loai Foods
    shop.addProduct(new Food(5, "Cake", 40000));
    shop.addProduct(new Food(6, "Breads", 15000));

    int choice;

    do {
        cout << "\n============== MENU ==============\n";
        cout << "1. Hien thi danh sach san pham\n";
        cout << "2. Nhap don hang\n";
        cout << "3. Hien thi danh sach don hang\n";
        cout << "4. Tinh doanh thu theo ngay\n";
        cout << "5. Minh hoa tinh da hinh\n";
        cout << "0. Thoat\n";
        cout << "==================================\n";
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
            cout << "\nNhap ngay can tinh doanh thu:\n";
            date.input();
            shop.displayRevenue(date);
            break;
        }

        case 5:
            shop.demonstratePolymorphism();
            break;

        case 0:
            cout << "Ket thuc chuong trinh!\n";
            break;

        default:
            cout << "Lua chon khong hop le!\n";
        }

    } while (choice != 0);

    return 0;
}

