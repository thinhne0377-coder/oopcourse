#include <iostream>
using namespace std;
int main() {

  int n;
  do {

    cout << "how many students ";
    cin >> n;
    cout << endl;

    if (n < 2 || n > 20) {
      cout << "invalid number of students!\n";
      cout << "Please enter a number from 2 to 20\n";
    }

  } while (n < 2 || n > 20);

  
  float a;
    for (int i=1;i<=n;i++)
    {
        cout << "Enter score for student " << i << ": ";
        
        do {
            cin >> a;
            if (a <0 || a>10) cout <<"Invalid score! Pleasee enter a value from 0 to 10: ";
        } while (a <0 || a>10);
    }


  return 0;
}