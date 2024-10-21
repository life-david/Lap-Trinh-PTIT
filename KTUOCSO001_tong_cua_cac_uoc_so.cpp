#include <iostream>
#include <cmath>
using namespace std;

long long Tong_Uoc(int n){
    long long sum=0;
    for(int i=1 ; i <= sqrt(n); i++){
      if(n % i==0){
        if( i < n){
            sum += i;
        }
       
      int pair = n/i;
      if (pair != i && pair < n){
        sum += pair;
      }
    }
    }
    return sum;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << Tong_Uoc(n) << endl;
    }
    return 0;
}