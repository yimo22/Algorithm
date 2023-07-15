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
int N, K;
vector<int> arr;
vector<int> tree;

int getv(int idx, int l, int r, int lb, int rb) {
    if (rb < l || r < lb) return 1;
    if (lb <= l && r <= rb) return tree[idx];

    int mid = l + (r - l) / 2;
    return getv(idx * 2, l, mid, lb, rb) * getv(idx *2+1, mid+1, r, lb, rb);
}
void change(int idx, int l, int r, int pos, int value) {
    if (pos < l || pos > r) return;
    if (l == r && l == pos) {
        tree[idx] = value;
        return;
    }
    int mid = l + (r - l) / 2;
    change(idx * 2, l, mid, pos, value);
    change(idx * 2 + 1, mid + 1, r, pos, value);

    tree[idx] = tree[idx * 2] * tree[idx * 2 + 1];
    return;
}
void build(int idx, int l, int r) {
    // terminal
    if (l == r) {
        int w = arr[l - 1];
        if (w > 0) w = 1;
        else if (w < 0) w = -1;
        else w = 0;
        tree[idx] = w;
        return;
    }
    int mid = l + (r - l) / 2;
    build(idx * 2, l, mid);
    build(idx * 2 + 1, mid + 1, r);
    tree[idx] = tree[idx * 2] * tree[idx * 2 + 1];
    return;
}
void Solve() {
    while (cin >> N >> K) {
        arr.resize(N);
        tree.resize(4 * N);
        for (int i = 0; i < N; i++) cin >> arr[i];
        build(1, 1, N);

        char c;
        int a, b;
        for (int i = 0; i < K; i++) {
            cin >> c >> a >> b;
            if (c == 'C') {
                if (b > 0) b = 1;
                else if (b == 0) b = 0;
                else b = -1;
                change(1, 1, N, a, b);

            }
            else if (c == 'P') {
                int res = getv(1, 1, N, a, b);
                if (res > 0) cout << "+";
                else if (res < 0) cout << "-";
                else cout << "0";
            }
        }
        cout << endl;
    }
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
}
int main() {
    init();
    Solve();
    return 0;
}