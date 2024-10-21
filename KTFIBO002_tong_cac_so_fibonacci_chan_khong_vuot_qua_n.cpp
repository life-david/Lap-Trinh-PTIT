#include<bits/stdc++.h>
using namespace std;
long long f[55];
vector<long long> v;
void fibo(){
 f[0]=0;
 f[1]=1;
 for (int i=2;i<=50;i++) {
  f[i]=f[i-1]+f[i-2];
  if (f[i]%2==0) v.push_back(f[i]);
 }
}
int main()
{
 fibo();
 int t;
 cin>> t;
 while (t--) {
  long long n;
  cin>> n;
  long long ans=0;
  for (int i=0;i<v.size();i++) {
   if (v[i]<=n) {
    ans=ans+v[i];
   }
  }
  cout << ans << endl;
 }
}