#include <iostream>
using namespace std;

// =====================================
// BÀI CHÍNH
// =====================================

// Đưa phần tử đầu tiên của mảng về 0
void setFirstToZero(int arr[]) {
    arr[0] = 0;
}

// Tăng tất cả phần tử trong mảng lên 1
void incrementAll(int (&arr)[4]) {
    for (int i = 0; i < 4; ++i) {
        arr[i] += 1;
    }
}

// =====================================
// TRY A VARIATION
// =====================================

// Đưa phần tử được truyền vào về 10
void setLastToTen(int& x) {
    x = 10;
}

// =====================================
// MAIN
// =====================================

int main() {

    // ---------------------------------
    // Practice 5 - Bài chính
    // ---------------------------------

    int nums[4] = {1, 2, 3, 4};

    setFirstToZero(nums);
    incrementAll(nums);

    cout << "Practice 5:" << endl;
    cout << nums[0] << " "
         << nums[1] << " "
         << nums[2] << " "
         << nums[3] << endl;


    // ---------------------------------
    // Try a Variation
    // ---------------------------------

    int nums2[4] = {3, 5, 7, 9};

    // nums2[3] được truyền bằng reference
    setLastToTen(nums2[3]);

    cout << "Variation:" << endl;

    for (int i = 0; i < 4; ++i) {
        cout << nums2[i] << " ";
    }

    cout << endl;

    return 0;
}