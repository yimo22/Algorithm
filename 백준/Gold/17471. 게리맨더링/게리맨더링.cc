#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int N;
int arr[10];
int answer;
vector<int> adj[10];
int search(int check) {
	int visited = 0;
	int startV = -1;
	for (int i = 0; i < N; i++) {
		if (check & (1 << i)) {
			startV = i;
			break;
		}
	}
	queue<int> q;

	q.push(startV);
	visited |= (1 << startV);
	while (!q.empty()) {
		int v = q.front(); q.pop();

		for (int nv : adj[v]) {
			if (!(check & (1 << nv))) continue;

			if (!(visited & (1 << nv))) {
				visited |= (1 << nv);
				q.push(nv);
			}
		}
	}
	
	if (check == visited) {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			if (visited & (1 << i)) sum += arr[i];
		}
		return sum;
	}
	else return -1;
}
void dfs(int depth, int used) {
	if (depth >= N) {
		if (used == (1 << N) - 1 || used == 0) return;
		// 연결되어 있는지 확인
		int notUsed = used ^ ((1 << N) - 1);
		int res1 = search(used);
		int res2 = search(notUsed);
		if (res1 != -1 && res2 != -1) answer = min(answer, abs(res1 - res2));
		return;
	}


	// 사용
	dfs(depth + 1, used | (1 << depth));

	// 사용x
	dfs(depth + 1, used);
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	int w;
	for (int i = 0; i < N; i++) {
		cin >> w;
		int k;
		for (int j = 0; j < w; j++){
			cin >> k;
			adj[i].push_back(k-1);
		}
	}
	answer = 0x7fffffff;
	dfs(0, 0);

	if (answer == 0x7fffffff) cout << -1;
	else cout << answer;
	return 0;
}