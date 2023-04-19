#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 987654321



int N;
vector<int> dp(1'000'000+1, INF);
vector<int> trace(1'000'000 + 1, INF);
int search(int n) {
	if (n == 1) {
		trace[n] = -1;
		return dp[n] = 1;
	}
	if (dp[n] != INF) return dp[n];
	
	if (n % 3 == 0) {
		int res = search(n / 3) + 1;
		if (res < dp[n]) {
			trace[n] = n / 3;
			dp[n] = res;
		}
	}
	if (n % 2 == 0) {
		int res = search(n / 2) + 1;
		if (res < dp[n]) {
			trace[n] = n / 2;
			dp[n] = res;
		}
	}

	int res = search(n - 1) + 1;
	if (res < dp[n]) {
		trace[n] = n - 1;
	}
	return dp[n] = min(res, dp[n]);
}
void Solve() {
	cout << search(N) -1 << endl;
	int pos = N;
	while (pos > 0) {
		cout << pos << " ";
		pos = trace[pos];
	}
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