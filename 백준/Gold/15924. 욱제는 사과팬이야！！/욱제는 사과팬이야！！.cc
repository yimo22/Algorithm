#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

/* define */
#define ll long long
#define endl '\n'
#define MODULO 1000000009
/* var */
int N, M;
int dp[3000][3000];
char board[3000][3000];
int recur(int row, int col) {
    if (row < 0 || row >= N || col < 0 || col >= M) return 0;
    char c = board[row][col];
    if (c == 'X') return 1;
    int& w = dp[row][col];
    if (w != -1) return w;


    if (c == 'E') return w = recur(row, col + 1);
    else if (c == 'S') return w = recur(row + 1, col);
    else return w = (recur(row + 1, col) + recur(row, col + 1)) % MODULO;
}
void Solve() {
    memset(dp, -1, sizeof dp);
    dp[N - 1][M - 1] = 1;
    recur(0, 0);

    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            sum = (sum + recur(i, j)) % MODULO;
        }
    }
    cout << sum;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
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