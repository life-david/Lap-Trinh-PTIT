#include <iostream>
#include <vector>
using namespace std;

// Ham tao day Fibonacci nho hon n hoac bang n
vector<int> generateFibonacci(int n){
    vector<int> fib = {1, 2}; // Bat dau tu F2 = 1 ; F3 = 2
    int a = 1, b = 2;
    while(true){
        int c = a+b;
        if(c > n) break;
        fib.push_back(c);
        a=b;
        b=c;
    }
    return fib;
}

//Ham de quy tim so cach bieu dien
int countWays(int n, const vector<int>& fib, int idx){
    if(n==0) return 1; // Neu n == 0 tim duoc 1 cach
    if(n < 0 || idx < 0) return 0;  // Neu n < 0 hoac khong con so Fibonacci nao de chon, khong co cach
//Khong chon fib[idx] hoac chon fib[idx] va tiep tuc de quy voi gia tri mo
    return countWays(n, fib, idx -1) + countWays(n-fib[idx],fib, idx -1);

}

int main(){
    int t;
    cin >> t;
   // Toi da N la 10^5, sinh day Fibonacci truoc
   vector<int>fib = generateFibonacci(100000);
   while(t--){
    int n;
    cin >>n;
    cout << countWays(n, fib, fib.size() - 1) << endl;
   }
   return 0;
}
