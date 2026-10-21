```cpp
#include <iostream>
#include <cmath>
using namespace std;

// ================= CLASS PT =================
class PT {
protected:
    double a, b, c;

public:
    // Constructor
    PT() {
        a = b = c = 0;
    }

    PT(double a, double b, double c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    // Setter
    void setA(double a) {
        this->a = a;
    }

    void setB(double b) {
        this->b = b;
    }

    void setC(double c) {
        this->c = c;
    }

    // Getter
    double getA() const {
        return a;
    }

    double getB() const {
        return b;
    }

    double getC() const {
        return c;
    }

    // Phuong thuc ao
    virtual void solve() = 0;

    virtual ~PT() {}
};

// ================= CLASS PTB1 =================
// Phuong trinh bac nhat: ax + b = 0
class PTB1 : public PT {
public:
    PTB1() : PT() {}

    PTB1(double a, double b) : PT(a, b, 0) {}

    void solve() override {
        cout << "\nPhuong trinh bac nhat: "
             << a << "x + " << b << " = 0\n";

        if (a == 0) {
            if (b == 0)
                cout << "Phuong trinh vo so nghiem.\n";
            else
                cout << "Phuong trinh vo nghiem.\n";
        } else {
            cout << "Nghiem x = " << -b / a << endl;
        }
    }
};

// ================= CLASS PTB2 =================
// Phuong trinh bac hai: ax^2 + bx + c = 0
class PTB2 : public PT {
public:
    PTB2() : PT() {}

    PTB2(double a, double b, double c)
        : PT(a, b, c) {}

    void solve() override {
        cout << "\nPhuong trinh bac hai: "
             << a << "x^2 + " << b
             << "x + " << c << " = 0\n";

        if (a == 0) {
            cout << "Day la phuong trinh bac nhat.\n";

            if (b == 0) {
                if (c == 0)
                    cout << "Phuong trinh vo so nghiem.\n";
                else
                    cout << "Phuong trinh vo nghiem.\n";
            } else {
                cout << "Nghiem x = " << -c / b << endl;
            }
            return;
        }

        double delta = b * b - 4 * a * c;

        if (delta < 0) {
            cout << "Phuong trinh vo nghiem thuc.\n";
        } else if (delta == 0) {
            cout << "Phuong trinh co nghiem kep x = "
                 << -b / (2 * a) << endl;
        } else {
            double x1 = (-b + sqrt(delta)) / (2 * a);
            double x2 = (-b - sqrt(delta)) / (2 * a);

            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        }
    }
};

// ================= HAM MAIN =================
int main() {
    double a, b, c;

    cout << "=== GIAI PHUONG TRINH BAC NHAT ===\n";
    cout << "Nhap a, b: ";
    cin >> a >> b;

    PTB1 pt1(a, b);
    pt1.solve();

    cout << "\n=== GIAI PHUONG TRINH BAC HAI ===\n";
    cout << "Nhap a, b, c: ";
    cin >> a >> b >> c;

    PTB2 pt2(a, b, c);
    pt2.solve();

    // Tinh da hinh thong qua lop co so
    cout << "\n=== TINH DA HINH ===\n";

    PT* ds[2];
    ds[0] = &pt1;
    ds[1] = &pt2;

    for (int i = 0; i < 2; i++) {
        ds[i]->solve();
    }

    return 0;
}
