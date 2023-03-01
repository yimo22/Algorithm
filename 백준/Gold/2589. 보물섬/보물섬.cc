#include <iostream>
#include <string>
#include <limits>
#include <queue>
#define MAX 50

using namespace std;
const int dir[4][2]={
  {0,1},{-1,0},{0,-1},{1,0}
};
int map[MAX][MAX];
int Answ = std::numeric_limits<int>::min();
int N, M;
bool isVisited[MAX][MAX];
void reset(){
  for(int i=0;i<N;i++){ 
    for(int j=0;j<M;j++){
      isVisited[i][j] = false;
    }
  }
}
void Input(){
  cin >> N >> M;
  for(int i=0;i<N;i++){
    string s;
    cin >> s;
    for(int j=0;j<M;j++){
      map[i][j] = s[j];
    }
  }
}
struct Node{
  int x, y, cnt;
  Node(int X, int Y, int CNT){
    this->x = X;
    this->y = Y;
    this->cnt = CNT;
  }
};
int travel(int xx , int yy){
  int maxDistance = -1;
  queue<struct Node> q;
  // init
  q.push(Node(xx,yy,0));
  isVisited[xx][yy] = true;
  while(!q.empty()){
    int curX = q.front().x;
    int curY = q.front().y;
    int curCnt = q.front().cnt; q.pop();

    // update maxDistance
    maxDistance = max(maxDistance,curCnt);

    for(int k=0;k<4;k++){
      int nextX = curX + dir[k][0];
      int nextY = curY + dir[k][1];

      // boundary check
      if(nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) continue;

      // promixity check
      if(map[nextX][nextY]=='L' && isVisited[nextX][nextY] == false){
        isVisited[nextX][nextY] = true;
        q.push(Node(nextX,nextY,curCnt+1));
      }
    }
  }

  return maxDistance;
}
void solution(){
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      // 전체 탐색
      if(map[i][j] == 'L'){
        reset();
        Answ = max(Answ,travel(i,j));
      }
    }
  }
}
int main(){
  Input();
  solution();

  cout << Answ << "\n";

  return 0;
}