#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;
int N, M;
vector<string> board;
int sx, sy;
int ex, ey;
constexpr int dir[4][2] = { {1, 0},{0, 1},{-1, 0},{0, -1} };
int search() {
	queue<tuple<int, int, int, int>> q;  // x, y, cnt, 보유열쇠
	int visited[50][50][1 << 6]; // x,y 에 열쇠보유의 방문여부
	memset(visited, 0, sizeof visited);
	q.push({ sx, sy, 0, 0 });
	visited[sx][sy][0] = 1;

	while (!q.empty()) {
		int x, y, cnt, has;
		tie(x, y, cnt, has) = q.front(); q.pop();

		for (int d = 0; d < 4; d++) {
			int nx = dir[d][0] + x;
			int ny = dir[d][1] + y;

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (board[nx][ny] == '#') continue;


			if (board[nx][ny] == '.' && !visited[nx][ny][has]) {
				visited[nx][ny][has] = cnt + 1;
				q.push({ nx,ny, cnt + 1, has });
			}

			if ('a' <= board[nx][ny] && board[nx][ny] <= 'f') {
				int nhas = has | (1 << (board[nx][ny] - 'a'));
				if (!visited[nx][ny][nhas]) {
					visited[nx][ny][nhas] = cnt + 1;
					q.push({ nx,ny, cnt + 1, nhas });
				}
			}

			if ('A' <= board[nx][ny] && board[nx][ny] <= 'F') {
				int isKey = (has & (1 << (board[nx][ny] - 'A')));
				if (isKey && !visited[nx][ny][has]) {
					visited[nx][ny][has] = cnt + 1;
					q.push({ nx,ny, cnt + 1, has });
				}
			}

			if (board[nx][ny] == '1') return cnt + 1;
		}
	}
	return -1;
}
void Solve() {
	cout << search();
}
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		board.push_back(s);
		for (int j = 0; j < M; j++) {
			if (board[i][j] == '0') {
				sx = i; sy = j;
				board[i][j] = '.';
			}
		}
	}
}
int main() {
	init();
	Solve();
	return 0;
}