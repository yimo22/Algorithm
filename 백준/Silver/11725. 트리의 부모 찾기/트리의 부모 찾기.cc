#include "bits/stdc++.h"
#define MAX 100'000
using namespace std;
int N;
int parent[MAX + 1];
vector<int> adj[MAX + 1];
void Solution() {
    // searching
    // init
    queue<int> q;
    vector<bool> vistied(MAX + 1, false);
    for (int node : adj[1]) {
        parent[node] = 1;
        q.push(node);
    }
    vistied[1] = true;
    // start
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (vistied[cur]) continue;
        vistied[cur] = true;
        // printf("cur : %d\n", cur);
        for (int nd : adj[cur]) {
            if (!vistied[nd]) {
                parent[nd] = cur;
                q.push(nd);
            }
        }
    }

    // print out
    for (int i = 2; i <= N; i++) cout << parent[i] << "\n";
}
int main() {
    cin >> N;
    int n1, n2;
    for (int i = 0; i < N - 1; i++) {
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    Solution();
}