#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/* define*/
#define endl '\n'
#define MAX 1024

/* var*/
int N, M, tmpN;
vector<vector<int>> seg(2 * MAX, vector<int>(2 * MAX, 0));

int getVal(int idx, int x1, int x2) {
	x1 = x1 + tmpN - 1;
	x2 = x2 + tmpN - 1;

	int sum = 0;
	while (x1 <= x2) {
		if (x1 & 1) {
			sum += seg[idx][x1];
			x1++;
		}
		x1 >>= 1;

		if (!(x2 & 1)) {
			sum += seg[idx][x2];
			x2--;
		}
		x2 >>= 1;
	}
	return sum;
}

int get(int x1, int y1, int x2, int y2) {
	y1 = tmpN + y1 - 1;
	y2 = tmpN + y2 - 1;
	int sum = 0;
	while (y1 <= y2) {
		if (y1 & 1) {
			sum += getVal(y1, x1, x2);
			y1++;
		}
		y1 >>= 1;

		if (!(y2 & 1)) {
			sum += getVal(y2, x1, x2);
			y2--;
		}
		y2 >>= 1;
	}
	return sum;
}
void update(int x, int y, int w) {
	/* 1D update*/
	int pos = tmpN + x - 1;
	seg[tmpN + y - 1][pos] = w;

	pos >>= 1;
	for (; pos >= 1; pos >>= 1) {
		seg[tmpN + y - 1][pos] = seg[tmpN + y - 1][pos * 2] + seg[tmpN + y - 1][pos * 2 + 1];
	}

	/* 2D update*/
	pos = tmpN + y - 1;
	pos >>= 1;
	for (; pos >= 1; pos >>= 1) {
		int j = tmpN + x - 1;
		seg[pos][j] = seg[pos * 2][j] + seg[pos * 2 + 1][j];

		j >>= 1;
		while (j >= 1) {
			seg[pos][j] = seg[pos * 2][j] + seg[pos * 2 + 1][j];
			j >>= 1;
		}
	}
}
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	tmpN = pow(2, ceil(log2(N)));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> seg[tmpN + j][tmpN + i];
		}
	}
	// init update
	// 1D update
	for (int i = 0; i < N; i++) {
		for (int j = tmpN - 1; j >= 1; j--) {
			seg[tmpN + i][j] = seg[tmpN + i][2 * j] + seg[tmpN + i][2 * j + 1];
		}
	}
	// 2D update
	for (int i = tmpN - 1; i >= 1; i--) {
		for (int j = 1; j < 2 * tmpN; j++) {
			seg[i][j] = seg[i * 2][j] + seg[i * 2 + 1][j];
		}
	}

	for (int i = 0; i < M; i++) {
		int w, x1, y1, x2, y2;
		cin >> w;
		if (w == 0) {
			cin >> x1 >> y1 >> w;
			update(x1, y1, w);
		}
		else if (w == 1) {
			cin >> x1 >> y1 >> x2 >> y2;
			cout << get(x1, y1, x2, y2) << endl;
		}
	}
}
int main() {
	init();
	return 0;
}