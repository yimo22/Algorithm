#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define endl '\n'
int N;
vector<int> arr;

vector<pair<int,int>> a;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	int w;
	for (int i = 0; i < N; i++) {
		cin >> w;
		arr.push_back(w);
	}
	for (int i = 0; i < N; i++) {
		cin >> w;
		a.push_back({ w, i });
	}

	// 자라는 길이가 작은 나무 순으로 자름
	sort(a.begin(), a.end());

	ll answer = 0;
	for (int i = 0; i < N; i++) {
		answer += arr[a[i].second] + (a[i].first * i);
	}
	cout << answer << endl;

	return 0;
}