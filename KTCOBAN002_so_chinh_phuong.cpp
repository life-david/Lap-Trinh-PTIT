#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// Hàm kiểm tra xem một số có phải là số chính phương với các chữ số là số chính phương không
bool isValid(long long n) {
    string s = to_string(n);
    for (char c : s) {
        if (c != '0' && c != '1' && c != '4' && c != '9') {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;

        long long start = pow(10, k-1);  // Bắt đầu từ số nhỏ nhất có k chữ số
        long long end = pow(10, k);      // Kết thúc ở số lớn nhất có k chữ số

        bool found = false;
        for (long long i = sqrt(start); i * i < end; ++i) {
            long long square = i * i;
            if (square >= start && isValid(square)) {
                cout << square << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << -1 << endl; // Không tìm thấy số phù hợp
        }
    }
    return 0;
}