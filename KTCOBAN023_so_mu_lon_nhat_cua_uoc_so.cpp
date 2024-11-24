#include <bits/stdc++.h>
using namespace std;

// Hàm tìm số lũy thừa của số nguyên tố `p` trong `fact!`
long long findPowerPrime(long long fact, long long p) {
    long long res = 0;
    while (fact > 0) {
        res += fact / p;
        fact /= p;
    }
    return res;
}

// Hàm tìm lũy thừa cao nhất mà `n` (số hợp số) có thể chia hết trong `fact!`
long long findPowerComposite(long long fact, long long n) {
    long long res = LLONG_MAX; // Sử dụng giá trị lớn nhất của `long long`
    for (long long i = 2; i * i <= n; i++) {
        long long count = 0;

        // Phân tích `n` thành thừa số nguyên tố
        while (n % i == 0) {
            count++;
            n /= i;
        }

        // Nếu `i` là một thừa số nguyên tố của `n`
        if (count > 0) {
            long long curr_pow = findPowerPrime(fact, i) / count;
            res = min(res, curr_pow);
        }
    }

    // Nếu còn lại `n >= 2`, tức là `n` là số nguyên tố lớn
    if (n >= 2) {
        long long curr_pow = findPowerPrime(fact, n);
        res = min(res, curr_pow);
    }

    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long fact, n;
        cin >> fact >> n;

        // Xử lý và in kết quả
        cout << findPowerComposite(fact, n) << endl;
    }
    return 0;
}
