#include <bits/stdc++.h>
using namespace std;

// Hàm cộng hai số lớn
string sumBig(string a, string b) {
    if (a.length() > b.length()) swap(a, b);
    string result = "";
    int n1 = a.length(), n2 = b.length();
    int diff = n2 - n1;
    int carry = 0;

    // Cộng từng chữ số từ cuối lên đầu
    for (int i = n1 - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i + diff] - '0') + carry;
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    // Cộng phần còn lại của chuỗi dài hơn
    for (int i = diff - 1; i >= 0; i--) {
        int sum = (b[i] - '0') + carry;
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    // Thêm chữ số dư nếu có
    if (carry) result.push_back(carry + '0');

    reverse(result.begin(), result.end());
    return result;
}

// Hàm tính phần bù 10 của một chuỗi số
string complement10(string v) {
    string complement = "";
    for (int i = 0; i < v.size(); i++) {
        complement += '9' - v[i] + '0'; // Phần bù 9
    }
    return sumBig(complement, "1"); // Thêm 1 để tạo phần bù 10
}

// Hàm trừ hai số lớn
string subtract(string a, string b) {
    // Đảm bảo số lớn hơn đứng trước
    if (a.length() < b.length() || (a.length() == b.length() && a < b)) {
        swap(a, b);
    }

    // Bổ sung các chữ số 0 vào đầu chuỗi b
    while (b.length() < a.length()) {
        b = "0" + b;
    }

    // Tính hiệu bằng cách sử dụng phần bù 10
    string c = sumBig(a, complement10(b));
    if (c.length() > a.length()) {
        c.erase(c.begin()); // Xóa chữ số dư nếu có
    }

    // Loại bỏ các chữ số 0 thừa ở đầu
    while (c[0] == '0' && c.length() > 1) {
        c.erase(c.begin());
    }

    return c;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        cout << subtract(str1, str2) << endl;
    }
    return 0;
}
