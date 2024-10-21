#include <iostream>
#include <queue>
#include <set>
using namespace std;

// Các nước đi có thể của quân mã
int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

struct State {
    int x, y, steps;
};

int bfs(int n, int k, int startX, int startY) {
    // Tập hợp để lưu lại các vị trí đã đi qua
    set<pair<int, int>> visited;
    queue<State> q;

    // Đưa vị trí bắt đầu vào hàng đợi
    q.push({startX, startY, 0});
    visited.insert({startX, startY});

    // BFS để duyệt qua tất cả các bước có thể
    while (!q.empty()) {
        State current = q.front();
        q.pop();

        // Nếu đã đi đủ số bước k thì không cần duyệt tiếp từ vị trí này
        if (current.steps == k) continue;

        // Thử tất cả 8 nước đi của quân mã
        for (int i = 0; i < 8; i++) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            // Kiểm tra nếu nước đi hợp lệ (trong bàn cờ) và chưa được thăm
            if (newX >= 1 && newX <= n && newY >= 1 && newY <= n) {
                if (visited.find({newX, newY}) == visited.end()) {
                    visited.insert({newX, newY});
                    q.push({newX, newY, current.steps + 1});
                }
            }
        }
    }

    // Kích thước của tập hợp chính là số ô cờ mà quân mã có thể đi đến
    return visited.size();
}

int main() {
    int t;
    cin >> t; // Số lượng testcase

    while (t--) {
        int n, k, x, y;
        cin >> n >> k >> x >> y;

        // Gọi hàm BFS để tính số ô cờ mà quân mã có thể đi qua sau k bước
        cout << bfs(n, k, x, y) << endl;
    }

    return 0;
}