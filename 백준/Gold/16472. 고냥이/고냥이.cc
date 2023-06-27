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
string S;
void Solve() {
    int s = 0;
    int e = 1;

    int type['z' + 1];
    memset(type, 0, sizeof type);
    int cnt = 1;
    type[S[s]]++;
    int ans = 0;
    while (s < e && e < S.size()) {
        if (cnt <= N) {
            ans = max(ans, e - s);
            if (type[S[e]] == 0) cnt++;
            type[S[e++]]++;
        }
        else {
            if (type[S[s]] == 1) cnt--;
            type[S[s++]]--;
        }
    }

    while (s < e) {
        if (cnt <= N) {
            ans = max(ans, e - s);
            break;
        }
        else {
            if (type[S[s]] == 1) cnt--;
            type[S[s++]]--;
        }
    }
    cout << ans << endl;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> S;
}
int main() {
    init();
    Solve();
    return 0;
}