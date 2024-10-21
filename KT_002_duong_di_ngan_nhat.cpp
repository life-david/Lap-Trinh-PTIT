#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX = 105;
const int INF = INT_MAX;

int dp[MAX][MAX]; // Lưu trữ giá trị đường đi ngắn nhất đến từng ô

int main() {
    int t;
    cin >> t; // Số lượng test case
    while (t--) {
        int m, n;
        cin >> m >> n; // Số hàng và số cột của bảng
        
        vector<vector<int>> A(m + 1, vector<int>(n + 1)); // Bảng A với m hàng, n cột

        // Nhập dữ liệu cho bảng A
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> A[i][j];
            }
        }

        // Nhập vị trí ô xuất phát
        int x, y;
        cin >> x >> y;

        // Khởi tạo mảng dp với giá trị lớn vô cùng (INF)
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = INF;
            }
        }

        // Đặt giá trị cho ô xuất phát
        dp[x][y] = A[x][y];

        // Duyệt qua các cột từ cột y đến cột n
        for (int j = y; j < n; ++j) {
            for (int i = 1; i <= m; ++i) {
                if (dp[i][j] != INF) {
                    // Di chuyển sang ô bên phải
                    dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + A[i][j + 1]);
                    
                    // Di chuyển sang ô chéo trên bên phải
                    if (i > 1) {
                        dp[i - 1][j + 1] = min(dp[i - 1][j + 1], dp[i][j] + A[i - 1][j + 1]);
                    }

                    // Di chuyển sang ô chéo dưới bên phải
                    if (i < m) {
                        dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + A[i + 1][j + 1]);
                    }
                }
            }
        }

        // Tìm giá trị nhỏ nhất ở cột cuối cùng (cột n)
        int result = INF;
        for (int i = 1; i <= m; ++i) {
            result = min(result, dp[i][n]);
        }

        // In ra kết quả của testcase hiện tại
        cout << result << endl;
    }
    return 0;
}