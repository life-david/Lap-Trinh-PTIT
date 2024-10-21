#include <iostream>
#include <cmath>
using namespace std;

long long USNT_MAX(long long N){
    long long maxPrime = -1;
    while (N%2 == 0){
        maxPrime = 2;
        N /= 2;
    }
    for (int i =3; i <= sqrt(N) ; i += 2){
        while (N % i == 0){
            maxPrime = i;
            N /= i;
        }
    }
    if (N > 2){
        maxPrime = N;
    }
    return maxPrime;
}

int main(){
    int t;
    cin >> t;

    while (t--){
        long long N;
        cin >> N;
        cout << USNT_MAX(N) << endl;
    }
    return 0;
}