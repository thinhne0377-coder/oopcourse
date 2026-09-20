#include <iostream>
#include <vector> 
using namespace std;


void insertSubarray(vector<int>& arr, const vector<int>& sub, int index) {
    // Kiểm tra vị trí chèn hợp lệ để tránh lỗi out-of-bounds
    if (index < 0 || index > arr.size()) {
        cout << "Vi tri chen khong hop le!" << endl;
        return;
    }
    // Chèn toàn bộ vector 'sub' vào 'arr' bắt đầu từ vị trí 'index'
    arr.insert(arr.begin() + index, sub.begin(), sub.end());
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> sub = {9, 9};
    
    // Đổi pos thành vị trí hợp lệ (ví dụ: pos = 2, chèn vào giữa mảng)
    int pos = 2; 

    insertSubarray(nums, sub, pos); // Chèn mảng sub vào vị trí index 2

    // In mảng sau khi chèn (Kết quả: 1 2 9 9 3 4 5)
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}