#include <iostream>
using namespace std;
long long coutZero(long long n){
    long long cout = 0;
    for (long long i = 5; n/i >= 1; i *= 5){
        cout += n/i;
    }
    return cout;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        long long n;
        cin >> n;
        cout << coutZero(n) << endl;
    }
    return 0;
}