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
int N, M;
int board[1000][1000];
int dp[1000 + 1][1000 + 1];
int recur(int x, int y) {
	if (x >= N || y >= M) return 0;
	if (dp[x][y] != -1) return dp[x][y];

	recur(x + 1, y);
	recur(x, y + 1);
	if (board[x][y]) {
		return dp[x][y] = min({
			recur(x + 1, y),
			recur(x, y + 1),
			recur(x + 1, y + 1)
			}) + 1;
	}
	else {
		return dp[x][y] = 0;
	}
}
void init() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (1) {
		cin >> N >> M;
		if (N == 0 && 0 == M) break;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> board[i][j];
				dp[i][j] = -1;
			}
		}
		recur(0, 0);
		int ans = 0;
		for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) ans = max(ans, dp[i][j]);
		cout << ans << endl;
	}
}
int main() {
	init();
	return 0;
}