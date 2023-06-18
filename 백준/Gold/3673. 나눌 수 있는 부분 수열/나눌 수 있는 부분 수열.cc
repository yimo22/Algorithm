#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* define */
#define endl '\n'
#define ll long long
/* var */
int c;
int d, n;
vector<int> arr;
void init() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> c;
}
void Solve() {
	// 연속하는 부분 수열의 합이 d로 나누어 떨어지는 것의 갯수
	// (i~j) 까지의 합 중, d의 배수의 갯수를 구하기
	vector<ll> psum;
	psum.resize(n + 1);
	psum[0] = 0;
	vector <ll> modulo(d, 0); // 나머지 i 인 갯수
	for (int i = 1; i <= n; i++) {
		psum[i] = psum[i - 1] + arr[i - 1];
		modulo[psum[i] % d]++;
	}

	ll answer = 0;
	// 구간합이 0인 것은 자체가 답임
	answer += modulo[0];
	for (int i = 0; i < d; i++) {
		answer += (ll)modulo[i] * (modulo[i] - 1) / 2;
	}
	cout << answer << endl;
}
int main() {
	init();
	for (int t = 0; t < c; t++) {
		cin >> d >> n;
		arr.resize(n);
		for (int i = 0; i < n; i++) cin >> arr[i];

		Solve();
	}
}