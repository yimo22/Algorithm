#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/* define*/
const int dir[8][2] = { {0, -1},{-1, -1},{-1, 0},{-1, 1},{0, 1},{1, 1},{1, 0},{1, -1} };
typedef struct {
	int x, y;
}Shark;
typedef struct Fish{
	int x, y, d;
	Fish(int X, int Y, int D) : x(X), y(Y), d(D) {}
}Fish;
/* var */
int M, S;
int maxFishCount;
string path;
Shark sk;
vector<Fish> fishList;
vector<Fish> board[4][4];
int smells[4][4];
/* shark dir -> dir*/
int convert(int d) {
	if (d == 1) return 2;
	else if (d == 2) return 0;
	else if (d == 3) return 6;
	else if (d == 4) return 4;
}
/* dir -> shark dir*/
int convertSharkDir(int d) {
	if (d == 2) return 1;
	else if (d == 0) return 2;
	else if (d == 4) return 4;
	else if (d == 6) return 3;
}
void search(int depth, int x, int y, string history) {
	if (depth >= 3) {
		// 현재 히스토리로 탐ㄴ색
		vector<vector<int>> visited(4, vector<int>(4, 0));
		int cx = sk.x;
		int cy = sk.y;
		int cnt = 0;
		for (int i = 0; i < 3; i++) {
			int d = convert(history[i] - '0');
			cx += dir[d][0];
			cy += dir[d][1];

			if (!visited[cx][cy]) {
				visited[cx][cy] = 1;
				cnt += board[cx][cy].size();
			}
		}

		if (maxFishCount < cnt) {
			path = history;
			maxFishCount = cnt;
		}
		else if (maxFishCount == cnt) {
			path = (path < history) ? path : history;
		}
		return;
	}

	for (int i = 1; i <= 4; i++) {
		int d = convert(i);
		int nx = x + dir[d][0];
		int ny = y + dir[d][1];
		if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;

		search(depth + 1, nx, ny, history + to_string(i));
	}
}
void sharkMove() {
	// 4방향 이동
	// 같은 최대의 물고기 수에 대해서는 사전순으로 앞선 것을 택함
	maxFishCount = 0;
	path = "444";
	search(0, sk.x, sk.y, "");
	// 어떤 경우로도 물고기를 먹을 수 없는 경우
	if (maxFishCount == 0) {
		for (int i = 0; i < 3; i++) {
			int nd;
			for (int d = 0; d < 4; d++) {
				nd= convert(d+1);
				int nx = sk.x + dir[nd][0];
				int ny = sk.y + dir[nd][1];
				if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
				break;
			}
			sk.x += dir[nd][0];
			sk.y += dir[nd][1];
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			int d = convert(path[i]-'0');

			sk.x += dir[d][0];
			sk.y += dir[d][1];
			if (!board[sk.x][sk.y].empty()) smells[sk.x][sk.y] = 3;
			board[sk.x][sk.y].clear();
		}
	}
}
void fishMove() {
	for (int i = 0; i < fishList.size(); i++) {
		Fish& cur = fishList[i];
		int nx, ny, nd = cur.d;
		int rep = 0;
		for (rep = 0; rep < 8; rep++, nd = (nd + 8 - 1) % 8) {
			nx = cur.x + dir[nd][0];
			ny = cur.y + dir[nd][1];

			if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
			if (smells[nx][ny] > 0) continue;
			if (sk.x == nx && sk.y == ny) continue;
			break;
		}
		// 불가능한 경우
		if (rep == 8) {
			board[cur.x][cur.y].push_back(Fish(cur.x,cur.y, cur.d));
		}
		else {
			board[nx][ny].push_back(Fish(nx,ny,nd));
		}
	}
}
void copyFish() {
	fishList.clear();
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < board[i][j].size(); k++) {
				fishList.push_back(board[i][j][k]);
			}
			board[i][j].clear();
		}
	}
}
void smellRemove() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (smells[i][j] > 0) smells[i][j]--;
		}
	}
}
void boardUpdate() {
	for (int i = 0; i < fishList.size(); i++) {
		Fish c = fishList[i];
		board[c.x][c.y].push_back(c);
	}
	fishList.clear();
}
void Solve() {
	while (S > 0) {
		copyFish();
		fishMove();
		sharkMove();
		smellRemove();
		boardUpdate();
		S--;
	}
}
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> M >> S;
	for (int i = 0; i < M; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		board[x - 1][y - 1].push_back(Fish(x-1,y-1,d-1));
	}
	cin >> sk.x >> sk.y;
	sk.x--;
	sk.y--;
}
int main() {
	init();
	Solve();

	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cnt += board[i][j].size();
		}
	}
	cout << cnt << '\n';
	return 0;
}