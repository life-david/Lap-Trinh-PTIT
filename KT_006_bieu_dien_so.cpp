#include <iostream>
#include <vector>
using namespace std;

int countWays(int n, int m) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;  
    vector<int> powers;
    int power = 1;
    while (power <= n) {
        powers.push_back(power);
        power *= m;
    }

    for (int p : powers) {
        for (int i = p; i <= n; ++i) {
            dp[i] += dp[i - p];
        }
    }

    return dp[n];
}

int main() {
    int t;
    cin >> t;  

    while (t--) {
        int n, m;
        cin >> n >> m;  
        cout << countWays(n, m) << endl;
    }

    return 0;
}