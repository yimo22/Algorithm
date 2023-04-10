#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

/* define*/
#define endl '\n'
#define ll long long
#define MAX 15

/* var*/
ll dp[1'500'000+10];
int N;
int v[1'500'010][2];
int answer = 0;
/* 메모 사용*/
ll dfs3(int depth) {
	if (depth > N) return -987654321;
	if (depth == N) {
		return 0;
	}

	if (dp[depth] != -1) return dp[depth];

	return dp[depth] = max(dfs3(depth + 1), dfs3(depth + v[depth][0]) + v[depth][1]);
}

/* 재귀(완탐) */
int dfs2(int depth) {
	if (depth > N) return -987654321; // 불가한 경우
	if (depth == N) {
		return 0;
	}

	return max(dfs2(depth + 1), dfs2(depth + v[depth][0]) + v[depth][1]);
}
/* 완탐 */
int dfs(int depth, int cost) {
	if (depth > N) return 0;
	if (depth == N) {
		answer = max(answer, cost);
		return 0;
	}

	// 사용
	dfs(depth + v[depth][0], cost + v[depth][1]);

	// 미사용
	dfs(depth + 1, cost);
}
void Solve() {
	memset(dp, -1, sizeof dp);
	//dfs(0, 0);
	//cout << answer << endl;
	cout << dfs3(0) << endl;
}
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	int t, p;
	for (int i = 0; i < N; i++) {
		cin >> v[i][0] >> v[i][1];
	}
}
int main() {
	init();
	Solve();
	return 0;
}