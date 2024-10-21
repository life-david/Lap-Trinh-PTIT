#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int countPartitions(int N) {
   
    vector<int> dp(N + 1, 0);
    dp[0] = 1;  

   
    for (int i = 1; i < N; ++i) {
        for (int j = i; j <= N; ++j) {
            dp[j] = (dp[j] + dp[j - i]) % MOD;
        }
    }

    return dp[N];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        cout << countPartitions(N) << endl;
    }
    return 0;
}