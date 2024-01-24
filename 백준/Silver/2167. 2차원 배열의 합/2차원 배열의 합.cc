#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <tuple>
using namespace std;

/* define */
#define ll long long
#define endl '\n'
#define BOJ
/* var */
int N, M, K;
int arr[300+1][300+1];
int psum[300+1][300+2];
vector<tuple<int,int,int,int>> v;
void Solve() {
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            psum[i][j] = psum[i][j-1] + arr[i][j];
        }
    }

    for(auto c : v){
        int sx, sy, ex, ey;
        tie(sx, sy, ex, ey) = c;

        int sum = 0;
        for(int row = sx; row<=ex; row++){
            sum += psum[row][ey] - psum[row][sy-1];
        }
        cout << sum << endl;
    }
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef BOJ
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int i, j, x, y;
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> arr[i][j];
        }
    }

    cin >> K;
    for(int rep=0;rep<K;rep++){
        cin >> i >> j >> x >> y;
        v.push_back({i,j,x,y});
    }


}
int main() {
    init();
    Solve();
    return 0;
}