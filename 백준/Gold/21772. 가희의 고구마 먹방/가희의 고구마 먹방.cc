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
typedef struct Node {
    int x, y, cnt, time;
    Node(int X, int Y, int C, int T) : x(X), y(Y), cnt(C), time(T) {}
}Node;
/* var */
int R, C, T;
int answer;
pair<int, int> start;
char board[100+1][100+1];
bool isIn(int x, int y) {
    if (x < 0 || x >= R || y < 0 || y >= C) return false;
    return true;
}
void recur(int x, int y, int time, int cnt) {
    if (time > T) return;
    answer = max(answer, cnt);

    for (int d = 0; d < 4; d++) {
        int nx = x + dir[d][0];
        int ny = y + dir[d][1];
        if (!isIn(nx, ny)) continue;
        if (board[nx][ny] == '#') continue;

        if (board[nx][ny] == 'S') {
            board[nx][ny] = '.';
            recur(nx, ny, time + 1, cnt + 1);
            board[nx][ny] = 'S';
        }
        else recur(nx, ny, time + 1, cnt);
    }
    
}
void Solve() {
    recur(start.first, start.second, 0, 0);
    cout << answer;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C >> T;
    string s;
    for (int i = 0; i < R; i++) {
        cin >> s;
        for (int j = 0; j < C; j++) {
            board[i][j] = s[j];
            if (board[i][j] == 'G') {
                start.first = i;
                start.second = j;
                board[i][j] = '.';
            }
        }
    }
}
int main() {
    init();
    Solve();
    return 0;
}