#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

/* define */
#define ll long long
#define endl '\n'
#define BOTTOM_X 3
#define BOTTOM_Y 1

constexpr int DICE_POSITION[6][2] = {{1, 1},
                                     {0, 1},
                                     {1, 2},
                                     {1, 0},
                                     {2, 1},
                                     {3, 1}};

constexpr int dir[4][2] = {{0,  1},
                           {1,  0},
                           {0,  -1},
                           {-1, 0}};

/* var */
int N, M, K;
int board[20 + 1][20 + 1];
int adjCnt[20 + 1][20 + 1];
int dice[4][3] = {
        {0, 2, 0},
        {4, 1, 3},
        {0, 5, 0},
        {0, 6, 0}
};
vector<pair<int, int>> buffer; // 경로 저장용 buffer


void rotateRight() {
    int tmp = dice[1][2];
    for(int i=2;i>=0;i--){
        if(i == 0) {
            dice[1][i] = dice[3][1];
            break;
        }
        dice[1][i] = dice[1][i-1];
    }
    dice[3][1] = tmp;
}

void rotateLeft() {
    int tmp = dice[1][0];
    for(int i=0;i<=2;i++){
        if(i == 2){
            dice[1][i] = dice[3][1];
            break;
        }
        dice[1][i] = dice[1][i+1];
    }
    dice[3][1] = tmp;
}

void rotateUpper() {
    int tmp = dice[0][1];
    for(int i=0;i<3;i++){
        dice[i][1] = dice[i+1][1];
    }
    dice[3][1] = tmp;
}

void rotateDown() {
    int tmp = dice[3][1];
    for(int i=3;i>0;i--){
        dice[i][1] = dice[i-1][1];
    }
    dice[0][1] = tmp;
}

bool isIn(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= M) return false;
    return true;
}

/* (x, y) 에 있을때 다음 방향 결정 */
int makeDir(int d, int bottom, int x, int y) {
    if (bottom > board[x][y]) return (d + 1) % 4;
    else if (bottom < board[x][y]) return (d + 3) % 4;
    else return d;
}

int makePoint(int x, int y) {
    return adjCnt[x][y] * board[x][y];
}

void _init() {
    // 전처리 1. 각 칸에서의 인접한 숫자 갯수
    vector<vector<int>> visited(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j]) {
                buffer.clear();

                queue<pair<int, int>> q;
                int _cnt = 0;
                visited[i][j] = 1;
                buffer.push_back({i, j});
                q.push({i, j});
                _cnt++;

                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();

                    for (int d = 0; d < 4; d++) {
                        int nx = cur.first + dir[d][0];
                        int ny = cur.second + dir[d][1];

                        if (!isIn(nx, ny)) continue;
                        if (visited[nx][ny]) continue;
                        if (board[cur.first][cur.second] != board[nx][ny]) continue;

                        visited[nx][ny] = 1;
                        buffer.push_back({nx, ny});
                        q.push({nx, ny});
                        _cnt++;
                    }
                }

                for (auto c: buffer) {
                    adjCnt[c.first][c.second] = _cnt;
                }
            }
        }
    }
}

void Solve() {
    _init();

    int cd = 0;
    int cx = 0;
    int cy = 0;

    ll ans = 0;
    for (int rep = 0; rep < K; rep++) {
        // 이동방향에 칸이 없으면 이동방향 반대
        if (!isIn(cx + dir[cd][0], cy + dir[cd][1])) cd = (cd + 2) % 4;
        cx += dir[cd][0];
        cy += dir[cd][1];

        /* Rotating */
        switch(cd){
            case 0 : rotateRight(); break;
            case 1 : rotateDown(); break;
            case 2 : rotateLeft(); break;
            case 3 : rotateUpper(); break;
        }
        ans += makePoint(cx, cy );

        cd = makeDir(cd, dice[BOTTOM_X][BOTTOM_Y], cx, cy);
    }

    cout << ans;
}

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifndef BOJ
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
}

int main() {
    init();
    Solve();
    return 0;
}