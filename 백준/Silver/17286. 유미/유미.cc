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

/* var */
int sx, sy;
pair<int, int> arr[3];
int selected[3];
int answer = '????';
double getDist(pair<int, int> a, pair<int, int> b) {
    return sqrt(pow((a.first - b.first), 2) + pow((a.second - b.second), 2));
}
int recur(int n, int used) {
    if (n == 3) {
        double total = 0;
        int x = sx, y = sy;
        for (int i = 0; i < 3; i++) {
            pair<int, int>& dest = arr[selected[i]];
            total += getDist({x, y}, arr[selected[i]]);
            x = dest.first;
            y = dest.second;
        }
        answer = min(answer, (int) total);
        return 0;
    }

    for (int i = 0; i < 3; i++) {
        if (used & (1 << i)) continue;
        selected[n] = i;
        recur(n + 1, used | (1 << i));
    }
    return 0;
}
void Solve() {
    // 완탐
    // 3!
    recur(0, 0);
    cout << answer;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> sx >> sy;
    for (int i = 0; i < 3; i++) cin >> arr[i].first >> arr[i].second;
}
int main() {
    init();
    Solve();
    return 0;
}