#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
#define INF 1'000'000
int N;
vector<int> v;
int dist[100][100];
bool dfs(int cur) {
    vector<bool> visited(N, false);
    // 해당 v가 사이클이 있는지 check
    if (cur == v[cur]) return true;

    int nxt = v[cur];
    while (nxt != cur && !visited[nxt]) {
        visited[nxt] = true;
        nxt = v[nxt];
    }

    return nxt == cur;
}
void Solve() {
    // i 번쨰 Vertex 가 다시 i번쨰 vertex 로 돌아오면 true

    vector<int> answer;
    for (int i = 0; i < N; i++) {
        if (dfs(i)) answer.push_back(i + 1);
    }
    cout << answer.size() << endl;
    for (int w : answer) cout << w << "\n";

    return;
}
int main() {
    cin >> N;
    // set up
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++) dist[i][j] = INF;
    int w;
    for (int i = 0; i < N; i++) {
        cin >> w;
        v.push_back(w - 1);
    }

    Solve();
}