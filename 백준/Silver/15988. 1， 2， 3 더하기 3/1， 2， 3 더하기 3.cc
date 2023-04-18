#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'
#define MODULO 1'000'000'009
#define INF 987654321
int T;
vector<int> dp(1e6 + 1, INF);
int search(int n) {
	if (n == 1 ) return dp[n] = 1;
	if (n == 2) return dp[n] = 2;
	if (n == 3) return dp[n] = 4;

	if (dp[n] != INF) return dp[n];

	return dp[n] = ((search(n - 1) + search(n - 2)) % MODULO + search(n - 3)) % MODULO;
}
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	int n;
	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << search(n) << endl;
	}
}
int main() {
	init();
	return 0;
}