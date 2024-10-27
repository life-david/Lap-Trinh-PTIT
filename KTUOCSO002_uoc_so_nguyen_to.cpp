#include <bits/stdc++.h>
#define ll long long
using namespace std;

int t;
ll n;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        int dem=0, uoc=2;
        while(n!=1){
            if(n%uoc==0) dem++;
            while(n%uoc==0) n/=uoc;
            uoc++;
            if(uoc>sqrt(n)) break;
        }
        if(n!=1) dem++;
        cout << dem << '\n';
    }
    return 0;
}