#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

/* define */
#define ll long long
#define endl '\n'
#define MAX 1e5
/* var */
int N, M;
vector<int> v;
vector<tuple<int, int, int>> query;
vector<pair<int,int>> tree; // index, value
bool comp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}
void makeTree(int pos, int l, int r) {
	if (l == r) {
		tree[pos] = make_pair(l, v[l-1]);
		return;
	}
	else {
		int mid = l + (r - l) / 2;

		// left
		makeTree(pos*2, l, mid);

		// right
		makeTree(pos * 2 + 1, mid+1, r);

		// update
		tree[pos] = tree[2 * pos];
		tree[pos] = min(tree[pos], tree[pos * 2 + 1], comp);
	}
}
void init() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	v.resize(N);
	tree.resize(3 * N);
	for (int i = 0; i < N; i++) cin >> v[i];
	cin >> M;
	int q, a, b;
	for (int i = 0; i < M; i++) {
		cin >> q >> a >> b;
		query.push_back({ q,a,b });
	}
	
	makeTree(1, 1, N);
}
void update(int idx, int value, int pos, int l, int r) {
	if (idx < l || idx > r) return;

	if (l == r) {
		tree[pos].second = value;
		return;
	}
	else {
		int mid = l + (r - l) / 2;

		update(idx, value,pos * 2, l, mid);
		update(idx, value,pos * 2 + 1, mid + 1, r);

		// update
		tree[pos] = tree[2 * pos];
		tree[pos] = min(tree[pos], tree[pos * 2 + 1], comp);
	}
}

// lb, rb : 찾고자 하는 범위
// l, r : 현재 노드의 범위
// pos : 현재 노드의 index
pair<int, int> getElem(int pos, int l, int r, int lb, int rb) {
	if (r < lb || rb < l) {
		return { 1e9 + 1, 1e9 + 1 };
	}
	if (lb <= l && r <= rb) {
		return tree[pos];
	}


	if (l == r) {
		return tree[pos];
	}
	else {
		pair<int, int> answer = make_pair(1e9 + 1, 1e9 + 1);
		int mid = l + (r - l) / 2;
		answer = min(answer, getElem(pos * 2, l, mid, lb, rb), comp);
		answer = min(answer, getElem(pos * 2 + 1, mid + 1, r, lb, rb), comp);
		return answer;
	}

}
void Solve() {
	for (int i = 0; i < query.size(); i++) {
		int c, a, b;
		tie(c, a, b) = query[i];
		if (c == 1) {
			update(a, b, 1, 1, N);
		}
		else if(c==2){
			cout << getElem(1, 1, N, a, b).first << endl;
		}
	}
}
int main() {
	init();
	Solve();

	return 0;
}

/*
	10
1 3 2 1 4 2 5 3 1 4
5
2 1 10
1 8 1
2 8 10
1 1 4
2 1 10

A)
1
8
4
*/