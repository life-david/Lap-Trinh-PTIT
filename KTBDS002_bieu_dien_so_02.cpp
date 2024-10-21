#include <iostream>
#include <vector>
using namespace std;

//Ham tinh to hop C(n,k)
long long combination(int n, int k){
    if(k > n || n < 0) return 0; // Truong hop khong hop le
    if(k == 0 || k == n) return 1; // C(n,0) = C(n,n) = 1
    long long res = 1;
    for(int i = 1; i <= k; i++){
        res *= (n-i+1);
        res /= i;
    }
    return res;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int N, K;
        cin >> N >> K;
        //So cach bieu dien N thanh tong cua K so tu nhien la C(N+K-1,K-1)
        cout << combination(N+K-1,K-1) << endl;
    }
    return 0;
}