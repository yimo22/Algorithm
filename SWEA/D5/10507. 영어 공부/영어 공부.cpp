#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

/* define*/
typedef long long ll;
#define endl '\n'
/* var*/
int N, P;
vector<int> nums;

ll bsc(ll start, ll end) {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		// 시작점은 nums[i] -> 최대 P만큼 써서 가능한 최대 요일 구하기
		int l, r, mid;
		l = i;
		r = N;

		while (l < r && r - l > 1) {
			mid = l + (r-l) / 2;
			int blank = nums[mid] - nums[i] + 1 - (mid - i + 1);
			if (blank <= P) {
				l = mid;
			}
			else r = mid;
		}

		// l 일때 가능한 최대의 일수로 업데이트
		int blank = nums[l] - nums[i] + 1 - (l - i + 1);
		ans = max(ans, nums[l] - nums[i] + 1 + P - blank);
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> N >> P;
		nums.clear();
		for (int i = 0; i < N; i++) {
			int w;
			cin >> w;
			nums.emplace_back(w);
		}
		cout << "#" << (tc + 1) << " ";
		cout << bsc(1, 1'000'000) << '\n';
	}
	return 0;
}