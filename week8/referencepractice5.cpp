#include <iostream>
using namespace std;

// Hàm đưa phần tử đầu tiên của mảng về 0
void setFirstToZero(int arr[])
{
    arr[0] = 0;
}

// Hàm tăng tất cả phần tử lên 1
void incrementAll(int (&arr)[4])
{
    for (int i = 0; i < 4; ++i)
    {
        arr[i] += 1;
    }
}

int main()
{
    // Khai báo mảng
    int nums[4] = {1, 2, 3, 4};

    // Đưa phần tử đầu tiên về 0
    setFirstToZero(nums);

    // Tăng tất cả phần tử lên 1
    incrementAll(nums);

    // In kết quả
    cout << nums[0] << " "
         << nums[1] << " "
         << nums[2] << " "
         << nums[3] << endl;

    return 0;
}