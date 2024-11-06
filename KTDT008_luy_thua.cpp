#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int st, t;
    scanf("%d", &st);  // Number of test cases
    for (t = 1; t <= st; t++) {
        long long L, R;
        cin >> L >> R;

        // Variable to check if we found a valid `k`
        bool found = false;
        
        // Iterate over possible values of `k`
        for (int k = 40; k >= 1; --k) {
            long long left = 1, right = (long long)(pow(R, 1.0 / k) + 1);
            while (left <= right) {
                long long mid = (left + right) / 2;
                long long z = 1;

                // Calculate mid^k using a loop to avoid overflow
                for (int i = 0; i < k; ++i) {
                    z *= mid;
                    if (z > R) break;  // Stop if z exceeds R
                }

                if (L <= z && z <= R) {
                    printf("%d\n", k);  // Print the highest valid `k` found
                    found = true;
                    break;
                }

                // Binary search adjustments
                if (z < L) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            if (found) break;  // Break the loop if a valid `k` is found
        }
        
        if (!found) {
            printf("No valid k found\n");  // Case if no k satisfies the conditions
        }
    }

    return 0;
}