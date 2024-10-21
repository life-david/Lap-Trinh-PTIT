#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX_N = 100000;  // Giới hạn của N

vector<int> max_prime_factor(MAX_N + 1, 0); // Lưu ước số nguyên tố lớn nhất của mỗi số

// Sàng Eratosthenes để tìm ước số nguyên tố lớn nhất của mỗi số
void sieve() {
    for (int i = 2; i <= MAX_N; i++) {
        if (max_prime_factor[i] == 0) { // i là số nguyên tố
            for (int j = i; j <= MAX_N; j += i) {
                max_prime_factor[j] = i; // i là ước số nguyên tố lớn nhất của j
            }
        }
    }
}

// Hàm kiểm tra và tìm số đặc biệt lớn nhất trong khoảng từ 1 đến N
int find_special_number(int N) {
    int special_number = -1;
    
    // Lặp qua tất cả các số từ 1 đến N
    for (int i = N; i >= 1; i--) {
        int largest_prime_factor = max_prime_factor[i];
        if (largest_prime_factor > sqrt(i)) {
            special_number = i;
            break;
        }
    }
    
    return special_number;
}

int main() {
    sieve(); // Khởi tạo sàng Eratosthenes
    
    int t;
    cin >> t; // Số lượng test case
    
    while (t--) {
        int N;
        cin >> N; // Đọc giá trị N
        
        // Tìm số đặc biệt lớn nhất trong khoảng từ 1 đến N
        cout << find_special_number(N) << endl;
    }
    
    return 0;
}