#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

/* define */
#define ll long long
#define endl '\n'
typedef struct Node {
    int x, y, cnt;
    Node(int X, int Y, int C) : x(X), y(Y), cnt(C) {}
}Node;
constexpr int dir[4][2] = {
    {1, 0}, {0, 1}, {-1, 0}, {0, -1}
};
/* var */
int N;
int board[50][50];
int visited[50][50];
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < N; j++) {
            board[i][j] = s[j] - '0';
        }
    }
    memset(visited, -1, sizeof visited);
}
void Solve() {
    queue<Node> q;
    q.push(Node(0, 0, 0));
    visited[0][0] = 0;
    while (!q.empty()) {
        Node cur = q.front(); q.pop();


        if (cur.x == N - 1 && cur.y == N - 1) continue;
        if (visited[cur.x][cur.y] != cur.cnt) continue;

        for (int d = 0; d < 4; d++) {
            int nx = cur.x + dir[d][0];
            int ny = cur.y + dir[d][1];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

            if (visited[nx][ny] == -1 || visited[nx][ny] > cur.cnt) {
                int ncnt = (board[nx][ny] == 0) ? cur.cnt + 1 : cur.cnt;
                visited[nx][ny] = ncnt;
                q.push(Node(nx, ny, ncnt));
            }
        }
    }

    cout << visited[N - 1][N - 1] << endl;
}
int main() {
    init();
    Solve();
    return 0;
}