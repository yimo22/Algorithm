#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

/* define */
#define ll long long
#define endl '\n'
#define MODULO 1000000000
/* var */
int N;
int dp[100+1][10][1<<10];
// 길이 n, 맨 뒤의 수 cur, 사용한 숫자기록 used
int recur(int n, int cur, int used) {
    if (n == N) {
        return used == (1 << 10) - 1 ? 1 : 0;
    }
    int& w = dp[n][cur][used];
    if (w != -1) {
        return w;
    }

    w = 0;
    if (cur + 1 <= 9) {
        w = (w + recur(n + 1, cur + 1, used | (1 << cur + 1))) % MODULO;
    }
    if (cur - 1 >= 0) {
        w = (w + recur(n + 1, cur - 1, used | (1 << cur - 1))) % MODULO;
    }
    return w;
}
int Solve() {
    int ans = 0;
    for (int i = 1; i <= 9; i++) {
        ans = (ans + recur(1, i, 1 << i)) % MODULO;
    }
    cout << ans << endl;
    return ans;
}
int arr[11];
void recur2(int pos, int used) {
    if (pos == 11) {
        if (used == (1 << 10) - 1) {
            for (int i = 0; i < 11; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    if (pos == 0) {
        for (int i = 1; i <= 9; i++) {
            arr[pos] = i;
            recur2(pos + 1, used | (1 << i));
        }
        return;
    }

    int prev = arr[pos - 1];
    if (prev + 1 <= 9) {
        arr[pos] = prev + 1;
        recur2(pos + 1, used | (1 << prev + 1));
    }
    
    if (prev - 1 >= 0) {
        arr[pos] = prev - 1;
        recur2(pos + 1, used | (1 << prev - 1));
    }
}
void Test() {
    recur2(0, 0);
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    memset(dp, -1, sizeof dp);
}
int main() {
    init();
    //Test();
    Solve();
    return 0;
}