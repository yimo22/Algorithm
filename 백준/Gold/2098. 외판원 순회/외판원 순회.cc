#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* define*/
#define endl '\n'
#define INF 987654321
/* var*/
int N;
int dp[1 << 16][16];
int w[16][16];
int dfs(int visited, int v) {
	if (visited == ((1 << N) - 1)) {
		if (w[v][0] != 0) {
			return dp[visited][v] = w[v][0];
		}
		else {
			return dp[visited][v] = INF;
		}
	}

	/* pruning*/
	if (dp[visited][v] != 0) return dp[visited][v];

	dp[visited][v] = INF;
	for (int i = 0; i < N; i++) {
		if (visited & (1 << i)) continue;
		if (w[v][i] == 0) continue;

		dp[visited][v] = min(dp[visited][v], dfs(visited | (1 << i), i) + w[v][i]);
	}
	
	return dp[visited][v];
}
void Solve() {
	/* 시작 노드는 0번 노드로 고정*/
	// init
	dfs(1, 0);
	cout << dp[1][0];
}
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> w[i][j];
		}
	}
}
int main() {
	init();
	Solve();
	return 0;
}