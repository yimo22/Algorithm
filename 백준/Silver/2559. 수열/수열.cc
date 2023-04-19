#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

vector<int> arr(100'000, 0);
vector<int> psum(100'000 + 1, 0);
int N, K;
void Solve() {
	// getSum
	for (int i = 0; i < N; i++) {
		psum[i + 1] = psum[i] + arr[i];
	}
	int answer = -987'654'321;
	for (int i = K; i <= N; i++) {
		answer = max(psum[i] - psum[i - K], answer);
	}
	cout << answer << endl;
}
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}
int main() {
	init();
	Solve();
	return 0;
}