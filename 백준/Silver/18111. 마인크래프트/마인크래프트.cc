#include "bits/stdc++.h"

using namespace std;
#define MAX 500
int N, M, B;
vector<vector<int>> mapping(MAX, vector<int>(MAX, 0));
void Solution() {
    // brute force
    int answer = numeric_limits<int>::max();
    int h = -1;
    for (int height = 0; height <= 256; height++) {
        // calc with current height
        int dig = 0, stacking = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (height >= mapping[i][j]) {
                    // stacking!
                    stacking += (height - mapping[i][j]);
                } else {
                    dig += (mapping[i][j] - height);
                }
            }
        }
        if (B + dig < stacking) continue;
        int time = 2 * dig + stacking;
        // printf(" %d : %d %d witih %d\n", height, dig, stacking, time);
        if (answer > time) {
            answer = time;
            h = height;
        } else if (answer == time) {
            h = max(h, height);
        }
    }
    cout << answer << " " << h;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> B;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> mapping[i][j];
        }
    }
    Solution();
    return 0;
}