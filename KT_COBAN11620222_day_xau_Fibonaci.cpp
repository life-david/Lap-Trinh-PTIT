#include <iostream>
#include <vector>
using namespace std;
vector <long long> fib_len(93);

void calculate_lengths(){
    fib_len[1] = 1;
    fib_len[2] = 1;
    for(int n = 3; n <= 92; ++n){
        fib_len[n] = fib_len[n-2] + fib_len[n-1];
    }
}

char find_char(int n, long long i){
    if(n == 1) return 'A';
    if(n == 2) return 'B';
    if(i <= fib_len[n-2]){
        return find_char(n-2,i);
    }
    else{
        return find_char(n-1, i-fib_len[n-2]);
    }
}

int main(){
    int t;
    cin >> t;
    calculate_lengths();
    while(t--){
        int n;
        long long i;
        cin >> n >> i;
        cout << find_char(n, i) << endl;
    }
    return 0;
}