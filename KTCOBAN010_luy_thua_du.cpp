#include <iostream>
using namespace std;
const int MOD = 1000000007; // 10^9 + 7
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a, n;
        cin >> a >> n;
        cout << binpow(a, n) << endl;
    }
    return 0;
}