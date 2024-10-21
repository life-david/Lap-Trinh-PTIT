#include <iostream>
#include <cmath>
using namespace std;

long long check(int x){
    long long sum_uoc = 1; // Bắt đầu từ 1 vì 1 luôn là ước của mọi số
    int sqrt_x = sqrt(x);
    for (int i = 2; i <= sqrt_x; i++) {
        if (x % i == 0) {
            sum_uoc += i;
            if (i != x / i) {
                sum_uoc += x / i;
            }
        }
    }
    if (sum_uoc == x && x != 1) {
        return 1;
    }
    else {
        return 0;
    }
}

int main(){
    int t;
    cin >> t;
    while (t--){
        long long n;
        cin >> n;
        if (check(n)){
            cout << "1\n";
        }
        else{
            cout << "0\n";
        }
    }
    return 0;
}