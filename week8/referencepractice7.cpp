#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// =====================================================
// BAI 1: Modify a String through a Reference
// =====================================================
void bai1() {
    cout << "\n===== BAI 1 =====" << endl;

    string s = "Hello";
    string& r = s;

    r += " World";

    cout << s << endl;
    cout << r << endl;
}

// =====================================================
// BAI 2: Pass by Reference
// =====================================================
void addExclaim(string& str) {
    str += "!";
}

void bai2() {
    cout << "\n===== BAI 2 =====" << endl;

    string msg = "Good Day";

    addExclaim(msg);

    cout << msg << endl;
}

// =====================================================
// BAI 3: Swap Two Strings
// =====================================================
void swapStr(string& a, string& b) {
    string temp = a;
    a = b;
    b = temp;
}

void bai3() {
    cout << "\n===== BAI 3 =====" << endl;

    string x = "cat";
    string y = "dog";

    swapStr(x, y);

    cout << x << " " << y << endl;
}

// =====================================================
// BAI 4: Modify a Character through a Reference
// =====================================================
void changeFirstChar(string& str) {
    str[0] = 'J';
}

void bai4() {
    cout << "\n===== BAI 4 =====" << endl;

    string name = "python";

    changeFirstChar(name);

    cout << name << endl;
}

// =====================================================
// BAI 5: Reference vs Copy
// =====================================================
void bai5() {
    cout << "\n===== BAI 5 =====" << endl;

    string s = "Hello";

    string r = s;       // Copy
    string& ref = s;    // Reference

    r += "!!!";
    ref += "???";

    cout << "s: " << s << endl;
    cout << "r: " << r << endl;
    cout << "ref: " << ref << endl;
}

// =====================================================
// BAI 6: Pass a String to Uppercase
// =====================================================
void toUpperCase(string& str) {
    for (char& c : str) {
        c = toupper(static_cast<unsigned char>(c));
    }
}

void bai6() {
    cout << "\n===== BAI 6 =====" << endl;

    string text = "c++ is fun";

    toUpperCase(text);

    cout << text << endl;
}

// =====================================================
// MAIN
// =====================================================
int main() {

    bai1();
    bai2();
    bai3();
    bai4();
    bai5();
    bai6();

    return 0;
}