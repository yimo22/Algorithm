#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

/* define */
#define ll long long
#define endl '\n'
#define MOD 10007
/* var */
int N;
int dp[1000 + 1];
int recur(int n) {
    if (dp[n] != -1) return dp[n];
    // 1 by 2
    dp[n] = 0;
    dp[n] = (dp[n] + recur(n - 1)) % MOD;
    // 2 by 1
    dp[n] = (dp[n] + recur(n - 2)) % MOD;
    return dp[n];
}
void Solve() {
    memset(dp, -1, sizeof dp);
    dp[1] = 1;
    dp[2] = 2;
    cout << recur(N);
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
}
int main() {
    init();
    Solve();
    return 0;
}