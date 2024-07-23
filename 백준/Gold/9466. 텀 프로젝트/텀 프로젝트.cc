#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

/* define */
#define ll long long
#define endl '\n'

/* var */
int N, T;
int arr[100'000];
int _IDX = 0;
int visited[100'000];
int dfs(int x){
    visited[x] = _IDX;

    int nx = arr[x];
    if(nx == x) return 1;
    if(visited[nx] != -1){
        if(visited[nx] != _IDX) return 0;

        // 방문한 노드가 이번 노드에서 방문했던 노드인 경우
        int cnt = 1;
        int cx = arr[x];
        while(cx != x){ cnt++; cx = arr[cx]; }
        return cnt;
    }
    else{
        return dfs(nx);
    }
}
void Solve() {
    for(int rep=0; rep<T; rep++){
        cin >> N;
        for(int i=0;i<N;i++) {
            cin >> arr[i];
            arr[i]--;
        }
        memset(visited, -1, sizeof visited);
        _IDX = 0;
        int ans = 0;
        for(int i=0;i<N;i++){
            if(visited[i] == -1) {
                ans += dfs(i);
                _IDX++;
            }
        }

        cout << N - ans << endl;
    }

    return;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef BOJ
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> T;
}
int main() {
    init();
    Solve();
    return 0;
}