#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

/* define */
#define ll long long
#define endl '\n'
#define MAX 100000
/* var */
int T, N;
vector<int> parent;
vector<int> depth;
vector<int> children[100000 + 1];
vector<int> order;
int ac[MAX+1][20];  // i의 2^j 번쨰 조상은 ac[i][j]

int lca(int a, int b) {
    int answer = 0;
    if (depth[a] > depth[b]) swap(a, b); // depth가 작은놈을 a로 고정

    // 같은 depth까지 맞춤
    int diff = depth[b] - depth[a];
    answer += diff;
    for (int i = 0;diff > 0; i++) {
        if (diff & 1) {
            b = ac[b][i];
        }
        diff >>= 1;
    }

    // 같이 뛰면서 find
    if (a != b) {
        // 둘의 공통 조상이 차이가 1만큼 날때까지 올림
        for (int k = 18; k >= 0; k--) {
            if (ac[a][k] > 0 && (ac[a][k] != ac[b][k])) {
                a = ac[a][k];
                b = ac[b][k];
                answer += 2 * pow(2, k);
            }
        }

        // 마지막으로 한칸씩 올림
        answer += 2;
    }

    return answer;
}

void init() {
    cin >> N;
    parent.resize(N+1);
    depth.resize(N + 1);
    if(!order.empty()) order.clear();
    memset(ac, 0, sizeof ac);
    for (int i = 1; i <= N; i++) children[i].clear();


    parent[1] = 1;
    for (int i = 2; i <= N; i++) {
        cin >> parent[i];
        children[parent[i]].push_back(i);
    }

    // 전처리
    queue<int> q;
    vector<int> visited(N + 1, 0);
    depth[1] = 0;
    visited[1] = 1;
    q.push(1);

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        
        for (int nv : children[cur]) {
            if (visited[nv]) continue;

            visited[nv] = 1;
            depth[nv] = depth[cur] + 1;
            ac[nv][0] = cur;
            q.push(nv);
            order.push_back(nv);
        }
    }
    int maxK = (int) ceil(log2(N) - 1);
    // ac dp 완성
    for (int k = 0; k <= maxK; k++) {
        for (int i = 1; i <= N; i++) {
            if (ac[i][k] > 0) {
                ac[i][k + 1] = ac[ac[i][k]][k];
            }
        }
    }

}
void Solve() {
    cin >> T;
    // N : 1<= <= 100K

    for(int tc=0; tc<T; tc++){
        init();
        // BFS 의 거리
        // -> LCA
        ll answer = 0;
        int prev = 1;
        for (int i = 0; i < order.size(); i++) {
            int value = lca(prev, order[i]);
            answer += value;
            prev = order[i];
        }

        cout << "#" << tc + 1 << " " << answer << endl;
    }
}
int main(int argc, char ** argv) {
    Solve();
    return 0;
}
