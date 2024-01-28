#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

/* define */
#define ll long long
#define endl '\n'
constexpr int dir[3][2] = {
        {-1, 0},
        {-1, -1},
        {0, -1}
};


/* var */
int N, M;
int dp[25+1][25+1];
pair<int,int> getPos (int w){
    return {w / M, w % M};
}

bool isIn(int x, int y){
    if(x < 0 || x >= N || y < 0 || y >= M) return false;
    return true;
}

bool isIn2(int x, int y){
    if(x > 0 && x < N && y > 0 && y < M) return true;
    else return false;
}


ll recur(int idx){
    pair<int,int> cur = getPos(idx);

    if(!isIn(cur.first, cur.second)){
//        for(int i=0;i<N;i++){
//            for(int j=0;j<M;j++){
//                cout << dp[i][j] << " ";
//            }
//            cout << endl;
//        }
//        cout << "--------" << endl;
        return 1;
    }


    // 해당 좌표에 넣는경우
    // checking
    ll ans = 0;

    dp[cur.first][cur.second] = 1;
    // backtracking
    int promising = dp[cur.first][cur.second];
    for(int d=0;d<3;d++){
        int nx = cur.first + dir[d][0];
        int ny = cur.second + dir[d][1];

        if(!isIn(nx,ny)) continue;
        promising &= dp[nx][ny];
    }

    if(! (isIn2(cur.first, cur.second) && promising )){
        ans += recur(idx+1);
    }

    // 해당 좌표에 넣지 않는 경우
    dp[cur.first][cur.second] = 0;
    ans += recur(idx + 1);
    return ans;
}
void Solve() {
    cout << recur(0);
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef BOJ
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> N >> M;

}
int main() {
    init();
    Solve();
    return 0;
}