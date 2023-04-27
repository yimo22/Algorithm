#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
#define endl '\n'
#define INF 987654321
int a, b, c, d, e, f;
pair<int,int> Solve() {
	for (int x = -999; x <= 999; x++) {
		for (int y = -999; y <= 999; y++) {
			if (a * x + b * y != c) continue;
			if (d * x + e * y != f) continue;
			return {x, y};
		}
	}
}
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b >> c >> d >> e >> f;
}
int main() {
	init();
	auto res = Solve();
	cout << res.first << " " << res.second;
	return 0;
}