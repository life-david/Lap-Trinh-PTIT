#include <iostream>
#include <vector>
using namespace std;

int countSolutions = 0;

void solve(int n, int row, vector<int>& col, vector<int>& diag1, vector<int>& diag2) {
    if (row == n) {
        // Đã đặt thành công n quân hậu, tăng số giải pháp
        countSolutions++;
        return;
    }
    
    for (int c = 0; c < n; ++c) {
        // Kiểm tra xem có thể đặt quân hậu vào hàng row, cột c hay không
        if (col[c] || diag1[row - c + n - 1] || diag2[row + c]) continue;

        // Đặt quân hậu
        col[c] = diag1[row - c + n - 1] = diag2[row + c] = 1;
        
        // Thử đặt tiếp ở hàng tiếp theo
        solve(n, row + 1, col, diag1, diag2);
        
        // Quay lui: gỡ quân hậu ra và thử vị trí khác
        col[c] = diag1[row - c + n - 1] = diag2[row + c] = 0;
    }
}

int nQueens(int n) {
    countSolutions = 0;

    // col[i]: kiểm tra xem cột i có quân hậu nào không
    // diag1[i]: kiểm tra đường chéo từ trên trái xuống dưới phải (row - col)
    // diag2[i]: kiểm tra đường chéo từ trên phải xuống dưới trái (row + col)
    vector<int> col(n, 0), diag1(2 * n - 1, 0), diag2(2 * n - 1, 0);
    
    // Bắt đầu thử đặt quân hậu từ hàng 0
    solve(n, 0, col, diag1, diag2);
    
    return countSolutions;
}

int main() {
    int T;
    cin >> T;  // Nhập số lượng test case
    
    while (T--) {
        int n;
        cin >> n;  // Nhập kích thước bàn cờ

        cout << nQueens(n) << endl;
    }

    return 0;
}