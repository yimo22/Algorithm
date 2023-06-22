#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

/* define */
#define ll long long
#define endl '\n'

/* var */
int N, M;
vector<tuple<int, int, int>> query;
vector<int> arr;
vector<int> tree; // 홀수 갯수에 대한 segTree
void build(int idx, int l, int r) {
    if (l == r) {
        tree[idx] = (arr[l-1] & 1);
    }
    else {
        int mid = l + (r - l) / 2;
        build(idx * 2    , l      , mid);
        build(idx * 2 + 1, mid + 1, r);

        tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
    }
}
int getValue(int idx, int l, int r, int lb, int rb) {
    if (rb < l || r < lb) {
        return 0;
    }
    else if (lb <= l && r <= rb) {
        return tree[idx];
    }

    if (l == r) return tree[idx];

    int mid = l + (r - l) / 2;
    int res = getValue(idx * 2, l, mid, lb, rb) + getValue(idx * 2 + 1, mid + 1, r, lb, rb);
    return res;
}
void update(int pos, int value, int idx, int l, int r) {
    if (pos < l || pos > r) return;
    
    if (l == r) {
        tree[idx] = (value & 1);
        return;
    }
    else {
        int mid = l + (r - l) / 2;
        update(pos, value, idx * 2    ,       l, mid);
        update(pos, value, idx * 2 + 1, mid + 1, r);
        tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
    }
}
void makeTree() {
    tree.resize(4 * N);
    build(1, 1, N);
}
void Solve() {
    makeTree();
    
    //while (1) {
    //    int c, l, r;
    //    cin >> c >> l >> r;
    //    if (c == 1) {
    //        arr[l - 1] = r;
    //        update(l, r & 1, 1, 1, N);
    //    }
    //    else if (c == 2) {
    //        cout << (r - l + 1) - getValue(1, 1, N, l, r) << endl;
    //    }
    //    else if (c == 3) {
    //        cout << getValue(1, 1, N, l, r) << endl;
    //    }
    //}
    
    for (auto t : query) {
        int c, l, r;
        tie(c, l, r) = t;
        if (c == 1) {
            arr[l - 1] = r;
            update(l, r & 1, 1, 1, N);
        }
        else if (c == 2) {
            cout << (r- l + 1) - getValue(1, 1, N, l, r) << endl;
        }
        else if (c == 3) {
            cout << getValue(1, 1, N, l, r) << endl;
        }
    }
    
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    cin >> M;
    int c, l, r;
    for (int i = 0; i < M; i++) {
        cin >> c >> l >> r;
        query.push_back({ c, l, r });
    }
}
int main() {
    init();
    Solve();
    return 0;
}
/*
8
1 2 3 4 5 6 7 8
4
3 4 8
1 2 9
1 4 9
3 1 4

*/