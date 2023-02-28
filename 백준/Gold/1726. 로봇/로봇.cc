#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 1'000'000'007
using namespace std;
const int dir[4][2] = { {0,1}, {0, -1}, {1, 0}, {-1, 0} };
int N, M;
int map[100][100];
int sr, sc, er, ec, sd, ed;
int visited[100][100][4]; // [r][c][d] : r,c 일때의 방향d 방문 여부
typedef struct Node {
	int x, y, d;
	int cnt;
	Node(int X, int Y, int D, int C) : x(X), y(Y), d(D), cnt(C) {}
}Node;
int rotate(int curD, int isRight) {
	if (isRight) {
		switch (curD) {
		case 0: return 2;
		case 1: return 3;
		case 2: return 1;
		case 3: return 0;
		default: break;
		}
	}
	else {
		switch (curD) {
		case 0: return 3;
		case 1: return 2;
		case 2: return 0;
		case 3: return 1;
		default: break;
		}
	}
}

int isIn(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M) return 0;
	else return 1;
}
int Solve() {
	// init
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 4; k++) {
				visited[i][j][k] = MAX;
			}
		}
	}
	queue<Node> q;
	q.push(Node(sr, sc, sd, 0));
	visited[sr][sc][sd] = 0;
	while (!q.empty()){
		Node cur = q.front(); q.pop();
		//printf("cur : %d %d %d %d \n", cur.x, cur.y, cur.d, cur.cnt);
		// check
		if (cur.x == er && cur.y == ec && cur.d == ed) return cur.cnt;
		if (cur.cnt > visited[cur.x][cur.y][cur.d]) continue;

		// 방향을 바꾸는 경우 (2가지)
		int nd = rotate(cur.d, 1);
		// 방문 시점이 더 이전인경우 && 방향을 바꿨는데 해당 앞에 벽이 없는 경우
		if (visited[cur.x][cur.y][nd] > cur.cnt + 1){
			visited[cur.x][cur.y][nd] = cur.cnt + 1;
			q.push(Node(cur.x, cur.y, nd, cur.cnt + 1));
		}
		nd = rotate(cur.d, 0);
		if (visited[cur.x][cur.y][nd] > cur.cnt + 1) {
			visited[cur.x][cur.y][nd] = cur.cnt + 1;
			q.push(Node(cur.x, cur.y, nd, cur.cnt + 1));
		}
		// 진행할 수 있는 만큼 진행하는 경우 (k가지)
		int nx = cur.x;
		int ny = cur.y;
		for (int k = 0; k < 3; k++) {
			nx += dir[cur.d][0];
			ny += dir[cur.d][1];
			//printf("\tnxt : %d %d\n", nx, ny);
			if (!isIn(nx, ny) || map[nx][ny] == 1) break;

			if (visited[nx][ny][cur.d] > cur.cnt + 1) {
				visited[nx][ny][cur.d] = cur.cnt + 1;
				q.push(Node(nx, ny, cur.d, cur.cnt + 1));
			}
		}
	}

}
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	cin >> sr >> sc >> sd;
	cin >> er >> ec >> ed;
	sd--;
	ed--;
	sr--;
	sc--;
	er--;
	ec--;
}
int main() {
	init();
	cout << Solve();

	return 0;
}