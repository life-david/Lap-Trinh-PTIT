#include <iostream>
#include <string>

using namespace std;

// Hàm thay thế '5' bằng '3' để tính tổng nhỏ nhất
int toMin(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '5') {
            s[i] = '3';
        }
    }
    return stoi(s); // Chuyển chuỗi thành số nguyên
}

// Hàm thay thế '3' bằng '5' để tính tổng lớn nhất
int toMax(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '3') {
            s[i] = '5';
        }
    }
    return stoi(s); // Chuyển chuỗi thành số nguyên
}

int main() {
    int T;
    cin >> T; // Đọc số lượng bộ test

    while (T--) {
        string A, B;
        cin >> A >> B; // Đọc hai số A và B dưới dạng chuỗi

        // Tính tổng nhỏ nhất
        int minSum = toMin(A) + toMin(B);

        // Tính tổng lớn nhất
        int maxSum = toMax(A) + toMax(B);

        // In kết quả
        cout << minSum << " " << maxSum << endl;
    }

    return 0;
}