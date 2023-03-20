#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

/* define*/
#define endl '\n'
#define MAX_N 2'000
const int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
/* var*/
int N, K;
int parent[MAX_N + 1];
int board[MAX_N + 1][MAX_N + 1];
vector<pair<int, int>> list;
int find(int a) {
	if (parent[a] == a) return a;
	else return parent[a] = find(parent[a]);
}
int uni(int a, int b) {
	int pa = find(a);
	int pb = find(b);

	if (pa == pb) return 0;

	parent[pa] = pb;

	return 1;
}
int check() {
	for (int i = 0; i < list.size(); i++) {
		if (find(1) != find(i + 1)) return 0;
	}
	return 1;
}
int Solve() {
	int cnt = 0;
	// init
	queue<pair<pair<int, int>, pair<int, int>>> q; // {cnt, x, y}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] > 0) q.push({ {0, board[i][j]}, {i,j} });
		}
	}
	while (!check()) {
		while (q.front().first.first <= cnt) {
			int curTime = q.front().first.first;
			int idx = q.front().first.second;
			pair<int, int> cur = q.front().second;
			q.pop();

			// 현재 노드를 기준으로 상하좌우로 문명 퍼짐
			for (int d = 0; d < 4; d++) {
				int nx = cur.first + dir[d][0];
				int ny = cur.second + dir[d][1];

				if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

				if (board[nx][ny] == 0) {
					board[nx][ny] = idx;
					// 주변 문명들과 연결
					for (int dd = 0; dd < 4; dd++) {
						int nnx = nx + dir[dd][0];
						int nny = ny + dir[dd][1];
						if (nnx < 0 || nnx >= N || nny < 0 || nny >= N) continue;
						if (board[nnx][nny] > 0) {
							uni(board[nnx][nny], idx);
						}
					}
					q.push({ {curTime + 1, idx} ,{nx,ny} });
				}
			}
		}
		cnt++;
	}
	return cnt;
}

void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i <= N; i++) parent[i] = i;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		board[x - 1][y - 1] = i + 1;
		list.push_back({ x - 1, y - 1 });
	}

	for (int i = 0; i < list.size(); i++) {
		pair<int, int> cur = list[i];
		for (int d = 0; d < 4; d++) {
			int nx = cur.first + dir[d][0];
			int ny = cur.second + dir[d][1];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

			if (board[nx][ny] != 0) uni(board[nx][ny], i + 1);
		}
	}
}

int main() {
	init();
	cout << Solve();

	return 0;
}
