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
int T, K;
int arr[500 + 1];
int dp[500+1][500 + 1];
int psum[500 + 1];
vector<pair<int, int>> trace;
// s ~ e 까지 최소비용
int recur(int s, int e) {
    if (dp[s][e] != -1) return dp[s][e];
    if (s == e) return dp[s][e] = 0;
    if ((e - s) == 1) return dp[s][e] = arr[s] + arr[e];

    int& w = dp[s][e];
    w = '????';
    for(int mid = s; mid < e; mid++){
        w = min(w, recur(s, mid) + recur(mid + 1, e));
    }
    return w += psum[e] - psum[s - 1];
}
void Solve() {
    while (T-- > 0) {
        cin >> K;
        for (int i = 1; i <= K; i++) {
            cin >> arr[i];
            psum[i] = psum[i - 1] + arr[i];
        }
        memset(dp, -1, sizeof dp);
        cout << recur(1, K) << endl;
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