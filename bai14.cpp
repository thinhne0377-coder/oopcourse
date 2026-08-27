#include <iostream>
#include <string>

using namespace std;

int main() {

    // Constant
    const int BIRTH_YEAR = 2007;

    // Variables
    string name = "thinh";
    int age = 19;
    double gpa = 7;
    char grade = 'A';

    // More variables
    int score = 80;

    // Calculations
    int nextAge = age + 1;
    double initialScore = score - 10;

    // Update variable
    score += 10;

    // Display information
    cout << "==============================\n";
    cout << "       MY FIRST C++ APP\n";
    cout << "==============================\n\n";

    cout << "Name          : " << name << endl;
    cout << "Age           : " << age << endl;
    cout << "GPA           : " << gpa << endl;
    cout << "Grade         : " << grade << endl;

    cout << endl;

    cout << "Birth Year    : " << BIRTH_YEAR << endl;
    cout << "Next Age      : " << nextAge << endl;

    cout << endl;

    cout << "Initial Score : " << initialScore << endl;
    cout << "Updated Score : " << score << endl;

    cout << endl;
    cout << "Goal: Become a better programmer!\n";

    return 0;
}