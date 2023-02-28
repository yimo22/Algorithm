#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#define MAX 1'000
using namespace std;

int map[MAX][MAX];
int N;
typedef struct Node {
	int idx, w;
	Node(int I, int W) : idx(I), w(W) {}
};
struct comp {
	bool operator()(Node & a, Node & b) {
		return a.w > b.w;
	}
};
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	// prim
	priority_queue<Node, vector<Node>, comp> pq; // 최소힙
	vector<int> visited(N, 0);
	
	pq.push(Node(0, 0));
	long long res = 0;
	while (!pq.empty()) {
		Node cur = pq.top(); pq.pop();

		if (visited[cur.idx]) continue;
		res += cur.w;
		visited[cur.idx] = 1;

		for (int i = 0; i < N; i++) {
			if (!visited[i] && map[cur.idx][i] > 0) {
				pq.push(Node(i, map[cur.idx][i]));
			}
		}
	}

	cout << res;




	return 0;
}