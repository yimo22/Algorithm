#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

/* define */
#define ll long long
#define endl '\n'
constexpr int dir[4][2] = {
    {0, 1},     // E
    {1, 0},     // S
    {0, -1},    // W
    {-1, 0}     // N
};
/* var */
int N;
int board[500][500];
int dp[500][500];
int visited[500][500];
int recur(int x, int y) {
    if (dp[x][y]) return dp[x][y];

    int ans = 0;
    for (int d = 0; d < 4; d++) {
        int nx = x + dir[d][0];
        int ny = y + dir[d][1];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if (board[nx][ny] > board[x][y]) {
            ans = max(ans, recur(nx, ny));
        }
    }
    return dp[x][y] = ans + 1;
}
void Solve() {
    // 최대한 많은 칸을 이동
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cnt = max(cnt, recur(i, j));
        }
    }
    cout << cnt;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> board[i][j];
}
int main() {
    init();
    Solve();
    return 0;
}