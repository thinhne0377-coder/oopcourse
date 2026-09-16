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
// câu 6: average price
void average_price(Flower DS[], int N) {
  float sum = 0;
  for (int i = 0; i < N; i++) {
    sum = sum + DS[i].price;
  }

  cout << "the average price: " << sum / N << endl;
}
// câu 7: đếm xem mỗi loại có bao nhiêu hoa
void cout_eachtype(Flower DS[], int N) {
  for (int i = 0; i < N; i++) {
    int dadem = 0;
    for (int j = 0; j < i; j++) {
      if (strcmp(DS[i].type, DS[j].type) == 0) {
        dadem = 1;
        break;
      }
    }

    if (dadem == 1)
      continue;

    int count = 0;
    for (int j = 0; j < N; j++) {
      if (strcmp(DS[j].type, DS[i].type) == 0) {
        count++;
      }
    }
    printf("%-20s : %d\n", DS[i].type, count);
  }
}
// câu 8: find all flowers of a given type
void findflower_bytype(Flower DS[], int N) {

  char a[50];
  int daco;

  do {
    daco = 0;
    cout << "Nhap type hoa can tim: ";
    cin.getline(a, 50);

    for (int i = 0; i < N; i++) {
      if (strcmp(DS[i].type, a) == 0) {
        daco = 1;
        break;
      }
    }

    if (daco == 1) {
      for (int i = 0; i < N; i++) {
        if (strcmp(DS[i].type, a) == 0)
          cout << DS[i].name << endl;
      }
    } else
      cout << "Ko co hoa theo type da go, vui long nhap lai!\n";
  } while (daco == 0);
}
// câu 9: search by name
Flower search_name(Flower DS[], int N) {
  char a[50];
  int found = 0;
  do {

    cout << "Nhap name cua flowers: ";
    cin.getline(a, 50);

    for (int i = 0; i < N; i++) {
      if (strcmp(DS[i].name, a) == 0) {
        found = 1;
        return DS[i];
      }
    }

    if (found == 0)
      cout << "K tim thay hoa theo ten go! Vu long nhap lai!\n";

  } while (found == 0);
}
// câu 10: check flowers
void checkflower(Flower DS[], int N) {

  char a[50];
  int daco;
  do {
    daco = 0;
    cout << "Name cua flower: ";
    cin.getline(a, 50);
    cout << "Status: ";

    for (int i = 0; i < N; i++) {
      if (strcmp(DS[i].name, a) == 0) {
        cout << "YES!\n";
        daco = 1;
        break;
      }
    }

    if (daco == 0)
      cout << "NO! please try again!\n";

  } while (daco == 0);
}
// câu 11: count flowers (quantity <5)
void count_flowers_lowerquantity(Flower DS[], int N) {
  int dem = 0;
  for (int i = 0; i < N; i++) {
    if (DS[i].quantity < 5)
      dem++;
  }

  cout << "So hoa <5 la: " << dem << endl;
}

// câu 12: count flowers ( price range)
void count_flowers_pricerange(Flower DS[], int N) {

  float a, b;
  int count;

  do {
    count = 0;
    cout << "Khoang price muon nhap: ";
    cin >> a >> b;
    // xíu nữa cin.ignore() vì nó lưu xuống hàng khi ấn enter

    for (int i = 0; i < N; i++) {
      if (a <= DS[i].price && DS[i].price <= b)
        count++;
    }

    if (count != 0) {
      cout << "So ten hoa trong khoang gia: " << count << endl;
      break;
    }
    if (count == 0)
      cout << "K co hoa trong khoang gia yeu cau, please nhap lai!\n";

  } while (count == 0);
}
// câu 13: calculate total value (price x quantity)
void total_value(Flower DS[], int N) {

  float sum = 0;
  for (int i = 0; i < N; i++) {
    sum = sum + (DS[i].price * DS[i].quantity);
  }

  cout << "Total value (price x quantity): " << sum << endl;
}
// câu 14: find the most value flower
void mostvalueflower(Flower DS[], int N) {
  float max = DS[0].price * DS[0].quantity;
  for (int i = 0; i < N; i++) {
    if (DS[i].price * DS[i].quantity > max) {
      max = DS[i].price * DS[i].quantity;
    }
  }

  cout << "The most valuable flower: " << endl;
  for (int i = 0; i < N; i++) {
    if (DS[i].price * DS[i].quantity == max) {
      cout << DS[i].name << endl;
    }
  }
}
// câu 15: sort flowers by price (tăng dần)
void sort_price(Flower DS[], int N) {

  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < N; j++)
      if (DS[i].price > DS[j].price)
        swap(DS[i].price, DS[j].price);
  }

  printf("====== SORT FLOWERS BY PRICE ======\n");
  printf("%-12s|%-32s|%4s|%10s|%20s\n", "No", "Name", "Price", "Qty", "Type");

  for (int i = 0; i < N; i++) {
    printf("%-12d|%-32s|%4.1f|%10d|%20s\n", DS[i].no, DS[i].name, DS[i].price,
           DS[i].quantity, DS[i].type);
  }
}

// câu 16: sort flowers name AZ
void sort_name(Flower DS[], int N) {
  for (int i = 0; i < N - 1; i++) {
    for (int j = i + 1; j < N; j++) {
      if (strcmp(DS[i].name, DS[j].name) > 0)
        swap(DS[i].name, DS[j].name);
    }
  }

  printf("====== SORT FLOWERS BY NAME ======\n");
  printf("%-12s|%-32s|%4s|%10s|%20s\n", "No", "Name", "Price", "Qty", "Type");

  for (int i = 0; i < N; i++) {
    printf("%-12d|%-32s|%4.1f|%10d|%20s\n", DS[i].no, DS[i].name, DS[i].price,
           DS[i].quantity, DS[i].type);
  }
}

// câu 17: find top 3 most expensive flowers
void top3expesive_price(Flower DS[], int N) {

  float max1 = DS[0].price;
  for (int i = 0; i < N; i++) {
    if (DS[i].price > max1)
      max1 = DS[i].price;
  }

  cout << " top 1: " << endl;
  for (int i = 0; i < N; i++) {
    if (DS[i].price == max1)
      cout << DS[i].name << endl;
  }

  float max2;
  int foundmax2 = 0;
  for (int i = 0; i < N; i++) {
    if (DS[i].price != max1) {
      max2 = DS[i].price;
      foundmax2 = 1;
      break;
    }
  }
  if (foundmax2 == 0)
    return;
  else {
    for (int i = 0; i < N; i++) {
      if (DS[i].price > max2 && DS[i].price != max1)
        max2 = DS[i].price;
    }
    cout << " top 2: " << endl;
    for (int i = 0; i < N; i++) {
      if (DS[i].price == max2)
        cout << DS[i].name << endl;
    }

    float max3;
    int foundmax3 = 0;
    for (int i = 0; i < N; i++) {
      if (DS[i].price != max1 && DS[i].price != max2) {
        max3 = DS[i].price;
        foundmax3 = 1;
        break;
      }
    }

    if (foundmax3 == 0)
      return;
    else {
      for (int i = 0; i < N; i++) {
        if (DS[i].price > max3 && DS[i].price != max1 && DS[i].price != max2)
          max3 = DS[i].price;
      }
      cout << " top 3: " << endl;
      for (int i = 0; i < N; i++) {
        if (DS[i].price == max3)
          cout << DS[i].name << endl;
      }
    }
  }
}

// câu 18: find flowers with the name containing a keyword
void keyword(Flower DS[], int N) {
  char keyword[50];

  cout << "Nhap keyword: ";
  cin.getline(keyword, 50);

  char keywordlower[50];
  strcpy(keywordlower, keyword);

  for (int i = 0; keywordlower[i] != '\0'; i++) {
    keywordlower[i] = tolower(keywordlower[i]);
  }

  int found = 0;

  for (int i = 0; i < N; i++) {
    char namelower[50];
    strcpy(namelower, DS[i].name);

    for (int j = 0; namelower[j] != '\0'; j++) {
      namelower[j] = tolower(namelower[j]);
    }

    if (strstr(namelower, keywordlower) != NULL) {
      cout << DS[i].name << endl;
      found = 1;
    }
  }

  if (found == 0)
    cout << " k tim thay flowers!" << endl;
}

// câu 19: calculate avearage quantity by type
void avg_quanntity_bytype(Flower DS[], int N) {
  for (int i = 0; i < N; i++) {

    int daco = 0;
    for (int j = 0; j < i; j++) {
      if (strcmp(DS[i].type, DS[j].type) == 0) {
        daco = 1;
        break;
      }
    }

    if (daco == 1)
      continue;

    float avg = 0;
    int sum = 0;
    int count = 0;
    for (int j = 0; j < N; j++) {
      if (strcmp(DS[i].type, DS[j].type) == 0) {
        sum = sum + DS[j].quantity;
        count++;
      }
    }
    avg = float(sum) / count;
    cout << DS[i].type << ": type nay có avg: " << avg;
  }
}

// câu 20: Generate a simple report
void simple_report(Flower DS[], int N) {
  int total_quantity = 0;
  float sum_price = 0;

  for (int i = 0; i < N; i++) {
    total_quantity = total_quantity + DS[i].quantity;
    sum_price = sum_price + DS[i].price;
  }

  cout << "====== SIMPLE REPORT ======" << endl;
  cout << "Total number of flowers: " << N << endl;
  cout << "Total quantity: " << total_quantity << endl;
  cout << "Average price: " << sum_price / N << endl;
  cout << "Number of flowers in each type:" << endl;

  for (int i = 0; i < N; i++) {
    int daco = 0;

    for (int j = 0; j < i; j++) {
      if (strcmp(DS[i].type, DS[j].type) == 0) {
        daco = 1;
        break;
      }
    }

    if (daco == 1)
      continue;

    int count = 0;

    for (int j = 0; j < N; j++) {
      if (strcmp(DS[i].type, DS[j].type) == 0)
        count++;
    }

    cout << DS[i].type << ": " << count << endl;
  }
}

int main() {

  Flower flowers[20];
  int N;
  do {
    cout << "Number of flowers: ";
    cin >> N;
    if (N < 1 || N > 20)
      cout << "please enter the suitable number of flowers from 1 to 20!";
  } while (N < 1 || N > 20);

  cin.ignore();
  nhapflowers(flowers, N);
  inflowers(flowers, N);
  max_price(flowers, N);
  min_price(flowers, N);
  max_quantity(flowers, N);
  sum_quantity(flowers, N);
  average_price(flowers, N);
  cout_eachtype(flowers, N);
  findflower_bytype(flowers, N);

  Flower x;
  x = search_name(flowers, N);
  cout << "In thong tin hoa: \n";
  cout << "No      : " << x.no << endl;
  cout << "Name    : " << x.name << endl;
  cout << "Price   : " << x.price << endl;
  cout << "Quantity: " << x.quantity << endl;
  cout << "Type    : " << x.type << endl;

  checkflower(flowers, N);
  count_flowers_lowerquantity(flowers, N);
  count_flowers_pricerange(flowers, N);
  total_value(flowers, N);
  mostvalueflower(flowers, N);
  sort_name(flowers, N);
  top3expesive_price(flowers, N);
  keyword(flowers, N);
  avg_quanntity_bytype(flowers, N);
  simple_report(flowers, N);

  return 0;
}