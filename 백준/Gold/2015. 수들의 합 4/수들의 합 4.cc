#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

/* define */
#define endl '\n'
#define ll long long

int N, K;
int arr[200'000 + 1];
int psum[200'000 + 1];
unordered_map<ll, ll> mp;
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> arr[i];

	psum[0] = 0;
	for (int i = 0; i < N; i++) psum[i + 1] = psum[i] + arr[i];

	ll ans = 0;
	// O(N)
	for (int i = 1; i <= N; i++) {
		// case1. 1~i번째 까지의 합이 K
		if (psum[i] == K) {
			ans++;
		}
		// case2. 1~i번째 까지의 합이 K가 아님
		ans += mp[psum[i] - K];
		mp[psum[i]]++;
	}

	cout << ans << endl;
}
int main() {
	init();

	return 0;
}