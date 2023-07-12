#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;

/* define */
#define ll long long
#define endl '\n'
constexpr int dir[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};
/* var */
int N, M;
int sx, sy;
int board[1000][1000];
void Solve() {
    queue<tuple<int, int, int>> q;
    vector<vector<int>> visited(N, vector<int>(M, -1));
    visited[sx][sy] = 0;
    q.push({ sx, sy, 0 });

    while (!q.empty()) {
        int x, y, cnt;
        tie(x, y, cnt) = q.front(); q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dir[d][0];
            int ny = y + dir[d][1];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if (visited[nx][ny] == -1 && board[nx][ny] > 0) {
                visited[nx][ny] = cnt + 1;
                q.push({ nx,ny, cnt + 1 });
            }
        }
    }


    // out
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 0) visited[i][j] = 0;

            cout << visited[i][j] << " ";
        }
        cout << endl;
    }


}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                sx = i;
                sy = j;
            }
        }
    }
}
int main() {
    init();
    Solve();
    return 0;
}