#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

int N, M;
vector<string> board;
constexpr int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int sx, sy;
void Solve() {
	queue<tuple<int,int,int>> q; // 
	int answer = -1;
	vector<vector<int>> visited(N, vector<int>(M, 0));
	board[sx][sy] = 0;
	visited[sx][sy] = 1;
	q.push({sx,sy,0});

	while (!q.empty()) {
		int x, y, cnt;
		tie(x, y, cnt) = q.front(); q.pop();

		if (board[x][y] > '2') {
			answer = cnt;
			break;
		}

		for (int d = 0; d < 4; d++) {
			int nx = x + dir[d][0];
			int ny = y + dir[d][1];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (board[nx][ny] == '1') continue;
			if (visited[nx][ny]) continue;
			visited[nx][ny] = 1;
			q.push({ nx,ny,cnt + 1 });
		}
	}
	if (answer == -1) {
		cout << "NIE";
	}
	else {
		cout << "TAK" << '\n' << answer;
	}
}
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	string tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		board.push_back(tmp);
		for (int j = 0; j < M; j++) {
			if (board[i][j] == '2') {
				sx = i;
				sy = j;
			}
		}
	}
}
int main() {
	init();
	Solve();
	return 0;
}