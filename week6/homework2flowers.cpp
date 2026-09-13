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
// câu 2: find the most expensive flowers
void max_price(Flower DS[], int N) {
  float max = DS[0].price;

  for (int i = 1; i < N; i++) {
    if (DS[i].price > max) {
      max = DS[i].price;
    }
  }

  printf("====== HOA CO GIA CAO NHAT ======\n");
  printf("%-12s|%-32s|%4s|%10s|%20s\n", "No", "Name", "Price", "Qty", "Type");

  for (int i = 0; i < N; i++) {
    if (DS[i].price == max) {
      printf("%-12d|%-32s|%4.1f|%10d|%20s\n", DS[i].no, DS[i].name, DS[i].price,
             DS[i].quantity, DS[i].type);
    }
  }
}
// câu 3: find the cheapest flowers
void min_price(Flower DS[], int N) {
  float min = DS[0].price;

  for (int i = 0; i < N; i++) {
    if (min > DS[i].price)
      min = DS[i].price;
  }

  printf("====== HOA CO GIA THAP NHAT ======\n");
  printf("%-12s|%-32s|%4s|%10s|%20s\n", "No", "Name", "Price", "Qty", "Type");

  for (int i = 0; i < N; i++) {
    if (DS[i].price == min) {
      printf("%-12d|%-32s|%4.1f|%10d|%20s\n", DS[i].no, DS[i].name, DS[i].price,
             DS[i].quantity, DS[i].type);
    }
  }
}
// câu 4: find the flower with the largest quantity
void max_quantity(Flower DS[], int N) {
  int max = DS[0].quantity;

  for (int i = 1; i < N; i++) {
    if (DS[i].quantity > max) {
      max = DS[i].quantity;
    }
  }

  printf("====== HOA CÓ NHIỀU QUANTITY NHẤT ======\n");
  printf("%-12s|%-32s|%4s|%10s|%20s\n", "No", "Name", "Price", "Qty", "Type");

  for (int i = 0; i < N; i++) {
    if (DS[i].quantity == max) {
      printf("%-12d|%-32s|%4.1f|%10d|%20s\n", DS[i].no, DS[i].name, DS[i].price,
             DS[i].quantity, DS[i].type);
    }
  }
}
// câu 5: tổng quantity
void sum_quantity(Flower DS[], int N) {
  int sum = 0;
  for (int i = 0; i < N; i++) {
    sum = sum + DS[i].quantity;
  }

  cout << "the total quantity: " << sum << endl;
}