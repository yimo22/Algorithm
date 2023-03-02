#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <queue>
using namespace std;
int main() {
	int N, K;
	cin >> N >> K;
	queue<int> q;
	for (int i = 1; i <= N; i++) q.push(i);

	vector<int> answer;
	while (!q.empty()) {
		for (int i = 1; i < K; i++) {
			q.push(q.front());
			q.pop();
		}
		answer.push_back(q.front());
		q.pop();
	}
	cout << "<";
	for (int i = 0; i < N - 1; i++) cout << answer[i] << ", ";
	cout << answer[N - 1] << ">";
	return 0;
}