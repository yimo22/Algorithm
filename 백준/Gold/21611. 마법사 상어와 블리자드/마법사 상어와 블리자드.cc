#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <deque>
#include <queue>
using namespace std;

/* define */
#define ll long long
#define endl '\n'
#define MAX 49
#define EXPLODE_CNT 4
constexpr int dir[4][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};
constexpr int dir2[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};

/* var */
int N, M;
int board[MAX+1][MAX+1];
int sr, sc;
int cnt[4];
vector<pair<int, int>> list;
deque<pair<int, int>> order; // 각 자리번호 마다의 위치

bool isIn(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= N) return false;
    return true;
}

void printMtrx() {
    vector<vector<int>> tmp(N, vector<int>(N, 0));
    vector<int> tmp2;
    for (pair<int, int>& p : order) {
        int& w = board[p.first][p.second];
        if (w == 0) continue;

        tmp2.push_back(w);
    }
    for (int i = 0; i < min(order.size(), tmp2.size()); i++) {
        tmp[order[i].first][order[i].second] = tmp2[i];
    }


    cout << " -- " << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << tmp[i][j] << " ";
        }
        cout << endl;
    }
    cout << cnt[1] << " " << cnt[2] << " " << cnt[3] << endl;
    cout << " -- " << endl;
}

void change() {
    // 재형성
    vector<int> tmp;
    int i, j;
    for (i = 0; i < order.size(); i++) {
        int & w1 = board[order[i].first][order[i].second];
        if (w1 == 0) continue;

        int diff = 1;
        for (j = i + 1; j < order.size(); j++) {
            int& w2 = board[order[j].first][order[j].second];
            if (w2 == 0) continue;
            if (w1 == w2) {
                diff++;
                continue;
            }
            break;
        }
        
        // i~j 까지 처리
        tmp.push_back(diff);
        tmp.push_back(w1);
        i = j - 1;
    }

    // board 만들기
    memset(board, 0, sizeof board);
    for (int i = 0; i < min(order.size(), tmp.size()); i++) {
        int& w = board[order[i].first][order[i].second];
        w = tmp[i];
    }
}
void explode() {
    // 연속하는 수 4개 지우기 (반복)
    
    bool isFound = false;
    int i, j, k;
    do {
        isFound = false;
        for (i = 0; i < order.size(); i++) {
            int& w1 = board[order[i].first][order[i].second];
            if (w1 == 0) continue;

            int diff = 1;
            for (j = i + 1; j < order.size(); j++) {
                int& w2 = board[order[j].first][order[j].second];
                if (w2 == 0) continue;

                if (w1 == w2) {
                    diff++;
                    continue;
                }
                else break;
            }

            if (diff >= EXPLODE_CNT) {
                isFound = true;
                for (k = i; k < j; k++) {
                    int& w3 = board[order[k].first][order[k].second];
                    if (w3 == 0) continue;
                    cnt[w3]++;
                    w3 = 0;
                }
            }
            i = j - 1;
        }
    } while (isFound);
}
void moveBall(int d, int s) {
    // board에 폭발하는 대상 지우기
    int x = N / 2;
    int y = N / 2;
    for (int rep = 0; rep < s; rep++) {
        int nx = x + dir[d][0];
        int ny = y + dir[d][1];

        if (isIn(nx, ny) && board[nx][ny]) {
            //cnt[board[nx][ny]]++;
            board[nx][ny] = 0;
        }

        x += dir[d][0];
        y += dir[d][1];
    }
}

void pre() {
    int x = 0;
    int y = 0;
    int d = 0;
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    
    for (int i = 0; i < N * N; i++) {
        visited[x][y] = true;
        order.push_front({ x, y });

        // 다음상태 체크
        int nx = x + dir2[d][0];
        int ny = y + dir2[d][1];

        // 범위밖 or 이미 방문
        if (!isIn(nx, ny) || visited[nx][ny]) d = (d + 1) % 4;

        // update
        x += dir2[d][0];
        y += dir2[d][1];
    }
    
    // 마지막 상어위치 제거
    order.pop_front();
}
void Solve() {
    pre();      // 사전작업

    for (pair<int, int>& _cur : list) {
        int cd = _cur.first;
        int cs = _cur.second;
        // 1. 칸 지우기 (구슬이동)
        moveBall(cd, cs);
        // 2. 구슬 폭발 (연속해서 폭발가능)
        // - 4개 이상 연속
        explode();
        // 3. 구슬변화하는 단계
        // - 
        change();

        //printMtrx();
    }
    int ans = 0;
    for (int i = 1; i <= 3; i++) {
        ans += i * cnt[i];
    }
    cout << ans;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    int d, s;
    for (int i = 0; i < M; i++) {
        cin >> d >> s;
        list.push_back({d-1, s});
    }
}
int main() {
    init();
    Solve();
    return 0;
}