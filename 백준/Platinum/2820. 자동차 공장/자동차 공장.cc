#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

/* define */
#define ll long long
#define endl '\n'
#define MAX 500000
/* var */
int N, M;
vector<int> wage;
vector<int> parent;
vector<int> child[MAX + 1];
int vs[MAX + 1];        // 노드 i에 대하여 최초 진입 시점
int ve[MAX + 1];        // 노드 i에 대하여 최후 진출 시점
int visited[MAX + 1];   // 노드 방문 여부
ll arr[4 * MAX];        // 노드 i에 대하여, 방문 순서에 따른 트리배열
ll dirt[4 * MAX];       // dirty check
int _CNT = 0;           // 시점 변수
vector<pair<int, int>> tmp;

void propagate(int idx, int l, int r) {
    arr[idx] += dirt[idx];
    if (l != r) {
        dirt[2 * idx] += dirt[idx];
        dirt[2 * idx + 1] += dirt[idx];
    }
    dirt[idx] = 0;
}
void update(int idx, int l, int r, int lb, int rb, int value) {
    if (r < lb || rb < l) return;
    if (lb <= l && r <= rb) {
        dirt[idx] += value;
        return;
    }

    int mid = l + (r - l) / 2;
    update(idx * 2, l, mid, lb, rb, value);
    update(idx * 2 + 1, mid + 1, r, lb, rb, value);
}
ll getW(int idx, int l, int r, int pos) {
    propagate(idx, l, r);
    if (pos > r || pos < l) return 0;
    if (l == r) return arr[idx];
    int mid = l + (r - l) / 2;
    return getW(idx * 2, l, mid, pos) + getW(idx * 2 + 1, mid + 1, r, pos);
}
void Solve() {
    while (M-- > 0) {
        char c;
        int a, b;
        cin >> c >> a;
        if (c == 'u') {
            // a의 월급을 출력
            cout << getW(1, 1, N, vs[a]) << endl;
        }
        else if (c == 'p') {
            cin >> b;
            // a의 모든 부하 월급 b만큼 증가
            // vs[a] + 1 ~ ve[a] 의 구간을 b만큼 증가
            update(1, 1, N, vs[a] + 1, ve[a], b);
        }
    }
}
void recur(int cur) {
    vs[cur] = ++_CNT;
    for (int nv : child[cur]) {
        if (visited[nv]) continue;
        visited[nv] = 1;
        recur(nv);
    }
    ve[cur] = _CNT;
}
int makeTree(int idx, int l, int r) {
    if (l == r) {
        arr[idx] = wage[tmp[l - 1].first];
        return 0;
    }
    int mid = l + (r - l) / 2;
    makeTree(idx * 2, l, mid);
    makeTree(idx * 2 + 1, mid + 1, r);
    arr[idx] = arr[idx * 2] + arr[idx * 2 + 1];
    return 0;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    /* INPUT START */
    cin >> N >> M;
    wage.resize(N+1);
    parent.resize(N + 1);
    for (int i = 0; i < N; i++) {
            cin >> wage[i + 1];
            if (i == 0) continue;
            cin >> parent[i + 1];
            child[parent[i + 1]].push_back(i+1);
    }
    parent[1] = 1;
    /* INPUT END */
    
    visited[1] = 1;
    recur(1);
    for (int i = 1; i <= N; i++) {
        tmp.push_back({i, vs[i]});
    }
    sort(tmp.begin(), tmp.end(), [](pair<int, int>& a, pair<int, int>& b) {return a.second < b.second; });
    makeTree(1, 1, N);
}
int main() {
    init();
    Solve();
    return 0;
}