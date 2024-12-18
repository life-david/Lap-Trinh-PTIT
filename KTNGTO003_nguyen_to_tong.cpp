#include <bits/stdc++.h>
using namespace std;
int ngto(long long n){
    int m = sqrt(n);
    for(int i=3; i<=m; i+=2)
        if(n%i == 0) return 0;
        return 1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        if(n<=4) cout << 5 << endl;
        else {
            if(n%2 == 0) n++;
            while(n>0){
                if(ngto(n-2) && ngto(n)) break;
                n += 2;
            }
            cout << n << endl;
        }
    }
    return 0;
}