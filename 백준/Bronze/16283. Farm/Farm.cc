#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a, b, n, w;
int main() {
	cin >> a >> b >> n >>w;
	vector<pair<int, int>> v;
	for (int i = 1; i < n; i++) {
		int sumA = i * a;
		int sumB = (n - i) * b;
		if (sumA + sumB == w) v.push_back({ i, n - i });

		if (v.size() >= 2) break;
	}

	if (v.size() >= 2 || v.empty()) cout << -1;
	else cout << v[0].first << " " << v[0].second;

	return 0;
}