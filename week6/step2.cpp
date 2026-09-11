#include <iostream>

using namespace std;

void showStudentID(int id)
{
    cout << "Student ID: " << id << endl;
}

int main()
{
    int id;

    cout << "Enter your student ID: ";
    cin >> id;

    showStudentID(id);

    return 0;
}