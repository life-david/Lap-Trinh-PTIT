#include<bits/stdc++.h>
using namespace std;

float x;
int n;
float Bp(float n, float k){
    float ans = 1;
    for(int i = 1; i <= k; ++i) ans*=n;
    return ans;
}
int main(){
    int t;
    cin >> t;
    while(t--){
       cin >> n >> x;
       float tmp=1, s=0;
       for(float i=1; i <= n; ++i){
            s = sqrt(Bp(x,i)+s);
       }
       cout<<fixed<<setprecision(3)<<s<<'\n';
    }
    return 0;
}