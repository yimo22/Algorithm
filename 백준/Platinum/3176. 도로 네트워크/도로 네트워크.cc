#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N, K;
vector<pair<int,int>> adj[100'000 +1];
vector<pair<int, int>> orders;
int parent[100'000 + 1];
int depth[100'000 + 1];
int ac[100'000 + 1][18];
int acw[100'000 + 1][18][2];
int maxK;

pair<int,int> lcs(int v1, int v2) {
	// b를 깊은 노드로 맞춤
	int amax = -1, amin = 1'000'000;
	int a = v1, b = v2;
	if (depth[a] > depth[b]) swap(a, b);

	// 높이를 맞춤
	int diff = depth[b] - depth[a];
	for (int i = 0; diff > 0; i++) {
		if (diff & 1) {
			amax = max(amax, acw[b][i][1]);
			amin = min(amin, acw[b][i][0]);
			b = ac[b][i];
		}
		diff >>= 1;
	}

	if (a != b) {

		for (int k = maxK; k >= 0; k--) {
			if (ac[a][k] > 0 && ac[a][k] != ac[b][k]) {
				amin = min(amin, acw[a][k][0]);
				amax = max(amax, acw[a][k][1]);
				amin = min(amin, acw[b][k][0]);
				amax = max(amax, acw[b][k][1]);

				
				a = ac[a][k];
				b = ac[b][k];
			}
		}
		// 현재 조상이 공통조상임
		amin = min(amin, acw[a][0][0]);
		amax = max(amax, acw[a][0][1]);
		amin = min(amin, acw[b][0][0]);
		amax = max(amax, acw[b][0][1]);
	}
	return make_pair(amin, amax);
}

void Solve() {
	for (int i = 0; i < orders.size(); i++) {
		pair<int, int> res = lcs(orders[i].first, orders[i].second);
		cout << res.first << " " << res.second << '\n';
	}
}

void dfs(int v, bool * visited) {
	for (pair<int, int> nv : adj[v]) {
		if (!visited[nv.first]) {
			visited[nv.first] = true;
			parent[nv.first] = v;
			depth[nv.first] = depth[v] + 1;
			ac[nv.first][0] = v;
			acw[nv.first][0][0] = acw[nv.first][0][1] = nv.second;
			dfs(nv.first, visited);
		}
	}
}
void make() {
	bool visited[100'000 + 1];
	for (int i = 0; i <= N; i++) visited[i] = false;
	depth[1] = 1;
	dfs(1, visited);

	// ac update
	maxK = (int) floor(log2(N));
	for (int k = 0; k < maxK; k++) {
		for (int i = 1; i <= N; i++) {
			if (ac[i][k] > 0) {
				ac[i][k + 1] = ac[ac[i][k]][k];
				acw[i][k + 1][0] = min(acw[ac[i][k]][k][0],acw[i][k][0]);
				acw[i][k + 1][1] = max(acw[ac[i][k]][k][1], acw[i][k][1]);
			}
		}
	}
}
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		adj[s].push_back({ e, w });
		adj[e].push_back({ s, w });
	}

	cin >> K;
	for (int i = 0; i < K; i++) {
		int s, e;
		cin >> s >> e;
		orders.push_back({ s, e });
	}
	return;
}
int main() {
	init();
	make();
	Solve();
	return 0;
}