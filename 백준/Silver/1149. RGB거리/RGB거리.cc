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
int a[1000+1][3];
int dp[1000+1][3]; // i번째집 j로 칠하는 최소비용
int recur(int n, int c) {
    if (dp[n][c] != -1) return dp[n][c];


    if (c == 0) 
        return dp[n][c] = min(recur(n + 1, 1), recur(n + 1, 2)) + a[n][c];
    else if (c == 1) 
        return dp[n][c] = min(recur(n + 1, 0), recur(n + 1, 2)) + a[n][c];
    else 
        return dp[n][c] = min(recur(n + 1, 0), recur(n + 1, 1)) + a[n][c];
}
void Solve() {
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < 3; i++) dp[N][i] = a[N][i];
    cout << min({ recur(1, 0), recur(1, 1), recur(1, 2) });
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
}
int main() {
    init();
    Solve();
    return 0;
}