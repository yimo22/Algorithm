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
vector<int> arr;
int N;
int dp[5000+1][5000+1];
int recur(int s, int e) {
    if (s >= e) return 0;
    if (dp[s][e] != -1) return dp[s][e];

    int w = 0;
    if (arr[s] == arr[e]) {
        w = recur(s + 1, e - 1);
    }
    else {
        w = min(recur(s + 1, e),
            recur(s, e - 1));
        w++;
    }
    return dp[s][e] = w;
}
void Solve() {
    memset(dp, -1, sizeof dp);
    cout << recur(0, N - 1);
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
}
int main() {
    init();
    Solve();
    return 0;
}