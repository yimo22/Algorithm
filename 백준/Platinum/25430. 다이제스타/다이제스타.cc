#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

/* define*/
typedef long long ll;
#define endl '\n'
#define MAX 50'000
/* var*/
int N, M;
vector<pair<int, int>> adj[MAX + 1]; // {w, 노드}
struct comp {
	bool operator()(tuple<ll, int, int>  a, tuple<ll, int, int> b) {
		return get<0>(a) > get<0>(b);
	}
};
ll Solve(int sv, int ev) {
	// dijkstra
	ll* dist = new ll[N + 1]; // sv -> i 까지 갈수있는 최소경로(방문경로는 오름차순)
	fill_n(dist, N + 1, 0x7fff'ffff'ffff'ffff);
	priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, comp> pq; // 최소힙{총합거리, 직전의 가중치, 노드}
	pq.push({ 0, 0, sv });
	dist[sv] = 0;
	while (!pq.empty()) {
		ll distance;
		int prevW, v;
		tie(distance, prevW, v) = pq.top(); pq.pop();

		if (dist[v] < distance) continue;
		if (dist[ev] < distance) continue;
		if (v == ev) continue;


		for (auto nv : adj[v]) {
			ll ndist = distance + nv.first;
			// 오름차순 경로 && 최소비용
			if (dist[nv.second] > ndist && nv.first > prevW) {
				dist[nv.second] = ndist;
				pq.push({ ndist, nv.first, nv.second });
			}
		}
	}
	//for (int i = 1; i <= N; i++) cout << dist[i] << ' ';
	return dist[ev] == 0x7fffffffffffffff ? -1 : dist[ev];
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		adj[s].emplace_back(make_pair(w, e));
		adj[e].emplace_back(make_pair(w, s));
	}
	int sv, ev;
	cin >> sv >> ev;
	ll res = Solve(sv, ev);
	if (res == -1) cout << "DIGESTA";
	else cout << res;

	return 0;
}