#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* define */

/* var */
int A, B, C;
vector<int> arr, brr, crr;
int answer = 0x7fffffff;

void search_ary(vector<int> & a, vector<int> & b, vector<int> & c) {
	// a와 b배열에서 결정
	for (int i = 0; i < a.size(); i++) {
		int wa = a[i];
		for (int j = 0; j < b.size(); j++) {
			int wb = b[j];
			int pos = lower_bound(c.begin(), c.end(), min(wa, wb)) - c.begin();

			if (pos == c.size()) pos--;

			if (min(wa, wb) <= c[pos] && (c[pos] <= max(wa, wb))) {
				answer = min(answer, abs(max(wa, wb) - min(wa, wb)));
			}
		}
	}
}
void Solve() {
	sort(arr.begin(), arr.end());
	sort(brr.begin(), brr.end());
	sort(crr.begin(), crr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	brr.erase(unique(brr.begin(), brr.end()), brr.end());
	crr.erase(unique(crr.begin(), crr.end()), crr.end());

	// A, B 에서 결정하는 경우
	search_ary(arr, brr, crr);
	// A, C 에서 결정하는 경우
	search_ary(arr, crr, brr);
	// B, C 에서 결정하는 경우
	search_ary(brr, crr, arr);
	cout << answer << endl;
}
void init() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> A >> B >> C;
	arr.resize(A);
	brr.resize(B);
	crr.resize(C);
	for (int i = 0; i < A; i++) cin >> arr[i];
	for (int i = 0; i < B; i++) cin >> brr[i];
	for (int i = 0; i < C; i++) cin >> crr[i];
}
int main() {
	init();
	Solve();
	return 0;
}