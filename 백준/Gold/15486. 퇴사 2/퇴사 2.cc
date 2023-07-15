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
int arr[1500000+1][2];
int dp[1500000 + 1]; // [i] : i일 ~ N일까지 일을 할때 최대수익
int recur(int pos) {
    if (pos > N) return -9999999999; // 불가
    if (pos == N) return 0;
    if (dp[pos] != -1) return dp[pos];
    return dp[pos] = max(recur(pos + arr[pos][0]) + arr[pos][1], recur(pos + 1));
}
void Solve() {
    memset(dp, -1, sizeof dp);
    cout << recur(0);
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i][0] >> arr[i][1];
}
int main() {
    init();
    Solve();
    return 0;
}