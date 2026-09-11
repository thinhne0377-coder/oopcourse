#include <iostream>
#include <string>

using namespace std;

// Ham hien thi ten va diem sinh vien
void showScore(string name, double score)
{
    cout << "Student: " << name << endl;
    cout << "Score: " << score << endl;
    cout << "Keep going!" << endl;
}

int main()
{
    // Khai bao bien
    string name;
    double score;

    // Nhap ten sinh vien
    cout << "Enter student name: ";
    getline(cin, name);

    // Nhap diem
    cout << "Enter score: ";
    cin >> score;

    // Goi ham
    showScore(name, score);

    return 0;
}