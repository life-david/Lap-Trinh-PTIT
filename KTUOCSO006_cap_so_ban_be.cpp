// cap so ban be là một dãy số mà mỗi số là tổng của các ước số của số trước nó bằng số còn lại
#include <bits/stdc++.h>
using namespace std;

long long sum_uoc(long long n){
    long long sum = 0;
    for (int i = 1; i <= n/2; i++){ // uoc lon nhat cua n khong vuot qua n/2
        if (n % i == 0){
            sum += i;
        }
    }
    return sum;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        long long a,b;
        cin >> a >> b;
        long long sum_a = sum_uoc(a);
        long long sum_b = sum_uoc(b);
        if ( sum_a == b && sum_b == a){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}