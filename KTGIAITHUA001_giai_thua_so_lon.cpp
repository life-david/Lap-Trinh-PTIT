#include <bits/stdc++.h>
using namespace std;

long long a[10000];

void solve(int n){
    long long m = 1, q, r = 0;
    a[0] = 1;
    for (int i = 2; i <= n ; i++){
        for (int j = 0; j < m; j++){
            q = a[j] * i + r;
            a[j] = q % 1000000;
            r = q / 1000000;
        }
        while(r > 0){
            a[m] = r % 1000000;
            r /= 1000000;
            m++;
        }
    }
    cout << a[m-1];
    for (int i = m - 2; i >= 0; i--){
        cout <<setw(6) << setfill('0') << a[i];
    }
    cout << endl;
}

int main(){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        solve(n);
    }
    return 0;
}