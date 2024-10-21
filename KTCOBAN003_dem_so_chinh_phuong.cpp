#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;  // Số lượng test cases
    while (t--) {
        long long L, R;
        cin >> L >> R;

        // Tìm căn bậc hai của L và R
        long long sqrtL = ceil(sqrt(L));  // Số chính phương đầu tiên >= L
        long long sqrtR = floor(sqrt(R)); // Số chính phương cuối cùng <= R

        // Số lượng số chính phương trong đoạn [L, R]
        if (sqrtL > sqrtR) {
            cout << 0 << endl;  // Nếu không có số chính phương nào
        } else {
            cout << (sqrtR - sqrtL + 1) << endl;  // Đếm số số chính phương
        }
    }
    return 0;
}