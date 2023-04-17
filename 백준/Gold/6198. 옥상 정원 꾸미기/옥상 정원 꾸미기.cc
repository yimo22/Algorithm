#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
/* define*/
#define ll long long
int N;
vector<int> arr;

void Solve() {
	stack<int> stk;
	ll answer = 0;
	for (int i = 0; i < arr.size(); i++) {
		// 내림차순 유지
		// Monotone stack
		while (!stk.empty() && stk.top() <= arr[i]) stk.pop();
		stk.push(arr[i]);
		answer += (stk.size() - 1);
	}
	cout << answer;
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
}
int main() {
	init();
	Solve();
	return 0;
}