#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100000
#define endl '\n'
#define MODULO 1000000009
// 합이 i인 대칭수의 경우의수
vector<int> dp(MAX + 1, -1);
int N;
int search(int N) {
	if (N == 1) {
		return dp[N] = 1;
	}
	if (N == 0) return dp[N] = 1;
	if (N == 2) return dp[N] = 2;
	if (N == 3) return dp[N] = 2;
	if (dp[N] != -1) return dp[N];

	dp[N] = 0;
	if (N - 2 >= 0) dp[N] = (dp[N] + search(N - 2)) % MODULO;
	if (N - 4 >= 0) dp[N] = (dp[N] + search(N - 4)) % MODULO;
	if (N - 6 >= 0) dp[N] = (dp[N] + search(N - 6)) % MODULO;
	return dp[N];
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	int w=0;
	for (int i = 0; i < N; i++) {
		cin >> w;
		cout << search(w) << endl;
	}

	return 0;
}