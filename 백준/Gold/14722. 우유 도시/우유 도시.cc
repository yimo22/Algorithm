#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

/* define */
#define ll long long
#define endl '\n'
constexpr int dir[2][2] = {
    {0, 1}, {1, 0}
};
/* var */
int N;
// 0(딸기), 1(초코), 2(바나나)
int board[1000 + 1][1000 + 1];
int dp[1000 + 1][1000 + 1][3];

bool isIn(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= N) return false;
    return true;
}
int recur(int x, int y, int state) {
    int& w = dp[x][y][state];
    if (w != -1) return w;
    if (x == N - 1 && y == N - 1) {
        return board[x][y] == state ? 2 : 1;
    }


    w = 0;
    for (int d = 0; d < 2; d++) {
        int nx = x + dir[d][0];
        int ny = y + dir[d][1];

        if (!isIn(nx, ny)) continue;

        // 마시는 경우
        if(board[x][y] == state)
            w = max(w, recur(nx, ny, (state + 1) % 3) + 1);

        // 안마시는 경우
        w = max(w, recur(nx, ny, state));
    }
    return w;
}
void Solve() {
    memset(dp, -1, sizeof dp);
    cout << recur(0, 0, 0) - 1;

}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
}
int main() {
    init();
    Solve();
    return 0;
}