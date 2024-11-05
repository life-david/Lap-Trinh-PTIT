#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        vector<pair<long long, int>> factors;
        
        // Factor out 2 first
        if (n % 2 == 0) {
            int count = 0;
            while (n % 2 == 0) {
                count++;
                n /= 2;
            }
            factors.push_back({2, count});
        }

        // Factor out odd numbers starting from 3
        for (long long i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                int count = 0;
                while (n % i == 0) {
                    count++;
                    n /= i;
                }
                factors.push_back({i, count});
            }
        }

        // If n is a prime number greater than 2
        if (n > 1) {
            factors.push_back({n, 1});
        }

        // Output the result
        cout << factors.size() << endl;
        for (const auto& factor : factors) {
            cout << factor.first << " " << factor.second << endl;
        }
    }
    return 0;
}