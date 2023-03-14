#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
using namespace std;
/* define*/
/* var*/
int N, M, tmpN;
long long * tree;
long long getSum(int a, int b) {
	int l = tmpN + a;
	int r = tmpN + b;
	if (r < l) swap(l, r);

	long long sum = 0;
	while (l <= r) {
		if (l & 1) {
			sum += tree[l];
			l++;
		}
		l >>= 1;

		if (!(r & 1)) {
			sum += tree[r];
			r--;
		}
		r >>= 1;
	}
	return sum;
}
void update(int k, int b) {
	int pos = k + tmpN;
	tree[pos] = b;

	pos >>= 1;

	while (pos > 0) {
		tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
		pos >>= 1;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	tmpN = pow(2, ceil(log2(N)));
	tree = new long long[2 * tmpN];
	fill_n(tree, 2 * tmpN, 0);
	for (int i = 0; i < M; i++) {
		int comm, a, b;
		cin >> comm >> a >> b;
		if (comm == 0) {
			// sum
			cout << getSum(a-1, b-1) << '\n';
		}
		else {
			update(a - 1, b);
		}
	}
	return 0;
}