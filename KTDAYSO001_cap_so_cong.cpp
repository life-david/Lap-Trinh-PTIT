#include<bits/stdc++.h>
#include<math.h>

using namespace std;
bool csc(long long a[], int n){
   
    
    int d = a[1] - a[0];
    for(int i = 1 ; i < n ; i++){
        if(a[i] - a[i - 1] != d){
            return false;
        }
    }
    return true ;
}
int main(){
    int t;
    cin >> t;
    while(t--){
    long long n ;
    cin >> n;
    long long a[n];
    for(long long i = 0 ; i < n; i++){
      cin >> a[i];   
    }
    if(csc(a, n)==1){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
  }
    return 0;
}