#include <iostream>
#include <algorithm>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;

/* define */
#define endl '\n'
typedef struct State {
	int x, y, d;
	State(int X, int Y, int D) : x(X), y(Y), d(D) {}
}State;
/* var */
int N, answer;
int board[500][500];
const int dir[4][2] = { {0,1}, {1, 0}, {0, -1}, {-1, 0} };
void spread(int x, int y, int d) {
	// 주변으로 퍼지는 방향은 (d + 1)%4, (d+3)%4 임
	int x1 = x + dir[d][0];
	int y1 = y + dir[d][1];
	if (x1 < 0 || x1 >= N || y1 < 0 || y1 >= N || board[x1][y1] == 0) return;
	// 1% 배분
	int left = board[x1][y1];
	int amount = board[x1][y1] / 100;
	for (int i = 0; i < 2; i++) {
		int nd = (d + (2 * i + 1)) % 4;
		int nx = x + dir[nd][0];
		int ny = y + dir[nd][1];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
			answer += amount;
		}
		else board[nx][ny] += amount;
		left -= amount;
	}

	// 7% 배분
	amount = board[x1][y1] * 7 / 100;
	for (int i = 0; i < 2; i++) {
		int nd = (d + (2 * i + 1)) % 4;
		int nx = x1 + dir[nd][0];
		int ny = y1 + dir[nd][1];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
			answer += amount;
		}
		else board[nx][ny] += amount;
		left -= amount;
	}
	// 2% 배분
	amount = board[x1][y1] / 50;
	for (int i = 0; i < 2; i++) {
		int nd = (d + (2 * i + 1)) % 4;
		int nx = x1 + 2 * dir[nd][0];
		int ny = y1 + 2 * dir[nd][1];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
			answer += amount;
		}
		else board[nx][ny] += amount;
		left -= amount;
	}
	// 10% 배분
	amount = board[x1][y1] / 10;
	int x2 = x1 + dir[d][0];
	int y2 = y1 + dir[d][1];
	for (int i = 0; i < 2; i++) {
		int nd = (d + (2 * i + 1)) % 4;
		int nx = x2 + dir[nd][0];
		int ny = y2 + dir[nd][1];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
			answer += amount;
		}
		else board[nx][ny] += amount;
		left -= amount;
	}

	// 5% 배분
	amount = board[x1][y1] / 20;
	int x3 = x2 + dir[d][0];
	int y3 = y2 + dir[d][1];
	if (x3 < 0 || x3 >= N || y3 < 0 || y3 >= N) {
		answer += amount;
	}
	else board[x3][y3] += amount;
	left -= amount;

	// 알파자리 처리
	if (x2 < 0 || x2 >= N || y2 < 0 || y2 >= N) {
		answer += left;
	}
	else board[x2][y2] += left;

	board[x1][y1] = 0;
}
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
}
int main() {
	init();
	// 방문 순서 stack에 저장
	stack<tuple<int, int, int>> stk;
	vector<vector<int>> visited(N, vector<int>(N, 0));
	int x = 0, y = 0, d = 0;
	for (int i = 0; i < N * N; i++) {
		if (d == 0 || d == 2)
			stk.push({ x, y, 2 - d });
		else
			stk.push({ x, y, 4 - d });
		visited[x][y] = 1;
		int nx = x + dir[d][0];
		int ny = y + dir[d][1];
		if (nx >= N || nx < 0 || ny >= N || ny < 0 || visited[nx][ny]) {
			d = (d + 1) % 4;
		}
		x = x + dir[d][0];
		y = y + dir[d][1];
	}
	while (!stk.empty()) {
		int x, y, d;
		tie(x, y, d) = stk.top(); stk.pop();

		spread(x, y, d);
	}
	cout << answer << endl;
	return 0;
}