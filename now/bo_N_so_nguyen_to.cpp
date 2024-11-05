#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_LIMIT = 10000; // Set a high limit to generate enough primes

// Function to generate prime numbers up to MAX_LIMIT using Sieve of Eratosthenes
vector<int> generatePrimes(int start) {
    vector<bool> isPrime(MAX_LIMIT + 1, true);
    vector<int> primes;

    // Mark non-prime numbers
    for (int i = 2; i * i <= MAX_LIMIT; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAX_LIMIT; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Collect primes greater than the given start
    for (int i = max(2, start + 1); i <= MAX_LIMIT; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

// Backtracking function to find combinations of primes
void findCombinations(vector<int>& primes, vector<int>& combination, int index, int N, int S, int currentSum) {
    if (combination.size() == N) {
        if (currentSum == S) {
            for (int num : combination) {
                cout << num << " ";
            }
            cout << endl;
        }
        return;
    }

    for (int i = index; i < primes.size(); ++i) {
        if (currentSum + primes[i] > S) break;
        combination.push_back(primes[i]);
        findCombinations(primes, combination, i + 1, N, S, currentSum + primes[i]);
        combination.pop_back();
    }
}

int main() {
    int P, N, S;
    cin >> P >> N >> S;

    vector<int> primes = generatePrimes(P);

    vector<int> combination;
    findCombinations(primes, combination, 0, N, S, 0);

    if (combination.empty()) {
        cout << -1 << endl;
    }

    return 0;
}