#include <iostream>
#include <cmath>
using namespace std;

// ==================== CLASS PT1 ====================
class PT1 {
private:
    double a, b;

public:
    // Constructor
    PT1() {
        a = 0;
        b = 0;
    }

    PT1(double a, double b) {
        this->a = a;
        this->b = b;
    }

    // Setter
    void setA(double a) {
        this->a = a;
    }

    void setB(double b) {
        this->b = b;
    }

    // Getter
    double getA() {
        return a;
    }

    double getB() {
        return b;
    }

    // Solve equation ax + b = 0
    void solve() {
        cout << "\nPhuong trinh bac nhat: " << a << "x + " << b << " = 0\n";

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

// ==================== CLASS PTB2 ====================
class PTB2 {
private:
    double a, b, c;

public:
    // Constructor
    PTB2() {
        a = b = c = 0;
    }

    PTB2(double a, double b, double c) {
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
    double getA() {
        return a;
    }

    double getB() {
        return b;
    }

    double getC() {
        return c;
    }

    // Solve equation ax^2 + bx + c = 0
    void solve() {
        cout << "\nPhuong trinh bac hai: "
             << a << "x^2 + " << b << "x + " << c << " = 0\n";

        if (a == 0) {
            PT1 pt(b, c);
            pt.solve();
            return;
        }

        double delta = b * b - 4 * a * c;

        if (delta < 0) {
            cout << "Phuong trinh vo nghiem thuc.\n";
        } else if (delta == 0) {
            cout << "Nghiem kep x = " << -b / (2 * a) << endl;
        } else {
            cout << "Nghiem x1 = "
                 << (-b + sqrt(delta)) / (2 * a) << endl;
            cout << "Nghiem x2 = "
                 << (-b - sqrt(delta)) / (2 * a) << endl;
        }
    }
};

// ==================== CLASS PTB3 ====================
class PTB3 {
private:
    double a, b, c, d;

public:
    // Constructor
    PTB3() {
        a = b = c = d = 0;
    }

    PTB3(double a, double b, double c, double d) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
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

    void setD(double d) {
        this->d = d;
    }

    // Getter
    double getA() {
        return a;
    }

    double getB() {
        return b;
    }

    double getC() {
        return c;
    }

    double getD() {
        return d;
    }

    // Solve equation ax^3 + bx^2 + cx + d = 0
    void solve() {
        cout << "\nPhuong trinh bac ba: "
             << a << "x^3 + " << b << "x^2 + "
             << c << "x + " << d << " = 0\n";

        if (a == 0) {
            PTB2 pt(b, c, d);
            pt.solve();
            return;
        }

        // Chuan hoa thanh x^3 + A*x^2 + B*x + C = 0
        double A = b / a;
        double B = c / a;
        double C = d / a;

        double p = B - A * A / 3.0;
        double q = 2 * A * A * A / 27.0 - A * B / 3.0 + C;
        double delta = q * q / 4.0 + p * p * p / 27.0;

        const double EPS = 1e-10;

        if (delta > EPS) {
            double u = cbrt(-q / 2.0 + sqrt(delta));
            double v = cbrt(-q / 2.0 - sqrt(delta));

            cout << "Phuong trinh co 1 nghiem thuc:\n";
            cout << "x = " << u + v - A / 3.0 << endl;
        } else if (delta < -EPS) {
            double r = 2 * sqrt(-p / 3.0);
            double value = (3 * q / (2 * p)) * sqrt(-3.0 / p);

            if (value > 1) value = 1;
            if (value < -1) value = -1;

            double theta = acos(value) / 3.0;

            cout << "Phuong trinh co 3 nghiem thuc:\n";

            for (int k = 0; k < 3; k++) {
                double x = r * cos(theta - 2 * M_PI * k / 3.0)
                           - A / 3.0;
                cout << "x" << k + 1 << " = " << x << endl;
            }
        } else {
            double u = cbrt(-q / 2.0);

            cout << "x1 = " << 2 * u - A / 3.0 << endl;
            cout << "x2 = " << -u - A / 3.0 << endl;
        }
    }
};

// ==================== MAIN ====================
int main() {
    double a, b, c, d;

    cout << "===== GIAI PHUONG TRINH BAC NHAT =====\n";
    cout << "Nhap a, b: ";
    cin >> a >> b;

    PT1 pt1(a, b);
    pt1.solve();

    cout << "\n===== GIAI PHUONG TRINH BAC HAI =====\n";
    cout << "Nhap a, b, c: ";
    cin >> a >> b >> c;

    PTB2 pt2(a, b, c);
    pt2.solve();

    cout << "\n===== GIAI PHUONG TRINH BAC BA =====\n";
    cout << "Nhap a, b, c, d: ";
    cin >> a >> b >> c >> d;

    PTB3 pt3(a, b, c, d);
    pt3.solve();

    return 0;
}