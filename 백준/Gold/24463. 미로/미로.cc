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
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};
/* var */
int N, M;
char board[2001 + 123][2001 + 123];
vector<pair<int, int>> dest;

bool isIn(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= M) return false;
    return true;
}
void Solve() {
    // dest[0] -> dest[1] 로의 최단거리
    // backtrace
    queue<tuple<int, int, int>> q;
    vector<vector<int>> visited(N, vector<int>(M, -1));
    q.push({ dest[0].first, dest[0].second, 0 });

    while (!q.empty()) {
        int x, y, cnt;
        tie(x, y, cnt) = q.front(); q.pop();
        if (x == dest[1].first && y == dest[1].second) break;

        for (int d = 0; d < 4; d++) {
            int nx = x + dir[d][0];
            int ny = y + dir[d][1];

            if (!isIn(nx, ny))continue;
            if (board[nx][ny] == '+') continue;

            if (visited[nx][ny] == -1) {
                visited[nx][ny] = d;
                q.push({ nx, ny, cnt + 1 });
            }

        }
    }
    
    vector<vector<char>> answer(N, vector<char>(M, '+'));
    // back tracing
    int x = dest[1].first;
    int y = dest[1].second;


    while ( isIn(x, y) && visited[x][y] != -1 && !(x == dest[0].first && y == dest[0].second)) {
        answer[x][y] = '#';
        int nd = (visited[x][y] + 2) % 4;
        x += dir[nd][0];
        y += dir[nd][1];
    }
    if(x == dest[0].first && y == dest[0].second)
        answer[x][y] = '#';

    // filling
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == '.') {
                if (answer[i][j] == '#') answer[i][j] = '.';
                else answer[i][j] = '@';
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << answer[i][j];
        }
        cout << endl;
    }
    
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < M; j++) {
            board[i][j] = s[j];

            if (i == 0 || i == N - 1 || j == 0 || j == M - 1) {
                if (board[i][j] == '.') dest.push_back({ i, j });
            }
        }
    }

}
int main() {
    init();
    Solve();
    return 0;
}