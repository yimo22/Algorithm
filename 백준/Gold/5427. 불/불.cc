#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <tuple>
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

/* var */
int T;
int W, H;
char board[1000+1][1000+1];
bool isIn(int x, int y){
    if(x < 0 || x >= H || y < 0 || y >= W) return false;
    else return true;
}

void printMtrx(){
    for(int i=0;i<H;i++){
        cout << board[i] << endl;
    }
}

void spreadFire(){
    queue<pair<int,int>> q;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(board[i][j] == '*') q.push({i, j});
        }
    }
    while(!q.empty()){
        pair<int,int> cur = q.front(); q.pop();

        for(int d=0;d<4;d++){
            int nx = dir[d][0] + cur.first;
            int ny = dir[d][1] + cur.second;

            if(!isIn(nx,ny)) continue;
            if(board[nx][ny] == '#') continue;
            if(board[nx][ny] == '*') continue;

            board[nx][ny] = '*';
        }
    }


}
void Solve() {
    // 벽은 불 x
    // 불붙은칸은 이동x
    // 이제 불이 붙으려는 칸은 이동x
    queue<tuple<int,int,int>> q;

    int fire[1000+1][1000+1];
    int visited[1000+1][1000+1];

    memset(fire, -1, sizeof fire);
    memset(visited, -1, sizeof visited);

    // 1. 사람에 대해서 bfs 탐색
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(board[i][j] == '@') {
                q.push({i, j, 0});
                visited[i][j] = 0;
            }
        }
    }

    while(!q.empty()){
        int x, y, time;
        tie(x, y, time) = q.front(); q.pop();


        for(int d=0;d<4;d++){
            int nx = dir[d][0] + x;
            int ny = dir[d][1] + y;

            if(!isIn(nx,ny)) continue;
            if(board[nx][ny] == '#') continue;
            if(visited[nx][ny] >= 0) continue;

            if(board[nx][ny] == '.'){
                visited[nx][ny]= time+1;
                q.push({nx,ny,time+1});
            }
        }

    }

    // 2. 불에 대해서 bfs 탐색
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(board[i][j] == '*'){
                q.push({i, j, 0});
                fire[i][j] = 0;
            }
        }
    }

    while(!q.empty()){
        int x, y, time;
        tie(x, y, time) = q.front(); q.pop();


        for(int d=0;d<4;d++){
            int nx = dir[d][0] + x;
            int ny = dir[d][1] + y;

            if(!isIn(nx,ny)) continue;
            if(board[nx][ny] == '#') continue;
            if(fire[nx][ny] >= 0) continue;

            fire[nx][ny]= time+1;
            q.push({nx,ny,time+1});
        }
    }

//    cout << "++++++++++++++++++" << endl;
//    for(int i=0;i<H;i++){
//        for(int j=0;j<W;j++){
//            cout << visited[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//    cout << "--fire--" << endl;
//    for(int i=0;i<H;i++){
//        for(int j=0;j<W;j++){
//            cout << fire[i][j] << " ";
//        }
//        cout << endl;
//    }
//    cout << "++++++++++++++++++" << endl;


    // 정답찾기
    int ans = '????';
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(board[i][j] == '#') continue;
            // 방문시각 < 불방문 : 가능
            if(visited[i][j] == -1) continue;
            if(i == 0 || i == (H-1) || j == 0 || j == (W-1)){
                if(fire[i][j] == -1) ans = min(ans, visited[i][j]);
                else if(visited[i][j] < fire[i][j]) ans = min(ans, visited[i][j]);
            }

        }
    }

    if(ans == '????')
        cout << "IMPOSSIBLE" << endl;
    else
        cout << ans + 1 << endl;


}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef BOJ
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> T;
    while(T-->0){
        cin >> W >> H;
        for(int i=0;i<H;i++){
            string s;
            cin >> s;
            for(int j=0;j<W;j++){
                board[i][j] = s[j];
            }
        }

        Solve();


    }



}
int main() {
    init();
    return 0;
}