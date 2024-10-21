#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int countLonelyNumbers(const vector<int>& arr) {
    unordered_map<int, int> count;

    // Đếm số lần xuất hiện của mỗi số trong dãy
    for (int num : arr) {
        count[num]++;
    }

    int lonelyCount = 0;
    // Đếm số lượng số xuất hiện duy nhất
    for (auto it : count) {
        if (it.second == 1) {
            lonelyCount++;
        }
    }

    return lonelyCount;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << countLonelyNumbers(arr) << endl;
    }

    return 0;
}