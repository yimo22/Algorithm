#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

/* define*/
#define endl '\n'
#define ll long long
/* var*/
int N;
void Solve() {
	// A^2 = B^2 + N
	// B를 선택
	// A의 제곱은 B의 제곱보다 N만큼 커 (1 ≤ N ≤ 1,000)
	int ans = 0;
	for (int i = 1; i <= 500; i++) {
		if (i*i + N > 500 * 500) break;
		int A = sqrt(i * i + N);
		if (A * A != i*i + N) continue;
		ans++;
	}
	cout << ans << endl;
}
void init() {
	cin >> N;
}
int main() {
	init();
	Solve();
	return 0;
}