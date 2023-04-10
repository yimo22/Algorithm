#include <iostream>
#include <limits>
#include <utility>
#include <numeric>
using namespace std;

int paperCnt[5];
int map[10][10];
int availalbe_map[10][10];
int Answ = std::numeric_limits<int>::max();
void Input(){
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      cin >> map[i][j];
    }
  }
}
void make0(pair<int,int> pos, int length){
  int x = pos.first;
  int y = pos.second;
  for(int i=x;i<x+length;i++){
    for(int j=y;j<y+length;j++){
      map[i][j] = 0;
    }
  }
}
void make1(pair<int,int> pos, int length){
  int x = pos.first;
  int y = pos.second;
  for(int i=x;i<x+length;i++){
    for(int j=y;j<y+length;j++){
      map[i][j] = 1;
    }
  }
}
pair<int,int> nextPos(){
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      if(map[i][j] == 1) return make_pair(i,j);
    }
  }
  return make_pair(-1,-1);
}
void dfs(pair<int,int> curPos){

  if(curPos.first == -1 && curPos.second == -1){
    // update Answ
    Answ = min(Answ, accumulate(paperCnt, paperCnt+5, 0));
    return ;
  }

  // 모든 경우의 수에 대하여 탐색
  for(int len = 1; len <= 5; len++){
    // curPos 로부터 칸이 1로 존재하는지 확인
    bool isPromsing = true;
    for(int i = curPos.first; i < curPos.first+len; i++){
      for(int j=curPos.second; j<curPos.second+len; j++){
        // check
        if(map[i][j] == 0 || i < 0 || i >= 10 || j < 0 || j >= 10){
          isPromsing = false;
          break;
        }
      }
      if(isPromsing == false) break;
    }
    if(isPromsing == false) continue;

    // 해당 블록이 가능할 경우 탐색
    if(accumulate(paperCnt, paperCnt+5, 0) + 1 >= Answ) continue;
    
    if(paperCnt[len-1] < 5){
      paperCnt[len-1]++;
      make0(curPos,len);
      dfs(nextPos());

      // roll back
      paperCnt[len-1]--;
      make1(curPos,len);
    }
  }
}
void solution(){
  bool isAll0 = true;
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      if(map[i][j] != 0){
        isAll0 = false;
        dfs(make_pair(i,j));
      }
    }
  }
  if(isAll0 == true) Answ = 0;
}
int main(){
  Input();

  solution();
  if(Answ == std::numeric_limits<int>::max()) cout << "-1" <<"\n";
  else cout << Answ << "\n";

  return 0;
}