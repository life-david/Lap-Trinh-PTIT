#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e9 + 7;
vector<vector<long long>> matrixMultiply(const vector<vector<long long>>& A, const vector<vector<long long>>& B) {
    int n = A.size();
    vector<vector<long long>> C(n, vector<long long>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}
vector<vector<long long>> matrixPower(vector<vector<long long>>& A, long long K) {
    int n = A.size();
    vector<vector<long long>> result(n, vector<long long>(n, 0));
    for (int i = 0; i < n; ++i) {
        result[i][i] = 1; // Kh?i t?o ma tr?n don v?
    }
    
    while (K > 0) {
        if (K % 2 == 1) {
            result = matrixMultiply(result, A);
        }
        A = matrixMultiply(A, A);
        K /= 2;
    }
    return result;
}
long long sumSecondaryDiagonal(const vector<vector<long long>>& A) {
    long long sum = 0;
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        sum = (sum + A[i][n - i - 1]) % MOD;
    }
    return sum;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        long long K;
        cin >> N >> K;

        vector<vector<long long>> A(N, vector<long long>(N));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> A[i][j];
            }
        }
        vector<vector<long long>> result = matrixPower(A, K);
        long long secondaryDiagonalSum = sumSecondaryDiagonal(result);

        cout << secondaryDiagonalSum << endl;
    }

    return 0;
}