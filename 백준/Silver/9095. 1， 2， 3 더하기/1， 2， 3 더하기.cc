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
int T, N;
int dp[12];
int recur(int n) {
    if (dp[n] != -1) return dp[n];
    return dp[n] = recur(n - 1) + recur(n - 2) + recur(n - 3);
}
void Solve() {
    memset(dp, -1, sizeof dp);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = dp[2] + dp[1] + 1;
    dp[4] = 7;
    while (T-- > 0) {
        cin >> N;
        cout << recur(N) << endl;
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