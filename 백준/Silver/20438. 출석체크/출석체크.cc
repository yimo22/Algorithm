#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
/* define */
#define endl '\n'
/* var */
int N, K, Q, M;
vector<int> slept, recv;
vector<pair<int,int>> list;
int visited[5000+123];
int psum[5000+123];
int recur(int v){
    for(int i : slept) if(i == v) return 0;
    visited[v] = 1;
    for(int nv= v + v; nv <= N+2; nv += v) recur(nv);
    return 0;
}
void Solve() {
    for(int cur : recv) recur(cur);
    for(int i=3;i<=N+2;i++) psum[i] = psum[i-1] + visited[i];
    for(pair<int,int> pos : list) cout << pos.second - pos.first + 1 - (psum[pos.second] - psum[pos.first - 1]) << endl;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef BOJ
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> N >> K >> Q >> M;
    slept.resize(K);
    recv.resize(Q);
    list.resize(M);
    for(int i=0;i<K;i++) cin >> slept[i];
    for(int i=0;i<Q;i++) cin >> recv[i];
    for(int i=0;i<M;i++) cin >> list[i].first >> list[i].second;
}
int main() {
    init();
    Solve();
    return 0;
}