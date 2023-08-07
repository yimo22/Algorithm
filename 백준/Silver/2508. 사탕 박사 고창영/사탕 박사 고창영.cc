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
int R, C;
char board[400][400];
void Solve() {
    while (T-- > 0) {
        cin >> R >> C;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> board[i][j];
            }
        }

        int count = 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j + 3 <= C; j++) {
                if (board[i][j] == '>' && board[i][j + 1] == 'o' && board[i][j+2] == '<') count++;
            }
        }

        for (int i = 0; i < C; i++) {
            for (int j = 0; j + 3 <= R; j++) {
                if (board[j][i] == 'v' && board[j+1][i] == 'o' && board[j+2][i] == '^') count++;
            }
        }
        cout << count << endl;
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