#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
/* define*/
#define endl '\n'
#define MAX 1'000'000
#define ll long long
/* var*/
int N, M, K;
int tmpN;
vector<ll> arr(2 * pow(2, ceil(log2(MAX))), 0);
ll get(int a, int b) {
	a = tmpN + a - 1;
	b = tmpN + b - 1;

	ll sum = 0;
	while (a <= b) {
		if (a & 1) {
			sum += arr[a];
			a++;
		}
		a >>= 1;

		if (!(b & 1)) {
			sum += arr[b];
			b--;
		}
		b >>= 1;
	}
	return sum;
}
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> K;
	tmpN = pow(2, ceil(log2(N)));
	for (int i = 0; i < N; i++) {
		cin >> arr[tmpN + i];
	}
	//update
	for (int i = tmpN - 1; i >= 1; i--) {
		arr[i] = arr[i * 2] + arr[i * 2 + 1];
	}

	ll a, b, c;
	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			arr[tmpN + b - 1] = c;
			for (int p = (tmpN + b - 1) / 2; p >= 1; p/=2) {
				arr[p] = arr[p * 2] + arr[p * 2 + 1];
			}
		}
		else if (a == 2) {
			cout << get(b, c) << endl;
		}
	}

}
int main() {
	init();
}