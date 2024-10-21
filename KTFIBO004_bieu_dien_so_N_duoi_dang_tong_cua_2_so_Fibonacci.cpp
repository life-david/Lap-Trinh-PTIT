#include <iostream>
#include <vector>
using namespace std;

// Hàm sinh dãy Fibonacci nhỏ hơn hoặc bằng n
vector<int> generateFibonacci(int n) {
    vector<int> fib = {0, 1};  // Bắt đầu từ F0 = 0, F1 = 1
    int a = 0, b = 1;
    while (true) {
        int c = a + b;
        if (c > n) break;
        fib.push_back(c);
        a = b;
        b = c;
    }
    return fib;
}

int main() {
    int t;  // Số lượng test case
    cin >> t;
    
    // Tối đa N là 10^6, sinh dãy Fibonacci trước
    vector<int> fib = generateFibonacci(1000000);
    
    while (t--) {
        int n;
        cin >> n;
        
        bool found = false;
        
        // Duyệt qua tất cả các cặp Fibonacci
        for (int i = 0; i < fib.size(); ++i) {
            for (int j = i; j < fib.size(); ++j) {
                if (fib[i] + fib[j] == n) {
                    cout << fib[i] << " " << fib[j] << endl;
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        
        if (!found) {
            cout << -1 << endl;
        }
    }
    
    return 0;
}