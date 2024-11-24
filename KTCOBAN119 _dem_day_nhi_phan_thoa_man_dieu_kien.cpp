#include <bits/stdc++.h>
using namespace std;

int binary(int n) {
    int count = 0;
    while (n > 0) {
        if ((n & 1) == 0) {
            count++;
        }
        n >>= 1;
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false); // Sửa lỗi cú pháp
    cin.tie(NULL);

    int t;
    cin >> t; // Thêm đọc giá trị t
    while (t--) {
        int n, k;
        cin >> n >> k;
        int dem = 0;
        for (int i = 0; i <= n; i++) {
            if (binary(i) == k) {
                dem++;
            }
        }
        cout << dem << endl;
    }
    return 0;
}
