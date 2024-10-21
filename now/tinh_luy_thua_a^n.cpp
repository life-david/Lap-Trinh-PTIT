#include<iostream>
using namespace std;

const long long MOD = 1e9 + 7;

long long pow_mod(long long a, long long n, long long mod) {
    if(n == 0) return 1; // a^0 = 1
    long long half = pow_mod(a, n / 2, mod);
    half = (half * half) % mod; // Tính half^2 và áp dụng mod
    if(n % 2 != 0) half = (half * a) % mod; // Nếu n lẻ, nhân thêm a và mod lại
    return half;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long a, n;
        cin >> a >> n;
        cout << pow_mod(a, n, MOD) << endl; // Sử dụng pow_mod để tính kết quả
    }
    return 0;
}