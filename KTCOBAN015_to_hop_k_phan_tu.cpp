#include <bits/stdc++.h>
#define MAX 50
#define ll long long
using namespace std;

int arr[MAX];
int n, k;

// Hàm tính giai thừa
ll gt(int x) {
    ll result = 1;
    for (int i = 1; i <= x; i++) {
        result *= i;
    }
    return result;
}

// Hàm tính tổ hợp C(n, k)
ll sumKey(int n, int k) {
    if (k > n) return 0; // Trường hợp không hợp lệ
    return gt(n) / (gt(k) * gt(n - k));
}

// Hàm in một tổ hợp
void res() {
    cout << "[";
    for (int i = 1; i <= k; i++) {
        cout << arr[i];
        if (i < k) cout << " ";
    }
    cout << "]\n";
}

// Hàm sinh tổ hợp
void key(int i) {
    for (int j = arr[i - 1] + 1; j <= n - k + i; j++) {
        arr[i] = j;
        if (i == k) {
            res();
        } else {
            key(i + 1);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;

        // In số lượng tổ hợp
        cout << sumKey(n, k) << endl;

        // Sinh tổ hợp
        arr[0] = 0; // Khởi tạo giá trị đầu tiên
        key(1);
    }
    return 0;
}
