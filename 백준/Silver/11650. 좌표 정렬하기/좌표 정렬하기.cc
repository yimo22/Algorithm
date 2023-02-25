#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> v;
bool comp(pair<int, int>& a, pair<int, int>& b) {
	if (a.first == b.first) return a.second < b.second;
	else return a.first < b.first;
}
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({x,y});
	}

	sort(v.begin(), v.end(), comp);
	for (auto k : v) {
		cout << k.first << " " << k.second << '\n';
	}

	return 0;

}