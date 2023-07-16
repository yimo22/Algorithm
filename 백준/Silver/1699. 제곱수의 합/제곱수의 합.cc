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
int dp[100000];
int recur(int n){
    if (n == 0) return 0;
    if (dp[n] != -1) return dp[n];

    dp[n] = '????';
    for (int i = 1; n - i * i >= 0; i++) {
        dp[n] = min(dp[n], recur(n - i * i) + 1);
    }
    return dp[n];
}
void Solve() {
    memset(dp, -1, sizeof dp);
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