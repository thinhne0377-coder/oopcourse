
#include <iostream>
#include <string>
#include <clocale>
using namespace std;

#define MAX 100

// ==================== CLASS DATE ====================
class Date {
private:
    int year, month, day;

public:
    Date() {
        year = 0;
        month = 0;
        day = 0;
    }

    Date(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }

    int getYear() { return year; }
    int getMonth() { return month; }
    int getDay() { return day; }

    void setYear(int y) { year = y; }
    void setMonth(int m) { month = m; }
    void setDay(int d) { day = d; }
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
    Fish() {
        id = 0;
        name = "";
        color = "";
        characteristic = "";
        categoryId = 0;
    }

    Fish(int i, string n, string c, string ch, int catId) {
        id = i;
        name = n;
        color = c;
        characteristic = ch;
        categoryId = catId;
    }

    int getId() { return id; }
    string getName() { return name; }
    string getColor() { return color; }
    string getCharacteristic() { return characteristic; }
    int getCategoryId() { return categoryId; }

    void setId(int i) { id = i; }
    void setName(string n) { name = n; }
    void setColor(string c) { color = c; }
    void setCharacteristic(string ch) {
        characteristic = ch;
    }
    void setCategoryId(int catId) {
        categoryId = catId;
    }

    void displayFishInfo() {
        cout << "Ma ca       : " << id << endl;
        cout << "Ten ca      : " << name << endl;
        cout << "Mau sac     : " << color << endl;
        cout << "Dac diem    : " << characteristic << endl;
        cout << "Ma danh muc : " << categoryId << endl;
    }
};

// ==================== CLASS CATEGORY ====================
class Category {
private:
    int categoryId;
    string categoryName;
    string description;

public:
    Category() {
        categoryId = 0;
        categoryName = "";
        description = "";
    }

    Category(int id, string name, string desc) {
        categoryId = id;
        categoryName = name;
        description = desc;
    }

    int getCategoryId() { return categoryId; }
    string getCategoryName() { return categoryName; }
    string getDescription() { return description; }

    void setCategoryId(int id) {
        categoryId = id;
    }

    void setCategoryName(string name) {
        categoryName = name;
    }

    void setDescription(string desc) {
        description = desc;
    }

    void displayCategoryInfo() {
        cout << "Ma danh muc : " << categoryId << endl;
        cout << "Ten danh muc: " << categoryName << endl;
        cout << "Mo ta       : " << description << endl;
    }
};

// ==================== CLASS FISHSHOP ====================
class FishShop {
private:
    int id;
    string name;
    string address;
    string owner;
    Date startdate;

    Category categories[MAX];
    Fish fishes[MAX];

    int soDanhMuc;
    int soCa;

public:
    FishShop() {
        id = 0;
        name = "";
        address = "";
        owner = "";
        startdate = Date();
        soDanhMuc = 0;
        soCa = 0;
    }

    FishShop(int i, string n, string addr,
             string o, Date d) {
        id = i;
        name = n;
        address = addr;
        owner = o;
        startdate = d;
        soDanhMuc = 0;
        soCa = 0;
    }

    // Getter
    int getId() { return id; }
    string getName() { return name; }
    string getAddress() { return address; }
    string getOwner() { return owner; }
    Date getStartdate() { return startdate; }
    int getSoDanhMuc() { return soDanhMuc; }
    int getSoCa() { return soCa; }

    Category getCategory(int index) {
        if (index >= 0 && index < soDanhMuc)
            return categories[index];

        return Category();
    }

    Fish getFish(int index) {
        if (index >= 0 && index < soCa)
            return fishes[index];

        return Fish();
    }

    // Setter
    void setId(int i) { id = i; }
    void setName(string n) { name = n; }
    void setAddress(string addr) { address = addr; }
    void setOwner(string o) { owner = o; }
    void setStartdate(Date d) { startdate = d; }

    void setCategory(int index, Category c) {
        if (index >= 0 && index < soDanhMuc)
            categories[index] = c;
    }

    void setFish(int index, Fish f) {
        if (index >= 0 && index < soCa)
            fishes[index] = f;
    }

    // Them danh muc
    void addCategory(Category c) {
        if (soDanhMuc < MAX) {
            categories[soDanhMuc] = c;
            soDanhMuc++;
        } else {
            cout << "Danh sach danh muc da day!\n";
        }
    }

    // Them ca
    void addFish(Fish f) {
        if (soCa < MAX) {
            fishes[soCa] = f;
            soCa++;
        } else {
            cout << "Danh sach ca da day!\n";
        }
    }

    // Hien thi thong tin cua hang
    void displayFishShopInfo() {
        cout << "\n========== THONG TIN CUA HANG ==========\n";
        cout << "Ma cua hang : " << id << endl;
        cout << "Ten cua hang: " << name << endl;
        cout << "Dia chi     : " << address << endl;
        cout << "Chu cua hang: " << owner << endl;

        cout << "Ngay mo cua : "
             << startdate.getDay() << "/"
             << startdate.getMonth() << "/"
             << startdate.getYear() << endl;

        cout << "So danh muc : " << soDanhMuc << endl;
        cout << "Tong so ca  : " << soCa << endl;

        for (int i = 0; i < soDanhMuc; i++) {
            cout << "\n========================================\n";
            cout << "DANH MUC " << i + 1 << endl;

            categories[i].displayCategoryInfo();

            cout << "\nDANH SACH CA:\n";
            int dem = 0;

            for (int j = 0; j < soCa; j++) {
                if (fishes[j].getCategoryId()
                    == categories[i].getCategoryId()) {
                    cout << "\nLoai ca " << ++dem << ":\n";
                    fishes[j].displayFishInfo();
                }
            }

            cout << "\nSo loai ca trong danh muc: "
                 << dem << endl;
        }
    }
};

// ==================== MAIN ====================
int main() {
    setlocale(LC_ALL, "");

    Date ngayMo(2026, 9, 10);

    FishShop cuaHang(
        1,
        "Cua hang ca canh thinhOPPA",
        "120 Yen Lang, TPHCM",
        "OPPA KO TEN",
        ngayMo
    );

    // ===== DANH MUC 1: CA CANH NHO =====
    cuaHang.addCategory(Category(
        1, "Ca canh nho", "Cac loai ca nho, de nuoi"
    ));

    cuaHang.addFish(Fish(1, "Ca bay mau", "Do", "De nuoi", 1));
    cuaHang.addFish(Fish(2, "Ca betta", "Xanh", "Duoi dep", 1));
    cuaHang.addFish(Fish(3, "Ca neon", "Xanh duong", "Boi theo dan", 1));
    cuaHang.addFish(Fish(4, "Ca molly", "Den", "De cham soc", 1));
    cuaHang.addFish(Fish(5, "Ca platy", "Cam", "Than nho", 1));
    cuaHang.addFish(Fish(6, "Ca kiem", "Do", "Duoi dai", 1));
    cuaHang.addFish(Fish(7, "Ca tam giac", "Cam", "Boi theo dan", 1));
    cuaHang.addFish(Fish(8, "Ca soc dau do", "Do", "Nhanh nhen", 1));
    cuaHang.addFish(Fish(9, "Ca binh tich", "Den", "De nuoi", 1));
    cuaHang.addFish(Fish(10, "Ca tram", "Bac", "Kich thuoc nho", 1));

    // ===== DANH MUC 2: CA THUY SINH =====
    cuaHang.addCategory(Category(
        2, "Ca thuy sinh", "Ca nuoi trong be thuy sinh"
    ));

    cuaHang.addFish(Fish(11, "Ca dia", "Do", "Than tron", 2));
    cuaHang.addFish(Fish(12, "Ca than tien", "Bac", "Vay dep", 2));
    cuaHang.addFish(Fish(13, "Ca chuot panda", "Trang den", "Song tang day", 2));
    cuaHang.addFish(Fish(14, "Ca but chi", "Bac", "Boi nhanh", 2));
    cuaHang.addFish(Fish(15, "Ca phuong hoang", "Vang xanh", "Mau dep", 2));
    cuaHang.addFish(Fish(16, "Ca thuy tinh", "Trong suot", "Than trong", 2));
    cuaHang.addFish(Fish(17, "Ca oto", "Vang nau", "An reu", 2));
    cuaHang.addFish(Fish(18, "Ca tam giac", "Den cam", "Boi theo dan", 2));
    cuaHang.addFish(Fish(19, "Ca chuot pygmy", "Xam", "Than nho", 2));
    cuaHang.addFish(Fish(20, "Ca neon vua", "Do xanh", "Mau noi bat", 2));

    // ===== DANH MUC 3: CA PHONG THUY =====
    cuaHang.addCategory(Category(
        3, "Ca phong thuy", "Ca canh co kich thuoc vua va lon"
    ));

    cuaHang.addFish(Fish(21, "Ca koi do", "Do", "Mau sac dep", 3));
    cuaHang.addFish(Fish(22, "Ca koi vang", "Vang", "De cham soc", 3));
    cuaHang.addFish(Fish(23, "Ca koi den", "Den", "Than dep", 3));
    cuaHang.addFish(Fish(24, "Ca chep vang", "Vang", "Boi nhanh", 3));
    cuaHang.addFish(Fish(25, "Ca rong huyet long", "Do", "Vay dep", 3));
    cuaHang.addFish(Fish(26, "Ca rong kim long", "Vang kim", "Anh kim", 3));
    cuaHang.addFish(Fish(27, "Ca la han", "Do", "Dau gu", 3));
    cuaHang.addFish(Fish(28, "Ca hong ket", "Do", "Than tron", 3));
    cuaHang.addFish(Fish(29, "Ca tai tuong", "Den do", "Than lon", 3));
    cuaHang.addFish(Fish(30, "Ca sam", "Den trang", "Hoa van cham bi", 3));

    // ===== DANH MUC 4: CA BIEN =====
    cuaHang.addCategory(Category(
        4, "Ca bien", "Ca nuoc man nuoi trong be bien"
    ));

    cuaHang.addFish(Fish(31, "Ca he Nemo", "Cam trang", "Song theo cap", 4));
    cuaHang.addFish(Fish(32, "Ca thia xanh", "Xanh", "Mau sac dep", 4));
    cuaHang.addFish(Fish(33, "Ca buom bien", "Vang", "Vay rong", 4));
    cuaHang.addFish(Fish(34, "Ca thien than", "Xanh vang", "Mau sac noi bat", 4));
    cuaHang.addFish(Fish(35, "Ca hoang de", "Xanh", "Hoa van dep", 4));
    cuaHang.addFish(Fish(36, "Ca tang vang", "Vang", "Than vang", 4));
    cuaHang.addFish(Fish(37, "Ca su tu bien", "Do nau", "Vay doc", 4));
    cuaHang.addFish(Fish(38, "Ca Banggai", "Bac den", "Vay dai", 4));
    cuaHang.addFish(Fish(39, "Ca he den", "Den trang", "Mau tuong phan", 4));
    cuaHang.addFish(Fish(40, "Ca bo hom", "Vang", "Than dac biet", 4));

    // Hien thi thong tin
    cuaHang.displayFishShopInfo();

    return 0;
}