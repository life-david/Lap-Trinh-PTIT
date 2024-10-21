#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Hàm sàng Eratosthenes để tìm tất cả các số nguyên tố <= S
vector<int> sievePrimes(int maxLimit) {
    vector<int> primes;
    for (int i = 2; i <= maxLimit; i++) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }
    return primes;
}

// Hàm quay lui để tìm các bộ số nguyên tố thỏa mãn điều kiện
void findCombinations(vector<int>& primes, int N, int S, int currentSum, int idx, vector<int>& currentSet, vector<vector<int>>& result) {
    // Nếu đã chọn đủ N số và tổng bằng S, ta thêm bộ vào kết quả
    if (currentSet.size() == N && currentSum == S) {
        result.push_back(currentSet);
        return;
    }
    // Nếu đã chọn đủ N số nhưng tổng khác S, hoặc tổng đã vượt quá S, thì quay lui
    if (currentSet.size() >= N || currentSum > S) {
        return;
    }

    // Duyệt qua các số nguyên tố bắt đầu từ vị trí idx
    for (int i = idx; i < primes.size(); i++) {
        currentSet.push_back(primes[i]);  // Chọn số nguyên tố
        findCombinations(primes, N, S, currentSum + primes[i], i + 1, currentSet, result);  // Tiếp tục quay lui
        currentSet.pop_back();  // Bỏ chọn số nguyên tố
    }
}

int main() {
    int P, N, S;
    cin >> P >> N >> S;

    // Tìm tất cả các số nguyên tố nhỏ hơn hoặc bằng S
    vector<int> primes = sievePrimes(S);

    // Loại bỏ các số nguyên tố <= P
    vector<int> validPrimes;
    for (int prime : primes) {
        if (prime > P) {
            validPrimes.push_back(prime);
        }
    }

    // Điều kiện biên: nếu số lượng số nguyên tố lớn hơn P không đủ hoặc tổng tối thiểu vượt quá S
    if (validPrimes.size() < N) {
        cout << -1 << endl;
        return 0;
    }

    // Kiểm tra tổng tối thiểu của N số nguyên tố nhỏ nhất
    int minSum = 0;
    for (int i = 0; i < N; i++) {
        minSum += validPrimes[i];
    }

    if (minSum > S) {
        cout << -1 << endl;
        return 0;
    }

    // Tìm tất cả các bộ số thỏa mãn
    vector<vector<int>> result;
    vector<int> currentSet;
    findCombinations(validPrimes, N, S, 0, 0, currentSet, result);

    // In kết quả
    if (result.empty()) {
        cout << -1 << endl;
    } else {
        for (const auto& combination : result) {
            for (int prime : combination) {
                cout << prime << " ";
            }
            cout << endl;
        }
    }

    return 0;
}