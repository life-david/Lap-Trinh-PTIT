#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        float x;
        cin >> n >> x;
        float tu = 1, mau = 1, sum =0;
        for(int i=1; i <=n; ++i){
            tu *= x;
            mau *= i;
            sum += tu/mau;
        }
        cout << fixed << setprecision(3) << sum << endl;
    }
    return 0;
}