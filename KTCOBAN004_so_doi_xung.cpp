#include <iostream>
#include <cmath>
using namespace std;

long long so_dxung(int n) {
    if (n <= 0) return 0; // Kiểm tra n hợp lệ
    return 9 * static_cast<long long>(pow(10, (n - 1) / 2));
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << so_dxung(n) << endl;
    }
    return 0;
}
