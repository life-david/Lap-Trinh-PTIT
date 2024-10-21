#include <iostream>
using namespace std;
long long demday(long long b, long long exp, long long mod){
    long long r = 1;
    while (exp > 0){
        if(exp % 2 == 1){
            r = (r*b)%mod;         
        }
        b = (b*b) % mod;
        exp /= 2;
    }
    return r;
}

int main(){
    int t;
    cin >> t;
    const long long mod = 123456789;
    while(t--){
        long long n;
        cin >> n;
        long long r = demday(2, n-1, mod);
        cout << r << endl;
    }
    return 0;
}