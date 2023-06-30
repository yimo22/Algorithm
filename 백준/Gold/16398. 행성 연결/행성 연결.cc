#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

/* define */
#define ll long long
#define endl '\n'
class Edge {
public:
    int s, e;
    int cost;
    Edge(int S, int E, int C) : s(S), e(E), cost(C) {}
};
bool comp(Edge & a, Edge & b) {
    return a.cost < b.cost;
}
/* var */
int N;
int path[1000+1][1000+1];
int parent[1000 + 1];
int getp(int v) {
    if (v == parent[v]) return v;
    else return parent[v] = getp(parent[v]);
}
int uni(int a, int b) {
    int pa = getp(a);
    int pb = getp(b);
    if (pa == pb) return 0;

    if (pa < pb) {
        parent[pb] = pa;
    }
    else parent[pa] = pb;

    return 1;
}
void Solve() {
    // init
    for (int i = 1; i <= N; i++) parent[i] = i;

    vector<Edge> edges;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if(path[i][j] > 0)
                edges.push_back(Edge(i + 1, j + 1, path[i][j]));
        }
    }
    sort(edges.begin(), edges.end(), comp);
    ll answer = 0;
    for (Edge e : edges) {
        if (uni(e.s, e.e)) {
            answer = (answer + e.cost);
        }
    }
    cout << answer << endl;

}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    parent[0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> path[i][j];
        }
    }
}
int main() {
    init();
    Solve();
    return 0;
}