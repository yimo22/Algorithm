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
int mp, mf, ms, mv;
int arr[20][5];
int trace[20];
int ans[20];
int answer = 0x7fffffff;
bool isPromising(int p, int f, int s, int v) {
    if ( (p >= mp) && (f >= mf) && (s >= ms) && (v >= mv)) return true;
    return false;
}
int recur(int pos, int p, int f, int s, int v, int cost) {
    if (isPromising(p, f, s, v)) {
        if (cost < answer) {
            memset(ans, 0, sizeof ans);
            for (int i = 0; i < N; i++) ans[i] = trace[i];
            answer = cost;
        }
        return 0;
    }
    if (pos > N) return 0;
    if (cost >= answer) return 0;

    trace[pos] = 1;
    recur(pos + 1, p + arr[pos][0],
        f + arr[pos][1],
        s + arr[pos][2],
        v + arr[pos][3],
        cost + arr[pos][4]);

    trace[pos] = 0;
    recur(pos + 1,
        p, f, s, v, cost);
    return 0;
}
void Solve() {
    recur(0, 0, 0, 0, 0, 0);
    answer = (answer == 0x7fffffff) ? -1 : answer;
    cout << answer << endl;
    if (answer != -1) {
        for (int i = 0; i < N; i++) {
            if (ans[i] > 0) cout << i + 1 << " ";
        }
    }
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    cin >> mp >> mf >> ms >> mv;
    for (int i = 0; i < N; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
        cin >> arr[i][4];
    }
}
int main() {
    init();
    Solve();
    return 0;
}