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
int T, K, N;
vector<int> arr[4];
void Solve() {
    for (int tc = 0; tc < T; tc++) {
        // input
        cin >> K >> N;
        for (int i = 0; i < 4; i++) {
            arr[i].resize(N);
            for (int j = 0; j < N; j++) cin >> arr[i][j];
        }

        // start
        vector<int> tmp1, tmp2;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                tmp1.push_back(arr[0][i] + arr[1][j]);
                tmp2.push_back(arr[2][i] + arr[3][j]);
            }
        }
        sort(tmp1.begin(), tmp1.end());
        sort(tmp2.begin(), tmp2.end());
        tmp1.erase(unique(tmp1.begin(), tmp1.end()), tmp1.end());
        tmp2.erase(unique(tmp2.begin(), tmp2.end()), tmp2.end());

        // 탐색 시작
        int e = tmp2.size() - 1;
        int diff = 0x7fffffff;
        int ans = 0x7fffffff;
        while (e >= 0) {
            // e의 관점에서 가능한지 check
            int pos = lower_bound(tmp1.begin(), tmp1.end(), K - tmp2[e]) - tmp1.begin();

            int idx;
            if (pos == 0 || pos == tmp1.size()) {
                if (pos == tmp1.size()) pos--;
                int curDiff = abs(K - (tmp1[pos] + tmp2[e]));
                if (diff > curDiff) {
                    diff = curDiff;
                    ans = tmp1[pos] + tmp2[e];
                }
                else if (diff == curDiff) {
                    ans = min(ans, tmp1[pos] + tmp2[e]);
                }
            }
            else {
                int curDiff = abs(K - (tmp1[pos] + tmp2[e]));
                if (diff > curDiff) {
                    diff = curDiff;
                    ans = tmp1[pos] + tmp2[e];
                }
                else if (diff == curDiff) {
                    ans = min(ans, tmp1[pos] + tmp2[e]);
                }
                pos--; 
                curDiff = abs(K - (tmp1[pos] + tmp2[e]));
                if (diff > curDiff) {
                    diff = curDiff;
                    ans = tmp1[pos] + tmp2[e];
                }
                else if (diff == curDiff) {
                    ans = min(ans, tmp1[pos] + tmp2[e]);
                }
            }
            e--;
        }

        cout << ans << endl;
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