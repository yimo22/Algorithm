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
int dp[1000+1][2]; // [i]: i개 돌 일때 j턴의 결과  / 0(SK), 1(CY) -1(미정)
int recur(int n, int t) {
    if (n < 0) return -1;
    if (dp[n][t%2] != -1) return dp[n][t%2];
    if (n == 0 || n == 2) return (1 - (t%2));
    int cur = t % 2;

    int r1 = recur(n - 1, t + 1);
    if (r1 != -1 && (r1 == cur)) {
        return dp[n][t%2] = cur;
    }

    int r2 = recur(n - 3, t + 1);
    if (r2 != -1 && (r2 == cur)) {
        return dp[n][t%2] = cur;
    }

    int r3 = recur(n - 4, t + 1);
    if (r3 != -1 && (r3 == cur)) {
        return dp[n][t%2] = cur;
    }
    return dp[n][t%2] = 1 - cur;
}
void Solve() {
    memset(dp, -1, sizeof dp);
    int ans = recur(N, 0);


    if (ans == 0) cout << "SK";
    else cout << "CY";

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