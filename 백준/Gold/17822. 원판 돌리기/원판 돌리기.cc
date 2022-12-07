#include "bits/stdc++.h"

using namespace std;
int N, M, T;
const int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<deque<int>> board;
vector<tuple<int, int, int>> orders;

void printBoard() {
    cout << "-------------\n";
    for (deque<int> dq : board) {
        for (int w : dq) cout << w << " ";
        cout << endl;
    }
    cout << "-------------\n";
}
void rotate(int x, int d, int k) {
    // x의 배수인 원판을 d방향으로 k칸 만큼 회전
    for (int i = 0; i < board.size(); i++) {
        if ((i + 1) % x != 0) continue;

        for (int cnt = 0; cnt < k; cnt++) {
            if (d == 0) {
                // 시계 방향 회전 : back을 front로 옮김
                board[i].push_front(board[i].back());
                board[i].pop_back();
            } else if (d == 1) {
                // 반시계 방향 회전 : front를 back으로 옮김
                board[i].push_back(board[i].front());
                board[i].pop_front();
            }
        }
    }
}
bool dfs(int x, int y, int w, vector<vector<bool>>& visited) {
    // searching
    bool res = false;
    for (int d = 0; d < 4; d++) {
        int nx = x + dir[d][0];
        int ny = (y + M + dir[d][1]) % M;

        // boundary check
        if (nx < 0 || nx >= N) continue;
        if (board[nx][ny] == w && !visited[nx][ny]) {
            visited[nx][ny] = true;
            res = true;
            board[nx][ny] = 0;
            dfs(nx, ny, w, visited);
        }
    }
    return res;
}
bool erase() {
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    bool isFound = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] > 0 && !visited[i][j]) {
                visited[i][j] = true;
                if (dfs(i, j, board[i][j], visited)) {
                    board[i][j] = 0;
                    isFound = true;
                }
            }
        }
    }
    return isFound;
}
void addUp() {
    // get avg
    int sum = 0, cnt = 0;
    for (int i = 0; i < N; i++) {
        sum = accumulate(board[i].begin(), board[i].end(), sum);
        for (int j = 0; j < M; j++) {
            if (board[i][j] > 0) {
                cnt++;
            }
        }
    }
    double avg = (double)sum / cnt;

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == 0) continue;
            if (board[i][j] > avg)
                board[i][j]--;
            else if (board[i][j] < avg)
                board[i][j]++;
        }
    }
}
bool check() {
    // checking board
    // 인접한 것을 모두 지움
    // 없으면, 원판에 적힌 평균을 구하고, 평균보다 큰수에는 1을 빼고, 작은수는
    // 1을 더한다

    // 원판의 남아 있는 갯수 check
    for (deque<int> dq : board) {
        for (int w : dq) {
            if (w > 0) return true;
        }
    }
    return false;
}
int Solution() {
    // 원판 번호는 0부터 시작
    // orders의 xi 는 1부터 시작
    int answer = 0;
    for (auto cur : orders) {
        int x, d, k;
        tie(x, d, k) = cur;
        rotate(x, d, k);
        // printBoard();
        if (!erase()) addUp();
        // printBoard();
    }

    // answer out
    for (deque<int> dq : board) {
        answer = accumulate(dq.begin(), dq.end(), answer);
    }

    return answer;
}
int main() {
    cin >> N >> M >> T;
    int w;
    // init

    // start
    for (int i = 0; i < N; i++) {
        deque<int> dq;
        for (int j = 0; j < M; j++) {
            cin >> w;
            dq.push_back(w);
        }
        board.push_back(dq);
    }
    int x, d, k;
    for (int i = 0; i < T; i++) {
        cin >> x >> d >> k;
        orders.push_back(make_tuple(x, d, k));
    }
    cout << Solution();
    return 0;
}