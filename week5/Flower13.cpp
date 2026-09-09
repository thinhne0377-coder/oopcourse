#include <iostream>
#include <string>
using namespace std;

// ==================================================
// BƯỚC 1: TẠO STRUCT
// ==================================================

struct Flower {
    string name;
    double price;
    int quantity;
    string type;
};

int main() {

    // ==================================================
    // BƯỚC 2: TẠO MẢNG
    // ==================================================

    Flower flowers[20];
    int n;

    // ==================================================
    // BƯỚC 3: NHẬP SỐ LƯỢNG HOA
    // ==================================================

    do {
        cout << "How many flowers (1-20): ";
        cin >> n;

        if (n < 1 || n > 20)
            cout << "Invalid! Enter 1-20.\n";

    } while (n < 1 || n > 20);


    // ==================================================
    // BƯỚC 4: NHẬP THÔNG TIN HOA
    // ==================================================

    for (int i = 0; i < n; i++) {

        cout << "\nFlower " << i + 1 << endl;

        // Nhập tên
        cout << "Name: ";
        cin >> ws;
        getline(cin, flowers[i].name);

        // Nhập giá
        do {
            cout << "Price: ";
            cin >> flowers[i].price;

            if (flowers[i].price <= 0)
                cout << "Price must be > 0!\n";

        } while (flowers[i].price <= 0);

        // Nhập số lượng
        do {
            cout << "Quantity: ";
            cin >> flowers[i].quantity;

            if (flowers[i].quantity < 0)
                cout << "Quantity must be >= 0!\n";

        } while (flowers[i].quantity < 0);

        // Nhập loại
        cout << "Type: ";
        cin >> ws;
        getline(cin, flowers[i].type);
    }


    // ==================================================
    // BƯỚC 5: HIỂN THỊ DANH SÁCH
    // TASK 1
    // ==================================================

    cout << "\n========== FLOWER SHOP ==========\n";

    for (int i = 0; i < n; i++) {

        cout << i + 1 << ". "
             << flowers[i].name << " | "
             << flowers[i].price << " | "
             << flowers[i].quantity << " | "
             << flowers[i].type << endl;
    }


    // ==================================================
    // BƯỚC 6: TÌM HOA ĐẮT NHẤT
    // TASK 2
    // ==================================================

    int maxPrice = 0;

    for (int i = 1; i < n; i++) {

        if (flowers[i].price > flowers[maxPrice].price)
            maxPrice = i;
    }

    cout << "\nMost expensive: "
         << flowers[maxPrice].name
         << " - "
         << flowers[maxPrice].price << endl;


    // ==================================================
    // BƯỚC 7: TÌM HOA RẺ NHẤT
    // TASK 3
    // ==================================================

    int minPrice = 0;

    for (int i = 1; i < n; i++) {

        if (flowers[i].price < flowers[minPrice].price)
            minPrice = i;
    }

    cout << "Cheapest: "
         << flowers[minPrice].name
         << " - "
         << flowers[minPrice].price << endl;


    // ==================================================
    // BƯỚC 8: TÌM HOA CÓ SỐ LƯỢNG LỚN NHẤT
    // TASK 4
    // ==================================================

    int maxQty = 0;

    for (int i = 1; i < n; i++) {

        if (flowers[i].quantity > flowers[maxQty].quantity)
            maxQty = i;
    }

    cout << "Largest quantity: "
         << flowers[maxQty].name
         << " - "
         << flowers[maxQty].quantity << endl;


    // ==================================================
    // BƯỚC 9: TỔNG SỐ LƯỢNG
    // TASK 5
    // ==================================================

    int totalQty = 0;

    for (int i = 0; i < n; i++) {
        totalQty += flowers[i].quantity;
    }

    cout << "Total quantity: "
         << totalQty << endl;


    // ==================================================
    // BƯỚC 10: GIÁ TRUNG BÌNH
    // TASK 6
    // ==================================================

    double sumPrice = 0;

    for (int i = 0; i < n; i++) {
        sumPrice += flowers[i].price;
    }

    double avgPrice = sumPrice / n;

    cout << "Average price: "
         << avgPrice << endl;


    // ==================================================
    // BƯỚC 11: ĐẾM HOA THEO TYPE
    // TASK 7
    // ==================================================

    string type;
    int countType = 0;

    cout << "\nEnter type to count: ";
    cin >> ws;
    getline(cin, type);

    for (int i = 0; i < n; i++) {

        if (flowers[i].type == type)
            countType++;
    }

    cout << "Number of " << type
         << ": " << countType << endl;


    // ==================================================
    // BƯỚC 12: TÌM HOA THEO TYPE
    // TASK 8
    // ==================================================

    cout << "\nFlowers of type " << type << ":\n";

    bool found = false;

    for (int i = 0; i < n; i++) {

        if (flowers[i].type == type) {

            cout << flowers[i].name << endl;
            found = true;
        }
    }

    if (!found)
        cout << "No flower found.\n";


    // ==================================================
    // BƯỚC 13: TÌM HOA THEO TÊN
    // TASK 9
    // ==================================================

    string name;

    cout << "\nEnter flower name: ";
    cin >> ws;
    getline(cin, name);

    found = false;

    for (int i = 0; i < n; i++) {

        if (flowers[i].name == name) {

            cout << "\nFound!\n";
            cout << "Name: " << flowers[i].name << endl;
            cout << "Price: " << flowers[i].price << endl;
            cout << "Quantity: " << flowers[i].quantity << endl;
            cout << "Type: " << flowers[i].type << endl;

            found = true;
            break;
        }
    }

    if (!found)
        cout << "Not found.\n";


    // ==================================================
    // BƯỚC 14: KIỂM TRA HOA CÓ TỒN TẠI
    // TASK 10
    // ==================================================

    cout << "\nEnter name to check: ";
    cin >> ws;
    getline(cin, name);

    found = false;

    for (int i = 0; i < n; i++) {

        if (flowers[i].name == name) {
            found = true;
            break;
        }
    }

    if (found)
        cout << "Yes, flower exists.\n";
    else
        cout << "No, flower does not exist.\n";


    // ==================================================
    // BƯỚC 15: ĐẾM HOA CÓ QUANTITY < 5
    // TASK 11
    // ==================================================

    int lowCount = 0;

    for (int i = 0; i < n; i++) {

        if (flowers[i].quantity < 5)
            lowCount++;
    }

    cout << "\nQuantity < 5: "
         << lowCount << endl;


    // ==================================================
    // BƯỚC 16: ĐẾM HOA TRONG KHOẢNG GIÁ
    // TASK 12
    // ==================================================

    double minP, maxP;

    cout << "\nEnter minimum price: ";
    cin >> minP;

    cout << "Enter maximum price: ";
    cin >> maxP;

    int priceCount = 0;

    for (int i = 0; i < n; i++) {

        if (flowers[i].price >= minP &&
            flowers[i].price <= maxP) {

            priceCount++;
        }
    }

    cout << "Flowers in price range: "
         << priceCount << endl;


    // ==================================================
    // BƯỚC 17: TỔNG GIÁ TRỊ
    // TASK 13
    // ==================================================

    double totalValue = 0;

    for (int i = 0; i < n; i++) {

        totalValue +=
            flowers[i].price *
            flowers[i].quantity;
    }

    cout << "\nTotal value: "
         << totalValue << endl;


    // ==================================================
    // BƯỚC 18: HOA CÓ GIÁ TRỊ LỚN NHẤT
    // TASK 14
    // ==================================================

    int maxValue = 0;

    for (int i = 1; i < n; i++) {

        double value1 =
            flowers[i].price *
            flowers[i].quantity;

        double value2 =
            flowers[maxValue].price *
            flowers[maxValue].quantity;

        if (value1 > value2)
            maxValue = i;
    }

    cout << "Most valuable: "
         << flowers[maxValue].name << endl;


    // ==================================================
    // BƯỚC 19: SẮP XẾP THEO GIÁ TĂNG DẦN
    // TASK 15
    // ==================================================

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if (flowers[j].price >
                flowers[j + 1].price) {

                Flower temp = flowers[j];

                flowers[j] = flowers[j + 1];

                flowers[j + 1] = temp;
            }
        }
    }

    cout << "\nSorted by price:\n";

    for (int i = 0; i < n; i++) {

        cout << flowers[i].name
             << " - "
             << flowers[i].price << endl;
    }


    // ==================================================
    // BƯỚC 20: SẮP XẾP THEO TÊN A -> Z
    // TASK 16
    // ==================================================

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if (flowers[j].name >
                flowers[j + 1].name) {

                Flower temp = flowers[j];

                flowers[j] = flowers[j + 1];

                flowers[j + 1] = temp;
            }
        }
    }

    cout << "\nSorted by name:\n";

    for (int i = 0; i < n; i++) {

        cout << flowers[i].name << endl;
    }


    // ==================================================
    // BƯỚC 21: TOP 3 HOA ĐẮT NHẤT
    // TASK 17
    // ==================================================

    // Sắp xếp lại theo giá giảm dần

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if (flowers[j].price <
                flowers[j + 1].price) {

                Flower temp = flowers[j];

                flowers[j] = flowers[j + 1];

                flowers[j + 1] = temp;
            }
        }
    }

    cout << "\nTop 3 expensive flowers:\n";

    int limit = (n < 3) ? n : 3;

    for (int i = 0; i < limit; i++) {

        cout << i + 1 << ". "
             << flowers[i].name
             << " - "
             << flowers[i].price << endl;
    }


    // ==================================================
    // BƯỚC 22: TÌM TÊN CHỨA KEYWORD
    // TASK 18
    // ==================================================

    string keyword;

    cout << "\nEnter keyword: ";
    cin >> keyword;

    found = false;

    for (int i = 0; i < n; i++) {

        if (flowers[i].name.find(keyword)
            != string::npos) {

            cout << flowers[i].name << endl;

            found = true;
        }
    }

    if (!found)
        cout << "No flower found.\n";


    // ==================================================
    // BƯỚC 23: TRUNG BÌNH QUANTITY THEO TYPE
    // TASK 19
    // ==================================================

    cout << "\nEnter type: ";
    cin >> ws;
    getline(cin, type);

    int total = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {

        if (flowers[i].type == type) {

            total += flowers[i].quantity;
            count++;
        }
    }

    if (count > 0) {

        double avg =
            (double)total / count;

        cout << "Average quantity: "
             << avg << endl;
    }
    else {
        cout << "No flower of this type.\n";
    }


    // ==================================================
    // BƯỚC 24: SIMPLE REPORT
    // TASK 20
    // ==================================================

    cout << "\n========== SIMPLE REPORT ==========\n";

    cout << "Number of flowers: "
         << n << endl;

    cout << "Total quantity: "
         << totalQty << endl;

    cout << "Average price: "
         << avgPrice << endl;

    cout << "Total value: "
         << totalValue << endl;


    return 0;
}
