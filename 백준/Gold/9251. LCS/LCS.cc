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
string s1, s2;
int dp[1000+1][1000+1];
void Solve() {
    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[s1.size()][s2.size()];
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s1 >> s2;
}
int main() {
    init();
    Solve();
    return 0;
}