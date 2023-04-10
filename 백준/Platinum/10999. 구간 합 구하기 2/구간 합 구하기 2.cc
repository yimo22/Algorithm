#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
/* 느리게 갱신되는 segTree */
using namespace std;
/* define*/
#define endl '\n'
#define MAX 1'000'000
#define ll long long
/* var*/
int N, M, K;
int tmpN;
vector<ll> arr(2 * pow(2, ceil(log2(MAX))), 0);
vector<ll> lazy(2 * pow(2, ceil(log2(MAX))), 0); // lazy 
void propagate(int node, int start, int end) {
	if (lazy[node]) {
		arr[node] += (end - start + 1) * lazy[node];
		// 단말 노드가 아니라면
		if (start != end) {
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

/* l : 현재의 범위 시작, r : 현재의 범위 마지막 */
/* lb : 구하고자 하는 범위의 시작, rb : 구하고자 하는 범위의 마지막 */
ll get_interval(int cur, int l, int r, int lb, int rb) {
	propagate(cur, l, r);
	// out of bound
	if (rb < l || lb > r) return 0;
	if (lb <= l && r <= rb) return arr[cur];
	
	int mid = l + (r - l) / 2;
	return get_interval(cur * 2, l, mid, lb, rb) + get_interval(cur * 2 + 1, mid + 1, r, lb, rb);
}
/* l : 현재의 범위 시작, r : 현재의 범위 마지막 */
/* lb : 구하고자 하는 범위의 시작, rb : 구하고자 하는 범위의 마지막 */
void update(int cur, ll value, int l, int r, int lb, int rb) {
	propagate(cur, l, r);
	// out of bound 
	if (r < lb || l > rb) return;
	// 범위에 드는 경우
	if (lb <= l && r <= rb) {
		arr[cur] += (r - l + 1) * value;

		// leaf 노드가 아닌 경우
		if (l != r) {
			lazy[2 * cur] += value;
			lazy[2 * cur + 1] += value;
		}
		return;
	}

	int mid = l + (r - l) / 2;
	update(cur * 2, value, l, mid, lb, rb);
	update(cur * 2 + 1, value, mid + 1, r, lb, rb);
	arr[cur] = arr[cur * 2] + arr[cur * 2 + 1];
}
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> K;
	tmpN = pow(2, ceil(log2(N)));
	for (int i = 0; i < N; i++) {
		cin >> arr[tmpN + i];
	}
	//update - bottom up
	for (int i = tmpN - 1; i >= 1; i--) {
		arr[i] = arr[i * 2] + arr[i * 2 + 1];
	}

	int a;
	ll b, c, d;
	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			/* b번째 수부터 c번째 수에 d를 더하기*/
			cin >> d;
			update(1, d, 1, tmpN, b, c);
		}
		else if (a == 2) {
			/* b번쨰 수부터 c번쨰 수의 합을 출력*/
			cout << get_interval(1, 1, tmpN, b, c) << endl;
		}

	}

}
int main() {
	init();
	return 0;
}