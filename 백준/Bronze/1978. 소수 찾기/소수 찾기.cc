#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/* define*/
#define endl '\n'
/* var*/
int N;
int ans = 0;
vector<int> v;
vector<bool> prime(1000+1, true);
void init() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	prime[1] = false;
	for (int i = 2; i <= sqrt(1000); i++) {
		if (prime[i]) {
			for (int j = i + i; j <= 1000; j += i) prime[j] = false;
		}
	}

	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		int value = 0;
		cin >> value;
		if (prime[value]) ans++;
	}

}
int main() {
	init();
	cout << ans << endl;
	return 0;
}