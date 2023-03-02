#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#define MAX 100'000
using namespace std;

int N;
vector<pair<int,int>> adj[MAX + 1];
int depth[MAX + 1];
int ac[MAX+1][20];
int visited[MAX + 1];
long long aw[MAX+1][20]; // [i][j] : 노드i의 2^j 번쨰 조상까지의 거리
int maxK;
void bfs() {
	// root는 1번노드
	queue<int> q;
	visited[1] = 1;
	q.push(1);

	while (!q.empty()) {
		int v = q.front(); q.pop();

		for (auto v2 : adj[v]) {
			int nv = v2.first;
			int w = v2.second;
			if (!visited[nv]) {
				visited[nv] = 1;
				depth[nv] = depth[v] + 1;
				ac[nv][0] = v;
				aw[nv][0] = w;
				q.push(nv);
			}
		}
	}
}
long long lcs(int v1, int v2) {
	// b가 더 깊은 V
	int a = v1, b = v2;
	if (depth[v1] > depth[v2]) swap(a, b);

	long long answer = 0;
	// depth 맞춤
	int diff = depth[b] - depth[a];
	for (int i = 0; diff > 0; i++) {
		if (diff & 1) {
			answer += aw[b][i];
			b = ac[b][i];
		}
		diff >>= 1;
	}

	if (a != b) {
		for (int k = maxK; k >= 0; k--) {
			if (ac[a][k] > 0 && ac[a][k] != ac[b][k]) {
				answer += aw[a][k];
				answer += aw[b][k];
				a = ac[a][k];
				b = ac[b][k];
			}
		}
		// 현재 노드의 부모가 공통조상
		answer += aw[a][0];
		answer += aw[b][0];
	}
	return answer;

}

void makeTree() {
	// root 는 1번노드
	bfs();

	// ac 초기화
	maxK = (int)ceil(log2(N));
	for (int k = 0; k <= maxK; k++) {
		for (int i = 1; i <= N; i++) {
			if (ac[i][k] > 0) {
				ac[i][k+1] = ac[ac[i][k]][k];
				if (ac[i][k] > N) continue;
				aw[i][k + 1] = aw[ac[i][k]][k] + aw[i][k];
			}
		}
	}
}
int getLcs(int v1, int v2) {
	int a = v1, b = v2;
	if (depth[a] > depth[b]) swap(a, b);

	int diff = depth[b] - depth[a];
	for (int i = 0; diff > 0; i++) {
		if (diff & 1) {
			b = ac[b][i];
		}
		diff >>= 1;
	}

	if (a != b) {
		for (int k = maxK; k >= 0; k--) {
			if (ac[a][k] > 0 && ac[a][k] != ac[b][k]) {
				a = ac[a][k];
				b = ac[b][k];
			}
		}
		a = ac[a][0];
	}
	return a;
}
int getKNode(int v1, int v2, int K) {
	int lcs = getLcs(v1, v2);
	// case1. v1 <-> lcs 사이에 있는 경우
	int cnt = depth[v1] - depth[lcs] + 1;
	if (depth[v1] - depth[lcs] + 1 >= K) {
		int diff = K - 1;
		for (int i = 0; diff > 0; i++) {
			if (diff & 1) {
				v1 = ac[v1][i];
			}
			diff >>= 1;
		}

		return v1;
	}
	else { // case 2. v2 <-> lcs 사이에 있는 경우
		int diff = depth[v2] - (K - cnt + depth[lcs]);
		for (int i = 0; diff > 0; i++) {
			if (diff & 1) {
				v2 = ac[v2][i];
			}
			diff >>= 1;
		}
		return v2;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N-1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ v, w });
		adj[v].push_back({ u, w });
	}
	makeTree();
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int o, u, v;
		cin >> o >> u >> v;
		if (o == 1) {
			cout << lcs(u, v) << '\n';
		}
		else {
			int k;
			cin >> k;
			cout << getKNode(u, v, k) << '\n';
		}
	}

	return 0;
}