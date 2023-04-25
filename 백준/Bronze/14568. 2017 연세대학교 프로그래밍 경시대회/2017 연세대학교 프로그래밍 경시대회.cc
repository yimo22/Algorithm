#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	// 영훈이의 사탕갯수
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		// 남규의 사탕수
		for (int j = i + 2; j <= N; j++) {
			if (i + j >= N) continue;
			int rest = N - (i + j);
			if (rest == 0 || rest&1) continue;
			answer++;
		}
	}
	cout << answer;
	return 0;
}