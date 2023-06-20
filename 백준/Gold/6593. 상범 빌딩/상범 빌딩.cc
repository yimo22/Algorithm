#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

/* define */
#define ll long long
#define endl '\n'

/* var */
int L=0, R=0, C=0;
char board[30][30][30];
constexpr int dir[6][3] = {
    {1, 0, 0},
    {-1, 0, 0},
    {0, 1, 0},
    {0, -1, 0},
    {0, 0, 1},
    {0, 0, -1}
};
int sz, sx, sy;
int ez, ex, ey;
bool isIn(int z, int x, int y) {
    if (z < 0 || z >= L || x < 0 || x >= R || y < 0 || y >= C) return false;
    else return true;
}
int Solve() {
    int visited[30][30][30];
    memset(visited, 0, sizeof visited);

    queue<tuple<int, int, int, int>> q; // z, x, y, cnt
    q.push({ sz, sx, sy, 0 });
    visited[sz][sx][sy] = 1;

    while (!q.empty()) {
        int z, x, y, cnt;
        tie(z, x, y, cnt) = q.front(); q.pop();

        if (z == ez && x == ex && y == ey) return cnt;

        for (int d = 0; d < 6; d++) {
            int nz = z + dir[d][0];
            int nx = x + dir[d][1];
            int ny = y + dir[d][2];

            if (!isIn(nz, nx, ny)) continue;
            if (visited[nz][nx][ny]) continue;
            if (board[nz][nx][ny] == '.') {
                visited[nz][nx][ny] = 1;
                q.push({ nz,nx,ny, cnt + 1 });
            }

        }
    }
    return -1;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    while (1) {
        cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0) break;

        string s;
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                cin >> s;
                for (int k = 0; k < C; k++) {
                    board[i][j][k] = s[k];
                    if (s[k] == 'S') {
                        sz = i;
                        sx = j;
                        sy = k;
                        board[i][j][k] = '.';
                    }
                    else if (s[k] == 'E') {
                        ez = i;
                        ex = j;
                        ey = k;
                        board[i][j][k] = '.';
                    }
                }
            }
        }
        int res = Solve();
        if (res >= 0) {
            printf("Escaped in %d minute(s).\n", res);
        }
        else printf("Trapped!\n");
    }
}
int main() {
    init();
    return 0;
}