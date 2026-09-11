void showScore(string name, double score)
#include <iostream>
#include <string>
using namespace std;
void showScore(string name, double score)
{
    cout << "Student: " << name << endl;
    cout << "Score: " << score << endl;
    cout << "Keep going!" << endl;
}
(string name, double score)
int main()
{
    string name;
    double score;
    cout << "Enter student name: ";
getline(cin, name);
cout << "Enter score: ";
cin >> score;
showScore(name, score);