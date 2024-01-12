#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

/* define */
#define ll long long
#define endl '\n'

/* var */
int T;
int N, D;
int board[500+1][500+1];
void rotate() {
    // 주대각 이동
    // 가운데열 이동
    // 부대각 이동
    // 가운데 행 이동

    vector<vector<int>> tmp(N, vector<int>(N, 0));
    // 1. 주대각 이동
    for (int i = 0; i < N; i++) {
        tmp[i][N/2] = board[i][i];
    }

    // 2. 가운데열 이동
    for (int i = 0; i < N; i++) {
        tmp[i][N - i - 1] = board[i][N/2];
    }

    // 3. 부대각 이동
    for (int i = 0; i < N; i++) {
        tmp[N / 2][N - 1 - i] = board[i][N - 1 - i];
    }

    // 4. 가운데행 이동
    for (int i = 0; i < N; i++) {
        tmp[N-1-i][N-1-i] = board[N / 2][N - 1 - i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tmp[i][j]) board[i][j] = tmp[i][j];
        }
    }
}
int cal(int degree) {
    if (degree < 0) degree = 360 + degree;
    return degree / 45;
}
void Solve() {
    while (T--) {
        cin >> N >> D;
        memset(board, 0, sizeof board);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> board[i][j];
            }
        }

        int rcnt = cal(D);
        while (rcnt-- > 0) {
            rotate();
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
}
int main() {
    init();
    Solve();
    return 0;
}