#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

/* define */
#define ll long long
#define endl '\n'

/* var */
int N, M;
vector<int> adj[10000+1];
void Solve() {

    vector<int> answerList;
    int answer = 0;
    for (int i = 1; i <= N; i++) {
        queue<int> q;
        vector<int> visited(N + 1, 0);
        q.push(i);
        int cnt = 1;
        visited[i] = 1;
        while (!q.empty()) {
            int cur = q.front(); q.pop();

            for (int nv : adj[cur]) {
                if (!visited[nv]) {
                    visited[nv] = 1;
                    cnt++;
                    q.push(nv);
                }
            }
        }

        if (answer == cnt) {
            answerList.push_back(i);
        }
        else if (answer < cnt) {
            answer = cnt;
            answerList.clear();
            answerList.push_back(i);
        }
    }

    for (int w : answerList) cout << w << " ";
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;
        adj[e].push_back(s);
    }
}
int main() {
    init();
    Solve();
    return 0;
}