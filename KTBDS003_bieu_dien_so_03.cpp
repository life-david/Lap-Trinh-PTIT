#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 50;
const int MAXK = 50;
const int MAXT = 1000;

//Ham tinh to hop C(n, k)
long long combination(int n, int k){
    if(k > n || n < 0) return 0; // neu k>n hoac n<o khong hop le
    if(k == 0 || k == n) return 1; // C(n,0) = C(n,n) =1

    long long res = 1;
    for (int i =1; i<= k ; i++){
        res *= (n -i +1);
        res /= i;
    }
    return res;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int N, K;
        cin >> N >> K;
        //Neu N < K thi khong co cach nao de phan tich
        if(N < K){
            cout << 0<< endl;
        }
        else{
            //Tinh C(N-1, K-1)
            cout << combination (N-1, K-1) << endl;
        }
    }
    return 0;
}