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
vector<int> arr;
vector<ll> tree;
vector<ll> dirty;

void propagate(int idx, int l, int r) {
    // non-leaf
    if (l != r) {
        dirty[idx * 2] += dirty[idx];
        dirty[idx * 2 + 1] += dirty[idx];
    }
    tree[idx] += dirty[idx] * (r - l + 1);
    dirty[idx] = 0;
    return;
}
void update(ll value, int lb, int rb, int idx, int l, int r) {
    propagate(idx, l, r);
    // 벗어난 경우
    if (r < lb || rb < l) return;

    // leaf 노드인경우
    if (l == r) {
        tree[idx] += value;
        return;
    }

    // 사이에 쏙 들어가는 경우
    if (lb <= l && r <= rb) {
        int count = r - l + 1;
        tree[idx] += value * count;
        // dirty propagate
        dirty[idx * 2] += value;
        dirty[idx * 2 + 1] += value;
        return; 
    }
    int mid = l + (r - l) / 2;
    update(value, lb, rb, idx * 2, l, mid);
    update(value, lb, rb, idx * 2 + 1, mid + 1, r);
    tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}
ll getValue(int pos, int idx, int l, int r) {
    propagate(idx, l, r);
    // 범위에 들지 않는 경우
    if (pos < l || pos > r) return 0;

    if (l == r) { return tree[idx]; } // leaf

    // non-leaf
    else {
        int mid = l + (r - l) / 2;
        return getValue(pos, idx * 2, l, mid) + getValue(pos, idx * 2 + 1, mid + 1, r);
    }
}
void Solve() {
    cin >> M;
    int a, b, c;
    ll d;
    for (int i = 0; i < M; i++) {
        cin >> a;
        if (a == 1) {
            cin >> b >> c >> d;
            update(d, b, c, 1, 1, N);
        }
        else if (a == 2) {
            cin >> b;
            cout << getValue(b, 1, 1, N) << endl;
        }
        /*for (int j = 0; j < N; j++) cout << getValue(i + 1, 1, 1, N) << " ";
        cout << endl;*/
    }
}
void build(int idx, int l, int r) {
    // terminal
    if (l == r) {
        tree[idx] = arr[l];
        return;
    }

    int mid = l + (r - l) / 2;
    build(idx * 2, l, mid);
    build(idx * 2 + 1, mid + 1, r);

    tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
    return;
}
void makeTree() {
    tree.resize(4 * N);
    dirty.resize(4 * N);
    build(1, 1, N);
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    arr.resize(N+1);
    for (int i = 1; i <= N; i++) cin >> arr[i];
    makeTree();
}
int main() {
    init();
    Solve();
    return 0;
}