#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define endl '\n'

int N, A, B;
vector<pair<int, int>> v;
map<pair<int, int>, int> mp;
void Solve() {
	for (int i = 0; i < N; i++) {
		mp[v[i]]++;
	}
	// 완탐
	int answer = 0;
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;

		if (mp.find({ x + A, y }) == mp.end()) continue;
		if (mp.find({ x, y + B }) == mp.end()) continue;
		if (mp.find({ x + A, y + B }) == mp.end()) continue;
		answer++;
	}
	cout << answer << endl;
}
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> A >> B;
	int x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		v.push_back({ x, y });
	}
}
int main() {
	init();
	Solve();
	return 0;
}