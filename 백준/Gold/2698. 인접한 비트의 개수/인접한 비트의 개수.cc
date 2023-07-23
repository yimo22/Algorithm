#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

/* define */
#define ll long long
#define endl '\n'

/* var */
int T;
int N, K;
int dp[100+1][100+1][2]; // 길이i, 비트수 j, 처음 비트 k 인 수열의 경우의수
// 길이 N, 인접비트수 K, 시작비트 begin
int recur(int n, int k, int begin) {
    if (dp[n][k][begin] != -1) return dp[n][k][begin];
    if (k < 0 || n < 0) return 0;
    if (n < k + 1) return 0;

    if (begin == 0) return dp[n][k][begin] = recur(n - 1, k, 1) + recur(n - 1, k, 0);
    else return dp[n][k][begin] = recur(n - 1, k - 1, 1) + recur(n - 1, k, 0);
}
void Solve() {
    memset(dp, -1, sizeof dp);
    for (int i = 1; i <= 100; i++) {
        dp[1][i][0] = dp[1][i][1] = 0;
    }
    dp[1][0][1] = 1;
    dp[1][0][0] = 1;

    while (T-- > 0) {
        cin >> N >> K;
        cout << recur(N, K, 0) + recur(N, K, 1) << endl;
    }
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
}
int main() {
    init();
    Solve();
    return 0;
}