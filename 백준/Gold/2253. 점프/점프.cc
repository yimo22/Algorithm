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
int N, M;
vector<int> arr;
int ans = '????';
int dp[10000+1][150];
bool possible[10000 + 1];
/*
    pos : 현재 위치
    prev : 전턴에 점프한 거리
    @return : N까지의 도약 횟수
*/
int recur(int pos, int prev) {
    if (pos == N) return 0;
    if (pos > N || possible[pos]) return -1;
    if (dp[pos][prev] != -1) return dp[pos][prev];


    int result = '????';
    for (int i = prev - 1; i <= prev + 1; i++) {
        if (i < 1) continue;

        int res = recur(pos + i, i);
        if (res != -1) result = min(result, res);
    }

    if (result == '????') return dp[pos][prev] = -1;
    return dp[pos][prev] = result + 1;
}
void Solve() {
    memset(dp, -1, sizeof dp);
    ans = recur(2, 1);
    if (ans != -1)
        cout << ans + 1;
    else cout << ans;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    arr.resize(M);
    for (int i = 0; i < M; i++) {
        int w;
        cin >> w;
        possible[w] = true;
    }
}
int main() {
    init();
    Solve();
    return 0;
}