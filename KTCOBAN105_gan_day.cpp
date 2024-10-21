#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 +7;
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<long long> lengths(n);
        for (int i = 0; i < n ;i++){
            cin >> lengths[i];
        }
        sort (lengths.begin(), lengths.end());
        long long ganday = 0;
        while (lengths.size() >1){
            long long first = lengths[0];
            long long second = lengths[1];
            long long combined = first + second;
            ganday = (ganday + combined)%MOD;
            lengths.erase(lengths.begin());
            lengths.erase(lengths.begin());
            lengths.insert(lower_bound(lengths.begin(), lengths.end(), combined), combined);

        }  
        cout << ganday << endl;
    }
    return 0;
}