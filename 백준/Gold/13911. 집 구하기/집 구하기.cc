#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <unordered_set>
#include <queue>
using namespace std;

/* define */
#define ll long long
#define endl '\n'
#define MAX_VAL 0x7fffffffffffffff
/* var */
int V, E;
int M, X, S, Y;
vector<vector<pair<int,int>>> adj;
unordered_set<int> macs, stars;
vector<ll> macs_dist;
vector<ll> stars_dist;

struct comp{
    bool operator()(pair<int,ll> & a, pair<int,ll> & b){
        return a.second > b.second;
    }
};

void dijkstra(int start, int size, vector<ll> & dist){
    priority_queue<pair<int,ll> , vector<pair<int, ll>>, comp> pq;    // {노드, 거리}

    dist[start] = 0;
    pq.push({start, 0});

    while(!pq.empty()){
        int cur; ll distance;
        cur = pq.top().first; distance = pq.top().second; pq.pop();

        if(dist[cur] < distance) continue;

        for(auto nxt: adj[cur]){
            int next = nxt.first;
            ll nDistance = distance + nxt.second;

            if(dist[next] <= nDistance) continue;

            dist[next] = nDistance;
            pq.push({next, nDistance});
        }
    }

}
void Solve() {
    // 0번노드 가상의 macs로 셋팅
    for(auto iter = macs.begin(); iter != macs.end(); iter++) {
        int node = *iter;
        adj[node].push_back({0, 0});
        adj[0].push_back({node, 0});
    }
    macs_dist.resize(V+1, 0x7fffffffffffffff);
    dijkstra(0, V, macs_dist);



    // 0번노드 가상의 stars로 셋팅
    adj[0].clear();
    for(auto iter = macs.begin(); iter != macs.end(); iter++) {
        int node = *iter;
        adj[node].pop_back();
    }
    for(auto iter = stars.begin(); iter != stars.end(); iter++) {
        int node = *iter;
        adj[node].push_back({0, 0});
        adj[0].push_back({node, 0});
    }
    stars_dist.resize(V+1, 0x7fffffffffffffff);
    dijkstra(0, V, stars_dist);


    // 정답 찾기
    ll answer = MAX_VAL;
    for(int i=1;i<=V;i++){
        if(macs.find(i) != macs.end() || stars.find(i) != stars.end()) continue;
        if(macs_dist[i] == MAX_VAL || stars_dist[i] == MAX_VAL) continue;
        if(macs_dist[i] > X || stars_dist[i] > Y) continue;
        answer = min(answer, macs_dist[i] + stars_dist[i]);
    }

    answer = (answer == MAX_VAL) ? -1 : answer;
    cout << answer << endl;

    return;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef BOJ
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> V >> E;
    adj.resize(V+1);


    // 0번 노드 : 가상노드
    // 1~N : 각 노드
    int u, v, w;
    for(int i=0;i<E;i++){
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    cin >> M >> X;
    int node;
    for(int i=0;i<M;i++){
        cin >> node;
        macs.insert(node);
    }

    cin >> S >> Y;
    for(int i=0;i<S;i++){
        cin >> node;
        stars.insert(node);
    }
}
int main() {
    init();
    Solve();
    return 0;
}