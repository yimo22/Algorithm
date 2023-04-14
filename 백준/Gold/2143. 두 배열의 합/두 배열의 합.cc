#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

/* define */
#define endl '\n'
#define ll long long

int N, T, M;
int arr[1000+1];
int brr[1000 + 1];
int apsum[1000 + 1];
int bpsum[1000 + 1];
map<ll, ll> A, B; // {합, 갯수}
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	cin >> M;
	for (int i = 0; i < M; i++) cin >> brr[i];

	// get prefix
	for (int i = 1; i <= N; i++) {
		apsum[i] = apsum[i - 1] + arr[i - 1];
	}
	for (int i = 1; i <= M; i++) {
		bpsum[i] = bpsum[i - 1] + brr[i - 1];
	}

	// 부분배열합
	
	for (int i = 1; i <= N; i++) {
		for(int j=1; j<=i; j++){
			A[apsum[i] - apsum[j - 1]]++;
		}
	}
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= i; j++) {
			B[bpsum[i] - bpsum[j - 1]]++;
		}
	}
	
	// A를 기점으로,  B를 이분탐색
	ll ans = 0;
	for (auto iter = A.begin(); iter != A.end(); iter++) {
		auto res = B.lower_bound((ll)T - iter->first);
		if (res != B.end() && (res->first + iter->first) == T) {
			ans += res->second * iter->second;
		}

	}

	cout << ans << endl;
}
int main() {
	init();

	return 0;
}