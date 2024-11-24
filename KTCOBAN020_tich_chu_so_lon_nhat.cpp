#include <bits/stdc++.h>
using namespace std;

// Hàm tính tích lớn nhất của các chữ số với phép thay đổi
unsigned long long max_1(unsigned long long N) {
    if (N == 0) return 1; // Điều kiện thoát

    unsigned long long current_digit = N % 10;
    unsigned long long remaining_digits = N / 10;

    // Trường hợp không thay đổi gì
    unsigned long long option1 = max_1(remaining_digits) * current_digit;

    // Trường hợp thay đổi chữ số hiện tại thành 9 (nếu có thể)
    if (remaining_digits > 0) { // Chỉ thay đổi khi còn số hàng cao hơn
        unsigned long long option2 = max_1(remaining_digits - 1) * 9;
        return max(option1, option2); // Trả về giá trị lớn nhất
    }

    return option1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        unsigned long long n;
        cin >> n;
        cout << max_1(n) << endl;
    }
    return 0;
}
