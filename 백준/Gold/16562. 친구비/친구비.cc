#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#define MAX 10'000
using namespace std;


vector<pair<int,int>> edges;
int N, M, K;
int parent[MAX + 1];
int find(int a) {
	if (a == parent[a]) return a;
	return parent[a] = find(parent[a]);
}
int uni(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	if (pa == pb) return 0;

	if (pa < pb)
		parent[pb] = pa;
	else parent[pa] = pb;
	return 1;
}

int allConnect() {
	for (int i = 0; i <= N; i++) if (find(i) != 0) return 0;
	return 1;
}

int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		int w;
		cin >> w;
		edges.push_back(make_pair(w, i+1));
	}
	// union-find
	for (int i = 0; i <= N; i++) parent[i] = i;

	for (int i = 0; i < M; i++) {
		int v, w;
		cin >> v >> w;
		// 자기 자신과 친구일 수 있다.
		// 같은 친구관계가 여러번 주어질 수 있다.
		uni(v, w);
	}


	//for (int i = 0; i <= N; i++) cout << parent[i] << " ";
	//cout << endl;
	sort(edges.begin(), edges.end());

	int cost = 0;
	for (pair<int, int> cur : edges) {
		// 연결되어 있는지 check
		if (uni(cur.second, 0)) {
			cost += cur.first;
		}

		if (cost > K) break;
		if (allConnect()) break;
	}

	if (allConnect() && cost <= K) cout << cost;
	else cout << "Oh no";
	return 0;
}