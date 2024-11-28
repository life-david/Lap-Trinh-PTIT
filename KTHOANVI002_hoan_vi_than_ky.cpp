#include <iostream>
#include <vector>
using namespace std;

void check(int n, int k) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i + 1; // Khởi tạo mảng A với giá trị từ 1 đến N
    }

    if (k == 0) { // Trường hợp K = 0, mảng không cần thay đổi
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }

    if (n % (2 * k) != 0) { // Nếu không chia đều được thành các cặp K
        cout << -1 << endl;
        return;
    }

    // Hoán vị các phần tử theo K
    for (int i = 0; i < n; i++) {
        if ((i / k) % 2 == 0) { // Nhóm chẵn: đẩy phần tử lên phía trước
            a[i] = i + 1 + k;
        } else { // Nhóm lẻ: đẩy phần tử xuống phía sau
            a[i] = i + 1 - k;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t; // Nhập số lượng testcase
    while (t--) {
        int n, k;
        cin >> n >> k;
        check(n, k);
    }
    return 0;
}
