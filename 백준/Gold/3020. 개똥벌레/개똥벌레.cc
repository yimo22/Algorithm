#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/* define */
#define ll long long
#define endl '\n'
/* var */
int N, H;
vector<int> v;
vector<ll> prefix;
void init() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> N >> H;
	
	v.resize(H+2);
	for (int i = 0; i < N; i++) {
		int h;
		cin >> h;
		if (i & 1) {
			v[H-h+1] += 1;
			v[H + 1] += -1;
		}
		else {
			v[1] += 1;
			v[h + 1] += -1;
		}
	}
	// get Sum
	prefix.resize(H + 1);
	prefix[0] = 0;
	for (int i = 1; i <= H; i++) {
		prefix[i] = prefix[i - 1] + v[i];
	}
	int minCount = * min_element(prefix.begin() + 1, prefix.end());
	int ans = 0;
	for (int i = 1; i <= H; i++) if (prefix[i] == minCount) ans++;

	cout << minCount << " " << ans << endl;

}
int main() {
	init();
	return 0;
}