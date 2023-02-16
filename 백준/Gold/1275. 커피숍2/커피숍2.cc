#include <algorithm>
#include <cmath>
#include <iostream>
#define endl '\n'
using namespace std;
int tmpN = 0;
int N = 0, Q = 0;
long long* tree;
int* arr;
void update(int a, int b) {
    tree[tmpN + a] = b;
    int cur = tmpN + a;
    cur >>= 1;
    while (cur > 0) {
        tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
        cur >>= 1;
    }
}

long getValue(int a, int b) {
    int l = min(a, b) + tmpN;
    int r = max(a, b) + tmpN;

    long sum = 0;
    while (l <= r) {
        if (l & 1) {
            sum += tree[l];
            l++;
        }
        l >>= 1;

        if (!(r & 1)) {
            sum += tree[r];
            r--;
        }
        r >>= 1;
    }

    return sum;
}

void makeTree() {
    tmpN = pow(2, ceil(log2(N)));
    tree = new long long[2 * tmpN];

    for (int i = 0; i < N; i++) {
        tree[i + tmpN] = arr[i];
    }

    // update
    for (int i = tmpN - 1; i > 0; i--) {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> Q;
    arr = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    makeTree();
    for (int i = 0; i < Q; i++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        cout << getValue(x - 1, y - 1) << endl;
        update(a - 1, b);
    }

    return 0;
}
