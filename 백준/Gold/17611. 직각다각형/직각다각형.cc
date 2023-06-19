#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/* define */
#define ll long long
#define endl '\n'
#define MAX 1'000'000
#define INDENT 500'000
/* var */
int N;
vector<pair<int, int>> list;
int hpsum[MAX + 2]; // horizontal prefix sum
int vpsum[MAX + 2]; // vertical prefix sum
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    int s, e;
    for (int i = 0; i < N; i++) {
        cin >> s >> e;
        list.push_back({ s, e });
    }
}
void Solve() {
    // make Vertical, Horizontal Set
    for (int i = 0; i < list.size(); i++) {
        auto cur = list[i];
        auto nxt = list[(i + 1) % N];
        // 상하 이동 
        if (nxt.first == cur.first) {
            vpsum[min(nxt.second, cur.second) + INDENT]++;
            vpsum[max(nxt.second, cur.second) + INDENT]--;
        }
        else {
            hpsum[min(nxt.first, cur.first) + INDENT]++;
            hpsum[max(nxt.first, cur.first) + INDENT]--;
        }
    }
    for (int i = 1; i <= MAX; i++) {
        vpsum[i] += vpsum[i - 1];
        hpsum[i] += hpsum[i - 1];
    }
    cout << max(*max_element(vpsum, vpsum + MAX+1), *max_element(hpsum, hpsum + MAX + 1)) << endl;
}
int main() {
    init();
    Solve();
    return 0;
}