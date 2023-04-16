#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define INF 987654321
#define endl '\n'
int N;
vector<int> dp(100'000 + 1, INF);
int search(int w) {
	if (w < 0) return INF;
	if (w == 0) return dp[0] = 0;
	if(w == 1){
		return dp[w] = 1;
	}
	if (dp[w] != INF) return dp[w];


	for (int i = 1; i * i <= w; i++) {
		dp[w] = min(dp[w], search(i * i) + search(w - i * i));
	}
	return dp[w];
}
void Solve() {
	for (int i = 1; i * i <= N; i++) dp[i * i] = 1;
	search(N);
	cout << dp[N] << endl;
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