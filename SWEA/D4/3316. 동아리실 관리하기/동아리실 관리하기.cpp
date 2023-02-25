#include <iostream>
#include <algorithm>
#include <string>
#define MOD 1'000'000'007
using namespace std;

int dp[10'000+1][1<<4]; // [날짜][참여자]
int Solve(string s) {
	int n = s.size();


	//init
	for (int i = 1; i <= n; i++) fill_n(dp[i], 1 << 4, 0);

	int bt = s[0] - 'A';
	for (int i = 0; i < (1 << 4); i++) {
		// A와 첫 당직자 비트가 켜저있는 경우 1
		if ((i & (1 << bt)) && (i & 1)) dp[1][i] = 1;
	}

	// start
	for (int i = 2; i <= n; i++) { // 일수 
		int Nbit = (s[i - 1] - 'A');
		for (int j = 0; j < (1 << 4); j++) { // 오늘 동아리 참여자
			if (j & (1 << Nbit)) { // 오늘 날짜의 당직자가 포함된경우
				for (int k = 0; k < (1 << 4); k++) {
					if (k & j) { // 이전 날짜의 참여자에 현재 참여자가 한명이라도 있는 경우
						dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
					}
				}

			}
		}
	}

	// answer
	int answer = 0;
	for (int i = 0; i < (1 << 4); i++) {
		answer = (answer + dp[n][i]) % MOD;
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);


	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		string s;
		cin >> s;
		cout << "#" << i + 1 << " ";
		cout << Solve(s) << '\n';
	}

	return 0;
}