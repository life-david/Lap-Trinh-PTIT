#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        string binaryStr;
        cin >> binaryStr;
        
       
        long long decimalValue = stoll(binaryStr, nullptr, 2);
        
       
        cout << decimalValue << endl;
    }
    
    return 0;
}