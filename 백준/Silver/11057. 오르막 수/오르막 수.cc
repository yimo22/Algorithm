#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/* define*/
#define endl '\n'
#define MAX 1'000
#define MODULO 10'007
#define INF 987654321
/* var*/
int N;
vector<vector<int>> dp(MAX + 1, vector<int>(10, INF)); // [i][j] : 앞자리 j, 길이 i인 오르막의 수
int search(int len, int w) {
	if (len == 1) {
		return dp[len][w] = 1;
	}

	if (dp[len][w] != INF) return dp[len][w];

	dp[len][w] = 0;
	for (int i = w; i <= 9; i++) {
		dp[len][w] += search(len -1, i);
		dp[len][w] %= MODULO;
	}
	return dp[len][w];
}
void Solve() {
	int answer = 0;
	for (int i = 0; i <= 9; i++) {
		answer += search(N, i);
		answer %= MODULO;
	}
	cout << answer << endl;
}
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
}
int main() {
	init();
	Solve();
	return 0;
}