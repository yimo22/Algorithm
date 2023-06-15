#include <iostream>
#include <vector>

using namespace std;
/* define*/
#define endl '\n'
/* var*/
int N, M;
vector<int> v;
vector<int> prefix;
void init() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> N >> M;
	v.resize(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	prefix.resize(N + 1);
	prefix[0] = 0;
	for (int i = 1; i <= N; i++) prefix[i] = prefix[i - 1] + v[i - 1];
}
void Solve() {
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		cout << prefix[b] - prefix[a - 1] << endl;
	}
}
int main() {
	init();
	Solve();
}