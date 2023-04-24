#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
#define endl '\n'
int N, X;
vector<int> arr;
unordered_map<int, int> mp;
void Solve() {
	sort(arr.begin(), arr.end());
	
	int answer = 0;
	for (int i = 0, j = N - 1; i < j;) {
		int sum = arr[i] + arr[j];

		if (sum == X) {
			answer++;
			i++;
		}
		else if (sum < X) {
			i++;
		}
		else {
			j--;
		}
	}
	cout << answer << endl;
}
void init() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	int w;
	for (int i = 0; i < N; i++) {
		cin >> w;
		arr.push_back(w);
	}
	cin >> X;
}
int main() {
	init();
	Solve();
	return 0;
}