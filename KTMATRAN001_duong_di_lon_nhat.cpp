#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        int N, M;
        cin >> N >> M;
        vector<vector<int>> A(N, vector<int>(M));
        //Nhap ma tran A
        for(int i = 0; i < N; i++){
            for(int j=0; j < M ; j++){
                cin >> A[i][j];
            }
        }
        //Khoi tao ma tran dp
        vector<vector<int>> dp(N,vector<int>(M,0));
        //Sao chep dong dau tien tu A sang dp
        for(int j =0; j < M ; j++){
            dp[0][j] = A[0][j];
        }
        //Tinh toan dp
        for(int i = 1; i < N; i++){
            for(int j =0; j < M; j++){
                dp[i][j] = A[i][j]; //Bat dau voi gia tri hien tai cua A
                //Kiem tra va cong them gia tri tu cac o tren dong truoc do
                if(j > 0) dp[i][j] = max(dp[i][j], A[i][j] + dp[i-1][j-1]);
                dp[i][j] = max(dp[i][j], A[i][j] + dp[i-1][j]);
                if(j < M-1) dp[i][j] = max(dp[i][j], A[i][j] + dp[i-1][j+1]);
            }
        }
        //Tim gia tri lon nhat trong dong cuoi cung
        int max_value = 0;
        for (int j = 0; j < M ; j++){
            max_value = max(max_value, dp[N-1][j]);
        }
        cout << max_value << endl;
    }
    return 0;
}
