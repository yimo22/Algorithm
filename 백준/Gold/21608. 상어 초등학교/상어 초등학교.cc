#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <tuple>
#include <cmath>
using namespace std;

/* define */
#define ll long long
#define endl '\n'
constexpr int dir[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0},
};
/* var */
int N;
int board[20+1][20+1];

vector<int> favor[400+1];
vector<int> order;
bool isIn(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= N) return false;
    return true;
}
struct comp {
    bool operator()(const tuple<int,int,int,int> & a, const tuple<int,int,int,int> & b) {
        int a_like, a_blank, a_r, a_c;
        int b_like, b_blank, b_r, b_c;
        tie(a_like, a_blank, a_r, a_c) = a;
        tie(b_like, b_blank, b_r, b_c) = b;

        if (a_like == b_like) {
            if (a_blank == b_blank) {
                if (a_r == b_r) {
                    return a_c > b_c;
                }
                else return a_r > b_r;
            }
            else return a_blank < b_blank;
        }
        else return a_like < b_like;

    }
};
void Solve() {
    // 1. 비어있는 칸 중, 좋아하는 학생이 인접한 칸에 가장 많은 칸
    // 2. 여러개일경우, 빈칸이 많은 칸으로
    // 3. 여러개일경우, 행 작을수록 / 열 작을수록

    for (int cur : order) {


        // 비어있는 칸 중 탐색
        // {좋아하는 학생의 수, 주변 빈칸, r, c}
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, comp> pq;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                // 빈칸 체크
                if (board[i][j]) continue; 

                // 주변의 좋아하는 사람수 + 빈칸수 체크
                int curLike = 0;
                int curBlank = 0;
                for (int d = 0; d < 4; d++) {
                    int nx = i + dir[d][0];
                    int ny = j + dir[d][1];

                    if (!isIn(nx, ny)) continue;

                    int person = board[nx][ny];

                    if (person == 0) curBlank++;
                    else {
                        // 좋아하는 사람인지 chk
                        for (int k : favor[cur]) {
                            if (k == person) curLike++;
                        }
                    }
                }
                pq.push({ curLike, curBlank, i, j });
            }
        }

        // 배치
        int cx, cy, clike, cblank;
        tie(clike, cblank, cx, cy) = pq.top();
        board[cx][cy] = cur;
    }

    // 검사
    int answer = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int cur = board[i][j];

            // 주변의 좋아하는 학생수 검사
            int _cnt = 0;
            for (int d = 0; d < 4; d++) {
                int nx = i + dir[d][0];
                int ny = j + dir[d][1];

                if (!isIn(nx, ny)) continue;

                for (int k : favor[cur]) {
                    if (k == board[nx][ny]) _cnt++;
                }
            }
            if (_cnt != 0) answer += pow(10, _cnt - 1);
        }
    }
    cout << answer;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    int n, a, b, c, d;
    for (int i = 0; i < N * N; i++) {
        cin >> n >> a >> b >> c >> d;
        favor[n].push_back(a);
        favor[n].push_back(b);
        favor[n].push_back(c);
        favor[n].push_back(d);
        order.push_back(n);
    }
}
int main() {
    init();
    Solve();
    return 0;
}