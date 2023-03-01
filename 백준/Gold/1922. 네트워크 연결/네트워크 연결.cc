#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
int N, M;
vector<tuple<int, int, int>> edge;
int arr[1000 + 1];
bool comp(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
	return get<2>(a) < get<2>(b);
}
int getParent(int v) {
	if (arr[v] == v) return arr[v];
	else return arr[v] = getParent(arr[v]);
}
void Union(int a, int b) {
	int pa = getParent(a);
	int pb = getParent(b);
	arr[pa] = pb;
	return;
}
void Solve() {
	// init
	int answ = 0;
	sort(edge.begin(), edge.end(), comp);
	for (int i = 0; i <= N; i++) arr[i] = i;
	int cnt = 0, pos =0;
	while (cnt <= N - 1 && pos < M) {
		int a, b, value;
		tie(a, b, value) = edge[pos++];
		if (getParent(a) != getParent(b)) {
			cnt++;
			answ += value;

			Union(a, b);
		}
	}
	cout << answ << "\n";
	return;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int s, e, v;
		cin >> s >> e >> v;
		edge.push_back(make_tuple(s, e, v));
	}

	// start
	Solve();
	return 0;
}