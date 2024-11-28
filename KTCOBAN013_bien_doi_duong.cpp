#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int count_negative = 0; // Đếm số phần tử âm
        int count_zero = 0;     // Đếm số phần tử bằng 0

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == 0) count_zero++;
            if (x < 0) count_negative++;
        }

        if (count_zero > 0) {
            cout << "-1" << endl; // Có phần tử bằng 0
        } else {
            if (count_negative <= n / 2) {
                cout << count_negative << endl; // Số phần tử âm <= n/2
            } else {
                cout << n - count_negative << endl; // Số phần tử dương nhiều hơn
            }
        }
    }
    return 0;
}
