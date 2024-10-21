#include <iostream>
#include <vector>
using namespace std;

string DEC2BIN (long long n){
    string binary = "";
    if (n == 0) return "0";
    while (n > 0){
        binary = (n%2 == 0 ? "0" : "1") + binary;
        n /= 2;
    }
    return binary;
}
int main(){ 
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        cout << DEC2BIN(n) << endl;
    }
    return 0;
}