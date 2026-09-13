#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

// kiểu cấu trúc
typedef struct {
  int no;
  char name[20];
  float price;
  int quantity;
  char type[20];

} Flower;
void nhapflowers(Flower DS[], int N) {
  printf("====== Nhap thong tin hoa ======\n");

  for (int i = 0; i < N; i++) {
    DS[i].no = i + 1;
    cout << "Nhap thong tin hoa " << i + 1 << ": " << endl;
    cout << "Name: ";
    cin.getline(DS[i].name, 20);
    cout << "Price: ";
    cin >> DS[i].price;
    cin.ignore();
    cout << "Quantity: ";
    cin >> DS[i].quantity;
    cin.ignore();
    cout << "Type: ";
    cin.getline(DS[i].type, 20);
    cout << endl;
  }
  cout << endl << endl;
}
// câu 1: display all flowers
void inflowers(Flower DS[], int N) {
  printf("====== BANG THONG TIN HOA ======\n");
  printf("%-12s|%-32s|%4s|%10s|%20s\n", "No", "Name", "Price", "Qty", "Type");

  for (int i = 0; i < N; i++) {
    printf("%-12d|%-32s|%4.1f|%10d|%20s\n", DS[i].no, DS[i].name, DS[i].price,
           DS[i].quantity, DS[i].type);
  }
  cout << endl << endl;
}