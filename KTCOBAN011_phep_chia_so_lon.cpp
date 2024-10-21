#include <iostream>
#include <string>
using namespace std;

// Hàm trừ số nguyên lớn lưu dưới dạng chuỗi
string subtractStrings(string a, string b) {
    // Giả sử a >= b
    int carry = 0;
    string result = "";
    int aLen = a.size();
    int bLen = b.size();
    
    for (int i = 0; i < aLen; i++) {
        int ai = a[aLen - 1 - i] - '0';
        int bi = (i < bLen) ? b[bLen - 1 - i] - '0' : 0;
        int digit = ai - bi - carry;
        if (digit < 0) {
            digit += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        result = char(digit + '0') + result;
    }
    
    // Loại bỏ số 0 thừa ở đầu
    while (result.size() > 1 && result[0] == '0') {
        result.erase(0, 1);
    }
    
    return result;
}

// Hàm chia chuỗi số lớn
pair<string, string> divideStrings(string a, string b) {
    string quotient = "";
    string remainder = "0";
    
    for (int i = 0; i < a.size(); i++) {
        remainder += a[i];
        
        // Loại bỏ số 0 thừa ở đầu của remainder
        while (remainder.size() > 1 && remainder[0] == '0') {
            remainder.erase(0, 1);
        }
        
        // Tìm số lớn nhất q sao cho b * q <= remainder
        int q = 0;
        while (remainder.size() > b.size() || (remainder.size() == b.size() && remainder >= b)) {
            remainder = subtractStrings(remainder, b);
            q++;
        }
        
        quotient += (q + '0');
    }
    
    // Loại bỏ số 0 thừa ở đầu của quotient
    while (quotient.size() > 1 && quotient[0] == '0') {
        quotient.erase(0, 1);
    }
    
    return {quotient, remainder};
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string a, b;
        cin >> a >> b;
        
        pair<string, string> result = divideStrings(a, b);
        cout << result.first << " " << result.second << endl;
    }
    
    return 0;
}