#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_LIMIT = 10000; // Giới hạn cao để tạo đủ số nguyên tố

// Hàm sinh các số nguyên tố lên đến MAX_LIMIT bằng Sieve of Eratosthenes
vector<int> generatePrimes(int start) {
    vector<bool> isPrime(MAX_LIMIT + 1, true);
    vector<int> primes;

    // Đánh dấu các số không phải là số nguyên tố
    for (int i = 2; i * i <= MAX_LIMIT; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAX_LIMIT; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Thu thập các số nguyên tố lớn hơn start
    for (int i = max(2, start + 1); i <= MAX_LIMIT; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

// Hàm backtracking để tìm tổ hợp các số nguyên tố
void findCombinations(vector<int>& primes, vector<int>& combination, int index, int N, int S, int currentSum, bool& found) {
    if (combination.size() == N) {
        if (currentSum == S) {
            found = true;
            for (int num : combination) {
                cout << num << " ";
            }
            cout << endl;
        }
        return;
    }

    for (int i = index; i < primes.size(); ++i) {
        if (currentSum + primes[i] > S) break; // Nếu tổng hiện tại + số nguyên tố lớn hơn S thì không cần kiểm tra tiếp
        combination.push_back(primes[i]);
        findCombinations(primes, combination, i + 1, N, S, currentSum + primes[i], found);
        combination.pop_back();
    }
}

int main() {
    int P, N, S;
    cin >> P >> N >> S;

    vector<int> primes = generatePrimes(P);

    vector<int> combination;
    bool found = false; // Biến để kiểm tra xem có tổ hợp nào được tìm thấy không
    findCombinations(primes, combination, 0, N, S, 0, found);

    if (!found) {
        cout << -1 << endl; // Nếu không tìm thấy tổ hợp nào thì in -1
    }

    return 0;
}