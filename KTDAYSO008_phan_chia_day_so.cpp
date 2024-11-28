#include<bits/stdc++.h>
using namespace std;
int ptds(const vector<int>& arr){
    int n = arr.size();
    int tong = 0;
    for(int num : arr){
        tong += num;
    }
    vector<bool> dp(tong/2 + 1, false);
    dp[0] = true;
    for(int num : arr){
        for(int j = tong/2 ; j >= num; --j){
            dp[j] = dp[j] || dp[j-num]; 
        }
    }
    int sum1 = 0;
    for(int i = tong /2; i >= 0; --i){
        if(dp[i]){
            sum1 = i;
            break;
        }
    }
    int sum2 = tong - sum1;
    return abs(sum2 - sum1);
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int N;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; ++i){
            cin >> arr[i];
        }
        cout << ptds(arr) << endl;
    }
    return 0;
}