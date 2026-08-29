#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cout << "Type the number of students: ";
    cin >> n;

    cin.ignore();   // remove all unnecessary '\n' remained

    string names [20];
    string ids [20];
    string phones [20];

    for (int i = 0; i < n; i++){
        
        cout << "Student " << i + 1 << endl;

        cout << "Name   :";
        getline (cin, names[i]);

        cout << "ID     :";
        getline (cin, ids[i]);

        cout << "Phone  :";
        getline (cin, phones[i]);
    }

    cout << "============================" << endl;
    cout << "        STUDENT LIST        " << endl;
    cout << "============================" << endl;

    for (int i = 0; i < n; i++){
        
        cout << "* Student " << i + 1 << endl;

        cout << "Name   :" << names[i] << endl;

        cout << "ID     :" << ids[i] << endl;

        cout << "Phone  :" << phones[i] << endl;
    }

    cout << endl;

    cout << "****************************" << endl;
    cout << "Total students: " << n << endl;
    cout << "****************************" << endl;

    return 0;
}