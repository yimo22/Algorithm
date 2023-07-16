#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;

/* define */
#define ll long long
#define endl '\n'
constexpr int dir[4][2] = {
    {0, 1}, // E
    {1, 0}, // S
    {0, -1}, // W
    {-1, 0} // N
};
/* var */
int N, M;
int board[500][500];
int dp[500][500];
int recur(int x, int y, int w) {
    if (dp[x][y] != -1) return dp[x][y];
    if (x == N - 1 && y == M - 1) return 1;
    int& ans = dp[x][y];
    ans = 0;
    for (int d = 0; d < 4; d++) {
        int nx = x + dir[d][0];
        int ny = y + dir[d][1];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

        if (board[nx][ny] < w) {
            ans += recur(nx, ny, board[nx][ny]);
        }
    }
    return dp[x][y] = ans;
}
void Solve() {
    memset(dp, -1, sizeof dp);
    cout << recur(0, 0, board[0][0]);
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> board[i][j];
}
int main() {
    init();
    Solve();
    return 0;
}