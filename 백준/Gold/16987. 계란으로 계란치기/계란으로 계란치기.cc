#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define endl '\n'
int N;
int w[8];
int hp[8];
vector<int> arr(8, -1);
int Ans = 0;
void perm(int pos) {
	if (pos >= N) {
		vector<int> power(N, 0);
		for (int i = 0; i < N; i++) power[i] = hp[i];
		for (int i = 0; i < N; i++) {
			// 현재 i번째 계란으로 arr[i]번째 계란을 칠거임
			if (power[arr[i]] <= 0 || power[i] <= 0) continue;
			power[i] -= w[arr[i]];
			power[arr[i]] -= w[i];
		}

		int answer = 0;
		for (int i = 0; i < N; i++) if (power[i] <= 0) answer++;
		
		Ans = max(Ans, answer);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (pos == i) continue; // 자기자신을 떄릴수 없음
		arr[pos] = i;
		perm(pos + 1);
	}
}
void Solve() {
	perm(0);
	cout << Ans << endl;
	return;
}
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> hp[i] >> w[i];
	}
}
int main() {
	init();
	Solve();
}