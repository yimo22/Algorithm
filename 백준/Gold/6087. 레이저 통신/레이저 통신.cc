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

constexpr int dir[4][2] = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
};

typedef struct Node{
    int x, y, cnt;
    int dir;
};

struct comp{
    bool operator()(Node & a, Node & b){
        return a.cnt > b.cnt;
    }
};

/* var */
int W, H;
string board[100+1];

bool isIn(int x, int y){
    if(x < 0 || x >= H || y < 0 || y >= W) return false;
    return true;
}

void Solve() {
    // 2차원 다익스트라
    int dist[100][100][4];
    priority_queue<Node, vector<Node>, comp> pq;
    vector<pair<int,int>> list;

    memset(dist, '????', sizeof dist);

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(board[i][j] == 'C'){
                list.push_back({i,j});
            }
        }
    }


    board[list.front().first][list.front().second] = '.';

    for(int d=0;d<4;d++){
        pq.push({list.front().first, list.front().second, 0, d});
        dist[list.front().first][list.front().second][d] = 0;
    }

    while(!pq.empty()){
        Node cur = pq.top(); pq.pop();
//        printf("current : %d %d (%d) : %d\n", cur.x, cur.y, cur.dir, cur.cnt);
        if(dist[cur.x][cur.y][cur.dir] < cur.cnt) continue;
        if(cur.x == list.back().first && cur.y == list.back().second) continue;

        for(int d=0;d<4;d++){
            int nx = cur.x + dir[d][0];
            int ny = cur.y + dir[d][1];

            if(!isIn(nx,ny)) continue;
            if(board[nx][ny] == '*') continue;

            if(d == cur.dir) {
                if(dist[nx][ny][d] > cur.cnt){
                    dist[nx][ny][d] = cur.cnt;
                    pq.push({nx, ny, cur.cnt, d});
                }
            }
            else {
                if(dist[nx][ny][d] > cur.cnt + 1){
                    dist[nx][ny][d] = cur.cnt + 1;
                    pq.push({nx,ny,cur.cnt +1, d});
                }
            };
        }
    }


    cout << min({dist[list.back().first][list.back().second][0], dist[list.back().first][list.back().second][1],dist[list.back().first][list.back().second][2],dist[list.back().first][list.back().second][3]});

}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef BOJ
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> W >> H;
    for(int i=0;i<H;i++) cin >> board[i];
}
int main() {
    init();
    Solve();
    return 0;
}