#include <iostream>
#include <vector>

using namespace std;

vector<int> factorial(int n) {
    vector<int> result(1, 1);
    for (int i = 2; i <= n; i++) {
        int carry = 0;
        for (int j = 0; j < result.size(); j++) {
            int product = result[j] * i + carry;
            result[j] = product % 10;
            carry = product / 10;
        }
        while (carry) {
            result.push_back(carry % 10);
            carry /= 10;
        }
    }
    return result;
}

vector<int> powerOfTwo(int n) {
    vector<int> result(1, 1);
    for (int i = 0; i < n; i++) {
        int carry = 0;
        for (int j = 0; j < result.size(); j++) {
            int product = result[j] * 2 + carry;
            result[j] = product % 10;
            carry = product / 10;
        }
        while (carry) {
            result.push_back(carry % 10);
            carry /= 10;
        }
    }
    return result;
}

vector<int> multiplyLargeNumbers(const vector<int>& a, const vector<int>& b) {
    vector<int> result(a.size() + b.size(), 0);
    for (int i = 0; i < a.size(); i++) {
        int carry = 0;
        for (int j = 0; j < b.size(); j++) {
            int product = a[i] * b[j] + result[i + j] + carry;
            result[i + j] = product % 10;
            carry = product / 10;
        }
        for (int j = i + b.size(); carry > 0; j++) {
            result[j] += carry;
            carry = result[j] / 10;
            result[j] %= 10;
        }
    }
    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }
    return result;
}

void printLargeNumber(const vector<int>& number) {
    for (int i = number.size() - 1; i >= 0; i--) {
        cout << number[i];
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> fact = factorial(n);
        vector<int> pow2 = powerOfTwo(n);
        vector<int> result = multiplyLargeNumbers(pow2, fact);
        printLargeNumber(result);
    }
    return 0;
}