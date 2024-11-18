#include <cstdio>
#include <vector>
#include <deque>
#include <cstring> // Thêm thư viện này để dùng memset và strlen
#include <algorithm>
using namespace std;

const int MAX = (int) 7e5;
bool p[MAX + 1];
int P[50000], n, k;
char s[300000], res[300000];

void eratos() {
    memset(p, -1, sizeof p); 
    p[0] = p[1] = 0; // 0 và 1 không phải số nguyên tố
    for (int i = 2; i * i <= MAX; ++i)
        if (p[i])
            for (int j = i + i; j <= MAX; j += i) 
                p[j] = 0; // Đánh dấu các bội của i là không nguyên tố
    for (int cnt = 0, i = 0; i <= MAX && cnt < 50000; ++i)
        if (p[i]) 
            P[cnt++] = i; // Lưu các số nguyên tố vào mảng P
}

void create() {
    char *t = s;
    for (int i = 0; i < n; ++i) {
        sprintf(t, "%d%n", P[i], &k); // Ghi số nguyên tố vào chuỗi `s`
        t += k;
    }
}

void solve() {
    deque<int> q;
    int b = 0, e = k, l = strlen(s), cnt = 0;
    for (int i = 0; i < l; ++i) {
        while (!q.empty() && s[q.back()] < s[i]) 
            q.pop_back(); // Loại bỏ các phần tử nhỏ hơn s[i] ở cuối hàng đợi
        q.push_back(i);
        if (i >= e - 1) { // Kiểm tra khoảng k phần tử
            while (!q.empty() && q.front() < b) 
                q.pop_front(); // Loại bỏ phần tử không nằm trong phạm vi [b, e)
            res[cnt++] = s[q.front()]; // Lấy phần tử lớn nhất trong phạm vi
            b++;
            e = b + k - 1;
        }
    }
    res[cnt] = '\0'; // Kết thúc chuỗi kết quả
    puts(res);
}

int main() {
    eratos(); // Khởi tạo danh sách số nguyên tố
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        create();
        solve();
    }
    return 0;
}
