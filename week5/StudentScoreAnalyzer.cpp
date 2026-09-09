#include <iostream>
#include <stdio.h>
using namespace std;
int main() {

  int n;
  do {

    cout << "how many students? ";
    cin >> n;
    cout << endl;

    if (n < 2 || n > 20) {
      cout << "invalid number of students!\n";
      cout << "Please enter a number from 2 to 20\n";
    }

  } while (n < 2 || n > 20);

  float a[100];
  a[0] = 0;

  for (int i = 1; i <= n; i++) {
    cout << "Enter score for student " << i << ": ";

    do {
      cin >> a[i];
      if (a[i] < 0 || a[i] > 10)
        cout << "Invalid score! Pleasee enter a value from 0 to 10: ";
    } while (a[i] < 0 || a[i] > 10);
  }

  cout << endl;
  cout << "==== STUDENT SCORES ====\n";
  cout << endl;

  for (int i = 1; i <= n; i++) {
    printf("Student %d: %.1f\n", i, a[i]);
  }

  cout << endl;
  cout << "==== RESULTS ====\n";
  cout << endl;

  for (int i = 1; i <= n; i++) {
    printf("Student %d: %.1f ", i, a[i]);
    if (a[i] >= 5)
      cout << "-----> PASS\n";
    else
      cout << "-----> FAIL\n";
  }


  
  return 0;
}