#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define f(i,a,b) for(int i=a; i<=b; ++i)
#define fn(i,a,b) for(int i=a; i>=b; --i)
using namespace std;

int t, l, r, check[1000005], dem[1000005];
int main() {
ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  check[1]=1;
  for(int i=2; i<=1000000; ++i){
    if(check[i]==0)
      for(int j=i*2; j<=1000000; j+=i){
        check[j]=1;
      }
  }
  for(int i=1; i<=1000000; ++i){
    if(check[i]==0) dem[i]=dem[i-1]+1;
    else dem[i]=dem[i-1];
  }
  cin >> t;
  while(t--){
    cin >> l >> r;
    cout << dem[r]-dem[l-1] <<'\n';
  }
return 0;
}