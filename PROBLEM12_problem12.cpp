#include <iostream>
#include <string>

using namespace std;

string addOneToBigInteger(string num) {
    int n = num.length();
    
    // Duyệt từ chữ số cuối cùng lên đầu
    for (int i = n - 1; i >= 0; --i) {
        if (num[i] == '9') {
            // Nếu chữ số là 9, biến nó thành 0
            num[i] = '0';
        } else {
            // Nếu không phải 9, tăng nó lên 1 và dừng
            num[i]++;
            return num;
        }
    }
    
    // Nếu tất cả các chữ số là 9 (ví dụ: 999 -> 1000)
    return '1' + num;
}

int main() {
    string bigInteger;
    cin >> bigInteger;
    
    // Tính tổng
    string result = addOneToBigInteger(bigInteger);
    
    // Xuất kết quả
    cout << result << endl;

    return 0;
}