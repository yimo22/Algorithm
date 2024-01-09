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
constexpr int dir[8][2] = {
    {1, 2},
    {2, 1},
    {2, -1},
    {1, -2},
    {-1, -2},
    {-2, -1},
    {-2, 1},
    {-1, 2}
};
/* var */
int visited[500][500];
int N, M;
int X, Y;
vector<pair<int, int>> v;

bool isIn(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= N) return false;
    return true;
}
void Solve() {
    queue<tuple<int,int,int>> q; // x, y, 횟수
    q.push({ X, Y, 0 });
    visited[X][Y] = -1;

    while (!q.empty()) {
        int cx, cy, cn;
        tie(cx, cy, cn) = q.front(); q.pop();

        for (int d = 0; d < 8; d++) {
            int nx = cx + dir[d][0];
            int ny = cy + dir[d][1];

            if (!isIn(nx, ny)) continue;
            if (visited[nx][ny]) continue;

            visited[nx][ny] = cn + 1;
            q.push({ nx,ny, cn + 1 });
        }
    }

    for (pair<int, int>& p : v) {
        cout << visited[p.first][p.second] << ' ';
    }
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    cin >> X >> Y;
    X--; Y--;
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        a--; b--;
        v.push_back({ a,b });
    }
}
int main() {
    init();
    Solve();
    return 0;
}