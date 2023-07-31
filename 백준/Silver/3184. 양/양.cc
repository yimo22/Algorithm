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
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};
/* var */
char board[250][250];
bool visited[250][250];
bool isOut;
int R, C;
int wolf, sheep;
bool isIn(int x, int y) {
    if (x < 0 || x >= R || y < 0 || y >= C) return false;
    return true;
}

int recur(int x, int y) {
    if (board[x][y] == 'o') sheep++;
    else if (board[x][y] == 'v') wolf++;


    for (int d = 0; d < 4; d++) {
        int nx = x + dir[d][0];
        int ny = y + dir[d][1];

        if (!isIn(nx, ny)) {
            isOut = true;
            continue;
        }

        if (board[nx][ny] == '#' || visited[nx][ny]) continue;

        visited[nx][ny] = 1;
        recur(nx, ny);
    }
    return 0;
}
void Solve() {
    int ans_w = 0, ans_s = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] == '#') continue;
            if (!visited[i][j]) {
                isOut = false;
                sheep = 0;
                wolf = 0;
                visited[i][j] = 1;
                recur(i, j);

                if (isOut) continue;

                if (sheep > wolf) ans_s += sheep;
                else ans_w += wolf;
            }
          }
    }
    cout << ans_s << " " << ans_w;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < C; j++) {
            board[i][j] = s[j];
        }
    }
}
int main() {
    init();
    Solve();
    return 0;
}