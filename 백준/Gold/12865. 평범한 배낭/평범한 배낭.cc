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
int N, K;
int a[100][2];          // 무게, 가치
int dp[100+1][100000+1]; // [i][j] : i번째까지의 아이템, 무게 j , 최대가치
void Solve() {
    // 무게한도내 가치 최대
    for (int i = 0; i < N; i++) {
        // i번째 물건에 대하여 탐색
        int w = a[i][0];
        int v = a[i][1];
        for (int j = 1; j <= K; j++) {
            dp[i+1][j] = dp[i][j];
            // use or not
            if(j - w >= 0) 
                dp[i+1][j] = max(dp[i][j], dp[i][j - w] + v);
        }
    }
    cout << dp[N][K];
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> a[i][0] >> a[i][1];
}
int main() {
    init();
    Solve();
    return 0;
}