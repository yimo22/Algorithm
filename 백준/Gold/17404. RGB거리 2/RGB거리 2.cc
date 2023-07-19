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
int N;
int arr[1000 + 1][3];
int dp[1000 + 1][3];
int recur(int n, int color, int first) {
    if (n == 1) {
        if (first == color) return 987654321;
        else return arr[n][color];
    }
    if (dp[n][color]) return dp[n][color];
    dp[n][0] = min(recur(n - 1, 1, first), recur(n - 1, 2, first)) + arr[n][0];
    dp[n][1] = min(recur(n - 1, 0, first), recur(n - 1, 2, first)) + arr[n][1];
    dp[n][2] = min(recur(n - 1, 0, first), recur(n - 1, 1, first)) + arr[n][2];
    return dp[n][color];
}
void Solve() {
    int ans = '????';
    for (int i = 0; i < 3; i++) {
        memset(dp, 0, sizeof dp);
        ans = min(ans, recur(N, i, i));
    }
    cout << ans;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
}
int main() {
    init();
    Solve();
    return 0;
}