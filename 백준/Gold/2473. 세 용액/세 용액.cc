#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long
#define endl '\n'
int N;
vector<ll> v;
void Solve() {
	sort(v.begin(), v.end());
	ll answer = v[0] + v[1] + v[2];
	ll val[3] = { v[0], v[1], v[2]};
	for (int i = 0; i < N-2; i++) {
		for (int j = i + 1, k = N - 1; j < k;) {
			ll result = v[i] + v[j] + v[k];

			if (abs(answer) > abs(result)) {
				val[0] = v[i];
				val[1] = v[j];
				val[2] = v[k];
				answer = result;
			}
			
			if (result >= 0) {
				k--;
			}
			else j++;
		}
	}
	cout << val[0] << " " << val[1] << " " << val[2] << endl;
	return;
}
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	int w;
	for (int i = 0; i < N; i++) {
		cin >> w;
		v.push_back(w);
	}
}
int main() {
	init();
	Solve();
	return 0;
}