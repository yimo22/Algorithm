#include <iostream>
#include <algorithm>
using namespace std;

/* define */
#define endl '\n'
/* var */
int N, M;
int arr[200][200];
int psum[200+1][200+1];
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	// getSum
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			psum[i][j] = arr[i - 1][j - 1] + psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];
		}
	}
}
void Solve() {
	int answer = -1e9;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			for (int k = i; k <= N; k++) {
				for (int m = j; m <= M; m++) {
					// (i,j) ~ (k, m) 까지의 다각형 합
					answer = max(answer, psum[k][m] - psum[i - 1][m] - psum[k][j - 1] + psum[i - 1][j - 1]);
				}
			}
		}
	}
	cout << answer << endl;
}
int main() {
	init();
	Solve();
	return 0;
}