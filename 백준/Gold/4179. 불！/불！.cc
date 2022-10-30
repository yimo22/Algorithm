#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
#define MAX 1'000
int R, C;
vector<string> map;
vector<vector<int>> fireMap(MAX, vector<int>(MAX, -1));
pair<int, int> start;
vector<pair<int, int>> fireStart;
const int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool check(int x, int y) {
    if (x < 0 || x >= R || y < 0 || y >= C)
        return true;
    else
        return false;
}
void make_map() {
    if (fireStart.empty()) return;
    // fire spread
    queue<tuple<int, int, int>> q;
    for (auto w : fireStart) {
        q.push(make_tuple(w.first, w.second, 0));
        fireMap[w.first][w.second] = 0;
    }

    while (!q.empty()) {
        int x, y, time;
        tie(x, y, time) = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dir[d][0];
            int ny = y + dir[d][1];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;

            if (fireMap[nx][ny] == -1 && map[nx][ny] != '#') {
                fireMap[nx][ny] = time + 1;
                q.push(make_tuple(nx, ny, time + 1));
            }
        }
    }
}
int Solve() {
    // 탐색
    queue<pair<pair<int, int>, int>> q;  // 위치, time
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    // init
    make_map();

    q.push(make_pair(start, 0));
    visited[start.first][start.second] = true;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        // forwarding
        for (int d = 0; d < 4; d++) {
            int nx = cur.first.first + dir[d][0];
            int ny = cur.first.second + dir[d][1];
            int nt = cur.second + 1;
            // boundary check
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) return cur.second + 1;

            // 불이 없거나, 미로의 벽이 아닌 경우 진행 가능
            if ((nt < fireMap[nx][ny] || fireMap[nx][ny] == -1) &&
                map[nx][ny] != '#' && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push(make_pair(make_pair(nx, ny), nt));
            }
        }
    }

    return -1;
}
int main() {
    cin >> R >> C;
    string s;
    for (int i = 0; i < R; i++) {
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == 'J') start = make_pair(i, j);
            if (s[j] == 'F') fireStart.push_back({i, j});
        }
        map.push_back(s);
    }

    int res = Solve();
    if (res > 0)
        cout << res << "\n";
    else
        cout << "IMPOSSIBLE\n";

    return 0;
}