#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Hàm cộng hai chuỗi số lớn
string addLargeNumbers(string a, string b) {
    // Đảm bảo chuỗi a luôn dài hơn hoặc bằng chuỗi b
    if (a.length() < b.length()) {
        swap(a, b);
    }
    
    // Đảo ngược chuỗi để dễ dàng cộng từ phải sang trái
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    string result = "";
    int carry = 0;
    
    // Cộng từng chữ số
    for (size_t i = 0; i < a.length(); ++i) {
        int digitA = a[i] - '0';  // Lấy chữ số từ chuỗi a
        int digitB = (i < b.length()) ? (b[i] - '0') : 0;  // Nếu chuỗi b còn chữ số thì lấy, ngược lại là 0
        int sum = digitA + digitB + carry;
        result += (sum % 10) + '0';  // Ghi chữ số hàng đơn vị vào kết quả
        carry = sum / 10;  // Tính phần dư để nhớ sang chữ số tiếp theo
    }
    
    // Nếu còn dư sau cùng
    if (carry > 0) {
        result += carry + '0';
    }
    
    // Đảo ngược chuỗi kết quả lại
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    int t;
    cin >> t;  // Đọc số lượng test cases
    while (t--) {
        string a, b;
        cin >> a >> b;  // Đọc hai số lớn dưới dạng chuỗi
        cout << addLargeNumbers(a, b) << endl;  // Tính và in ra kết quả
    }
    return 0;
}