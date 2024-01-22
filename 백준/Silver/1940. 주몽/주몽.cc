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
int N, M;
vector<int> v;
void Solve() {
    sort(v.begin(), v.end());

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        // 시작점은 i
        int need = M - v[i];
        cnt += upper_bound(v.begin() + i + 1, v.end(), need) - lower_bound(v.begin() + i + 1, v.end(), need);
    }
    cout << cnt;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    int w;
    for (int i = 0; i < N; i++) {
        cin >> w;
        v.push_back(w);
    }
}
int main() {
    init();
    Solve();
    return 0;
}