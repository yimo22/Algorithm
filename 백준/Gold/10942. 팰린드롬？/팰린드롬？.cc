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
int dp[2000+1][2000+1];
int recur(int s, int e) {
    if (s == e) return dp[s][e] = 1;
    if (s > e) return 0;
    if (s + 1 == e) {
        return dp[s][e] = (arr[s-1] == arr[e-1]);
    }
    if (dp[s][e] != -1) return dp[s][e];

    
    if (arr[s-1] == arr[e-1]) {
        return dp[s][e] = recur(s + 1, e - 1);
    }
    else return dp[s][e] = 0;
}
void Solve() {
    memset(dp, -1, sizeof dp);
    cin >> M;
    int s, e;
    while (M-- > 0) {
        cin >> s >> e;
        cout << recur(s, e) << endl;
    }
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