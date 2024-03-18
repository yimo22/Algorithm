#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <tuple>
#include <queue>
using namespace std;

/* define */
#define ll long long
#define endl '\n'

/* var */
int N, M, T;
vector<tuple<int,int,int>> adj[50'000];

struct comp{
    bool operator()(pair<int,ll> & a, pair<int,ll> & b){
        return a.second > b.second;
    }
};

/**
 * maxConf 의 불편도 값을 최대로 가질떄,
 * 0 -> N-1 노드까지 T시간내로 가능한지 여부
 * @param maxConf
 * @return
 */
bool possible(int maxConf){
    vector<ll> dist(50'000+1, '7fffffffffffffff');
    priority_queue<pair<int,ll>, vector<pair<int,ll>>, comp> pq; // {현재노드, 걸린시간}

    pq.push({0, 0});
    dist[0] = 0;

    while(!pq.empty()){
        int cur;
        ll time;
        cur = pq.top().first; time = pq.top().second; pq.pop();

        if(time > T || dist[cur] < time ) continue;
        if(cur == N-1) return true;

        for(auto nxt : adj[cur]){
            int nNode = get<0>(nxt);
            ll nTime = time + get<1>(nxt) + max(0, get<2>(nxt) - maxConf);

            if(nTime > T) continue;
            if(dist[nNode] <= nTime) continue;

            dist[nNode] = nTime;
            pq.push({nNode, nTime});
        }

    }
    return false;
}
void Solve() {
    int s, e;
    s = -1;
    e = 1e9;
    while(s < e && (e-s) > 1){
        int mid = s + (e-s) / 2;
        if(possible(mid)){
            e = mid;
        }
        else s = mid;
    }
    int answer = (possible(e)) ? e : -1;
    cout << answer;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef BOJ
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> N >> M >> T;
    int a, b, c, d;
    for(int i=0;i<M;i++){
        cin >> a >> b >> c >> d;
        adj[a-1].push_back({b-1, c, d}); // {도착지, 걸리는 시간, 불편도}
        adj[b-1].push_back({a-1,c,d});
    }


}
int main() {
    init();
    Solve();
    return 0;
}