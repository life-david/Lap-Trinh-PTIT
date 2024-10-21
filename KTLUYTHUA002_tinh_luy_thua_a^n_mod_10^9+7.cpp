#include <iostream>
#define MOD 1000000007

using namespace std;


long long power_mod(long long a, long long n) {
    if (n == 0) return 1; 
    long long half = power_mod(a, n / 2);
    half = (half * half) % MOD; 
    if (n % 2 != 0) half = (half * a) % MOD;  
    return half;
}

int main() {
    int T;
    cin >> T;  
    while (T--) {
        long long a, n;
        cin >> a >> n;
        cout << power_mod(a, n) << endl;
    }
    return 0;
}