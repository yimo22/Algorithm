#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int N, X;
vector<int> v;

int searching(int* tree, int tmpN, int idx, int size) {
    int l = idx + tmpN;
    int r = l + size - 1;
    int answer = 0;
    while (l <= r) {
        // l 는 우상향 진행
        // l 이 오른쪽 자식일경우, update
        if (l & 1) {
            answer += tree[l];
            l++;
        }
        l >>= 1;

        // r 는 좌상향 진행
        // r이 왼쪽 자식일 경우 update
        if (!(r & 1)) {
            answer += tree[r];
            r--;
        }
        r >>= 1;
    }
    return answer;
}
void Solution() {
    // making idx tree
    int tmpN = pow(2, ceil(log2(N)));
    int tree[2 * tmpN];

    // init
    for (int i = 0; i < 2 * tmpN; i++) tree[i] = 0;
    // insertion
    for (int i = 0; i < v.size(); i++) tree[i + tmpN] = v[i];

    // idxing
    for (int i = tmpN - 1; i > 0; i--) tree[i] = tree[2 * i] + tree[2 * i + 1];

    // answering
    int ans = 0, res;
    map<int, int> mp;
    for (int i = 0; i + X <= v.size(); i++) {
        res = searching(tree, tmpN, i, X);
        mp[res]++;
        ans = max(ans, res);
    }

    if (ans == 0)
        cout << "SAD\n";
    else {
        cout << ans << "\n" << mp[ans] << "\n";
    }

    return;
}
int main() {
    cin >> N >> X;
    int w;
    for (int i = 0; i < N; i++) {
        cin >> w;
        v.push_back(w);
    }

    Solution();

    return 0;
}