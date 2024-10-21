#include <iostream>
#include <string>
#define MOD 1000000007
using namespace std;

// Hàm tính lũy thừa nhanh a^b mod m
long long powerMod(long long a, long long b, long long m) {
    long long result = 1;
    a = a % m;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % m;
        }
        a = (a * a) % m;
        b /= 2;
    }
    return result;
}

// Hàm tính b % (MOD-1) khi b là số rất lớn
long long largeMod(const string &b, long long mod) {
    long long result = 0;
    for (char digit : b) {
        result = (result * 10 + (digit - '0')) % mod;
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string a_str, b_str;
        cin >> a_str >> b_str;

        // Chuyển a về dạng số nguyên long long
        long long a = 0;
        for (char digit : a_str) {
            a = (a * 10 + (digit - '0')) % MOD;
        }

        // Tính b % (MOD-1)
        long long b_mod = largeMod(b_str, MOD - 1);

        // Tính a^b_mod % MOD
        cout << powerMod(a, b_mod, MOD) << endl;
    }

    return 0;
}