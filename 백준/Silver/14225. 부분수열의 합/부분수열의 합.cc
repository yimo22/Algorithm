#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

int N;
vector<int> v;
vector<int> list;
void search(int pos, int sum) {
	if (pos >= v.size()) return;

	// 포함
	list.push_back(sum + v[pos]);
	search(pos + 1, sum + v[pos]);

	// 포함 x
	search(pos + 1, sum);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++) cin >> v[i];

	search(0, 0);

	// 정렬 & 중복제거
	sort(list.begin(), list.end());
	list.erase(unique(list.begin(), list.end()), list.end());
	
	// 정답 찾기
	int start = 0, value = 1;
	if (list[start] == 0) start++;
	for (value = 1; start < list.size(); start++, value++) {
		if (list[start] != value) {
			break;
		}
	}
	cout << value << endl;
	return 0;
}