#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



int N, M;
vector<int> arr(8, 0);
int selected[8];
int perm(int pos, int visited) {
	if (pos >= M) {

		for (int i = 0; i < M; i++) {
			cout << selected[i] << " ";
		}
		cout << endl;

		return 0;
	}

	for (int i = 0; i < N; i++) {
		if (visited & (1 << i)) continue;

		if (pos == 0) {
			selected[pos] = arr[i];
			perm(pos + 1, visited | (1 << i));
		}
		else {
			if (selected[pos - 1] < arr[i]) {
				selected[pos] = arr[i];
				perm(pos + 1, visited | (1 << i));
			}
		}
	}
	return 0;
}
void Solve() {
	sort(arr.begin(), arr.begin() + N);
	perm(0, 0);
	return;
}
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}
int main() {
	init();
	Solve();
	return 0;
}