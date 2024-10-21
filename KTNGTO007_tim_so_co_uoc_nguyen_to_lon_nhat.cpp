#include <iostream>
#include <cmath>

using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Hàm tìm ước nguyên tố lớn nhất
int largestPrimeFactor(int n) {
    int largestFactor = 1;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (isPrime(i)) {
                largestFactor = i;
            }
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1 && isPrime(n)) {
        largestFactor = n;
    }
    return largestFactor;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int L, R;
        cin >> L >> R;

        int maxFactor = 1;
        int result = L;

        for (int i = L; i <= R; i++) {
            int factor = largestPrimeFactor(i);
            if (factor > maxFactor) {
                maxFactor = factor;
                result = i;
            } else if (factor == maxFactor && i > result) {
                result = i;
            }
        }

        cout << result << endl;
    }

    return 0;
}