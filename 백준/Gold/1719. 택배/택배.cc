#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
#define endl '\n'
#define INF 987654321
int N, M;
vector<tuple<int, int, int>> edges;
vector<vector<int>> path(200, vector<int>(200, INF));
vector<vector<int>> trace(200, vector<int>(200, 0));
void Solve() {
	// make Graph
	for (auto a : edges) {
		int s, e, w;
		tie(s, e, w) = a;
		path[e][s] = path[s][e] = w;
		trace[e][s] = s;
		trace[s][e] = e;
	}
	// floyd
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (path[i][j] > path[i][k] + path[k][j]) {
					if (k != j) trace[i][j] = trace[i][k];
					path[i][j] = path[i][k] + path[k][j];
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) cout << "-" << " ";
			else cout << trace[i][j] + 1 << " ";
		}
		cout << endl;
	}
}
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	int s, e, w;
	for (int i = 0; i < M; i++) {
		cin >> s >> e >> w;
		edges.push_back({ s-1, e-1,w });
	}
}
int main() {
	init();
	Solve();

	return 0;
}