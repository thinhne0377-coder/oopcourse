#include <iostream>
#include <string>

using namespace std;

int main()
{
    // =========================================
    // 1. Nhap mot cau tu nguoi dung
    // =========================================
    string sentence;

    cout << "Enter a sentence: ";
    getline(cin, sentence);


    // =========================================
    // 2. Hien thi do dai cua cau
    // =========================================
    cout << "\n===== STRING INFORMATION =====" << endl;

    cout << "Length: " << sentence.length() << endl;


    // =========================================
    // 3. Tim vi tri cua tu "C++"
    // =========================================
    size_t pos = sentence.find("C++");

    if (pos != string::npos)
    {
        cout << "Found \"C++\" at position: "
             << pos << endl;


        // =========================================
        // 4. In phan chuoi bat dau tu "C++"
        // =========================================
        cout << "Substring from that position: "
             << sentence.substr(pos) << endl;


        // =========================================
        // 5. Thay "C++" bang "Programming"
        // =========================================
        sentence.replace(pos, 3, "Programming");

        cout << "New sentence: "
             << sentence << endl;
    }
    else
    {
        cout << "\"C++\" not found." << endl;
    }


    // =========================================
    // Ket thuc chuong trinh
    // =========================================
    cout << "==============================" << endl;

    return 0;
}