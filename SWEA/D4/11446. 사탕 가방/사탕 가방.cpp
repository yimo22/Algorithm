#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

/* define*/
typedef long long ll;
#define endl '\n'
#define MAX 1'000'000'000'000'000'000  // 10^18
/* var*/
ll N, M;
vector<ll> v;
ll solve() {
	// 가방의 수에 대하여 binarysearch
	ll l, r, mid;
	l = 0;
	r = MAX + 1;
	while (l < r && (r - l) > 1) {
		mid = l + (r - l) / 2;
		ll count = 0;
		for (int i = 0; i < N; i++) {
			count += v[i] / mid;
		}

		if (count >= M) l = mid;
		else r = mid;
	}
	return l;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> N >> M;
		v.clear();
		for (int i = 0; i < N; i++) {
			ll w;
			cin >> w;
			v.emplace_back(w);
		}
		cout << "#" << (tc + 1) << ' ';
		cout << solve() << '\n';
	}
	return 0;
}