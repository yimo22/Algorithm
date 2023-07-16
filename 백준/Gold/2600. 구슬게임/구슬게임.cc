#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

/* define */
#define ll long long
#define endl '\n'
//#define DEBUG 0
/* var */
int dp[2][500+1][500 + 1]; // player, k1 남은수, k2남은수
int b[3];


int recur(int turn, int k1, int k2) {
    if (k1 == 0 && k2 == 0) return dp[turn][k1][k2] = 1 - turn; // 상대방 승리
    if (dp[turn][k1][k2] != -1) return dp[turn][k1][k2];

    // 반드시 자기가 이기는 경우에만 갱신
    // 통1 에서 뺌
    for (int i = 0; i < 3; i++) {
        if (k1 - b[i] >= 0) {
            if (recur(1 - turn, k1 - b[i], k2) == turn) {
                return dp[turn][k1][k2] = turn;
            }
        }
    }
    // 통2 에서 뺌
    for (int i = 0; i < 3; i++) {
        if (k2 - b[i] >= 0) {
            if (recur(1 - turn, k1, k2 - b[i]) == turn) {
                return dp[turn][k1][k2] = turn;
            }
        }
    }
    return dp[turn][k1][k2] = 1 - turn;
}
void Solve() {
    memset(dp, -1, sizeof dp);
    int rep = 5;
    int k[2];
    while (rep-- > 0) {
        cin >> k[0] >> k[1];
        int ans = recur(0, k[0], k[1]);
        if (ans) cout << "B";
        else cout << "A";
        cout << endl;
    }
    
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < 3; i++) cin >> b[i];
}
int main() {
    init();
    Solve();
    return 0;
}