#include <bits/stdc++.h>
using namespace std;

string addLargeNumbers(string num1, string num2) {
    string result = "";
    int carry = 0;

    // Ensure num1 is the longer string
    if (num1.length() < num2.length()) {
        swap(num1, num2);
    }
    
    int len1 = num1.length();
    int len2 = num2.length();

    // Perform addition from the end of each string
    for (int i = len1 - 1; i >= 0; i--) {
        int digit1 = num1[i] - '0';
        int digit2 = i >= len1 - len2 ? num2[i - (len1 - len2)] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result = char(sum % 10 + '0') + result;
    }

    // If there's a carry left, add it to the result
    if (carry > 0) {
        result = char(carry + '0') + result;
    }

    return result;
}

string multiply(string num1, string num2) {
    int len1 = num1.size();
    int len2 = num2.size();
    vector<int> result(len1 + len2, 0);

    // Multiply each digit
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int product = (num1[i] - '0') * (num2[j] - '0');
            int sum = product + result[i + j + 1];
            result[i + j] += sum / 10;
            result[i + j + 1] = sum % 10;
        }
    }

    // Convert vector to string, skipping leading zeros
    string resultStr;
    for (int digit : result) {
        if (!(resultStr.empty() && digit == 0)) {
            resultStr += to_string(digit);
        }
    }

    return resultStr.empty() ? "0" : resultStr;
}

string trim(const string &str) {
    size_t start = str.find_first_not_of(' ');
    size_t end = str.find_last_not_of(' ');
    return (start == string::npos) ? "" : str.substr(start, end - start + 1);
}

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline after reading t

    while (t--) {
        string s;
        getline(cin, s);

        if (s.empty()) continue;  // Skip any empty lines

        string num1, num2;
        size_t found_plus = s.find('+');
        size_t found_multiply = s.find('*');

        // Check which operator exists and extract numbers accordingly
        if (found_plus != string::npos) {
            num1 = trim(s.substr(0, found_plus));
            num2 = trim(s.substr(found_plus + 1));

            if (!num1.empty() && !num2.empty()) {
                cout << addLargeNumbers(num1, num2) << "\n";
            } else {
                cerr << "Error: Invalid addition input '" << s << "'" << endl;
            }
        } else if (found_multiply != string::npos) {
            num1 = trim(s.substr(0, found_multiply));
            num2 = trim(s.substr(found_multiply + 1));

            if (!num1.empty() && !num2.empty()) {
                cout << multiply(num1, num2) << "\n";
            } else {
                cerr << "Error: Invalid multiplication input '" << s << "'" << endl;
            }
        } else {
            cerr << "Error: No valid operator found in line '" << s << "'" << endl;
        }
    }

    return 0;
}