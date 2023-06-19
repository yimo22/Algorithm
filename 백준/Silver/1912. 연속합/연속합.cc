#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/* define */
#define ll long long
#define endl '\n'

/* var */
int N;
int arr[100'000+1];
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
}
void Solve() {
    int dp[100'000+1];
    int maxValue = arr[0];
    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        // 연속 하는 경우 vs 연속하지 않는 경우
        dp[i] = max(dp[i-1] + arr[i-1], arr[i-1]);
        maxValue = max(maxValue, dp[i]);
    }
    cout << maxValue << endl;
}
int main() {
    init();
    Solve();
    return 0;
}