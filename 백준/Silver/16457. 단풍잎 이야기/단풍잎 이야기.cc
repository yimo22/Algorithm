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
int arr[100];
int n, m, k;
int ans;
int recur(int depth, int cnt, int selected) {
    if (cnt >= n) {
        // 전부 뽑은 경우
        int _cnt = 0;
        for (int i = 0; i < m; i++) {
            if ((arr[i] & selected) == arr[i]) _cnt++;
        }

        ans = max(ans, _cnt);
        return 0;
    }
    if (depth >= 2 * n) return 0; // 뽑을 수 없는 경우


    // (depth+1) 을 사용 하는경우
    recur(depth + 1, cnt + 1, selected | (1 << depth));

    // (depth+1) 을 사용 안하는 경우
    recur(depth + 1, cnt, selected );
    return 0;
}
void Solve() {
    // 1~2n 까지의 정수중 n개를 뽑음
    // m개의 퀘스트에 대하여 탐색
    recur(0, 0, 0);

    cout << ans;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int w;
        for (int j = 0; j < k; j++) {
            cin >> w;
            arr[i]  |= (1 << (w - 1));
        }
    }
}
int main() {
    init();
    Solve();
    return 0;
}