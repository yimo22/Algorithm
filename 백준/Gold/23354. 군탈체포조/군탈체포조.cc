#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#define MAX 1'000
using namespace std;
/* input
	5
	1 3 2 0 9
	2 0 4 4 3
	5 3 -1 1 1
	3 7 2 0 1
	1 2 3 5 0
*/
int N;
int map[MAX][MAX];
int answer = 0x7fffffff;
vector<pair<int, int>> list; // 탈영병의 위치
pair<int, int> st; // 시작점(캠프)
int path[5][5]; //  탈영병 <-> 탈영병 사이의 최소거리 
int startPath[5]; // 시작점 <-> 탈영병 사이의 최소거리
const int dir[4][2] = { {1, 0}, {0,1}, {-1,0}, {0,-1} };
typedef struct Node {
	int x, y, cnt;
	Node(int X, int Y, int C) : x(X), y(Y), cnt(C) {}
}Node; // x, y까지의 거리 cnt
struct comp {
	bool operator()(Node & a, Node & b){
		return a.cnt > b.cnt;
	}
};
void djik(int index, pair<int,int> start) {
	vector<vector<int>> dist(N, vector<int>(N, 1'000'000'007));
	priority_queue<Node, vector<Node>, comp> pq; // 최소힙
	dist[start.first][start.second] = 0;
	pq.push(Node(start.first, start.second, 0));
	while (!pq.empty()) {
		Node cur = pq.top(); pq.pop();

		if (dist[cur.x][cur.y] < cur.cnt) continue;

		for (int d = 0; d < 4; d++) {
			int nx = cur.x + dir[d][0];
			int ny = cur.y + dir[d][1];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

			int nw = cur.cnt + map[nx][ny];

			if (dist[nx][ny] > nw) {
				dist[nx][ny] = nw;
				pq.push(Node(nx, ny, nw));
			}
		}
	}
	// update
	for (int i = 0; i < list.size(); i++) {
		if (index == i) {
			path[index][index] = 0;
			continue;
		}
		pair<int, int> v1 = list[i];
		path[index][i] = dist[v1.first][v1.second];
	}
}
void djik2() {
	vector<vector<int>> dist(N, vector<int>(N, 1'000'000'007));
	priority_queue<Node, vector<Node>, comp> pq; // 최소힙
	pq.push(Node(st.first, st.second, 0));
	dist[st.first][st.second] = 0;
	while (!pq.empty()) {
		Node cur = pq.top(); pq.pop();

		if (dist[cur.x][cur.y] < cur.cnt) continue;

		for (int d = 0; d < 4; d++) {
			int nx = cur.x + dir[d][0];
			int ny = cur.y + dir[d][1];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

			int nw = cur.cnt + map[nx][ny];

			if (dist[nx][ny] > nw) {
				dist[nx][ny] = nw;
				pq.push(Node(nx, ny, nw));
			}
		}
	}

	// update
	for (int i = 0; i < list.size(); i++) {
		pair<int, int> v1 = list[i];
		startPath[i] = dist[v1.first][v1.second];
	}
}
void perm(int depth,int used, int history[]) {
	if (depth >= list.size()) {
		// history를 기반으로 정답갱신
		int total = 0;
		for (int i = 0; i < list.size()-1; i++) {
			total += path[history[i]][history[i + 1]];
		}
		// add camp->first & last -> camp
		total += startPath[history[0]];
		total += startPath[history[list.size() - 1]];

		answer = min(answer, total);

		return;
	}

	for (int i = 0; i < list.size(); i++) {
		if (used & (1 << i)) continue;

		history[depth] = i;
		perm(depth + 1, used | (1 << i), history);
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) { 
			cin >> map[i][j]; 
			if (map[i][j] == 0) {
				list.push_back({ i,j });
			}
			if (map[i][j] == -1) {
				map[i][j] = 0;
				st.first = i;
				st.second = j;
			}
		}
	}
	if (list.size() == 0) {
		cout << "0\n";
		return 0;
	}

	// 각 노드에 대하여 다익스트라
	for (int i = 0; i < list.size(); i++) djik(i,list[i]);
	djik2(); // 캠프에 대하여 다익스트라

	// 순열
	perm(0,0, new int[list.size()]);
	cout << answer << '\n';
	return 0;
}