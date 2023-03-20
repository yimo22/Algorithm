#include <iostream>
#include <queue>
#include <deque>
using namespace std;


const int dir[4][2] = { {0,1},{-1,0},{0,-1},{1,0}};

// -1 : snake's body
// 0 : no apple
// 1 : has apple
int matrix[100][100]={0,}; // matrix
int N, K, L;
struct info{
  int sec;
  char dir;
}info;
struct Body{
  int x,y;
  int dir;
}Body;
queue<struct info> q;
deque<struct Body> snake;
int dur = 0;

void PrintMatrix(){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}
void Solved(){
  // L방향일경우 next_dir = (cur_dir + 1) % 4 
  // R방향일경우 next_dir = (cur_dir + 3) % 4
  struct Body temp = {0,0,0};
  snake.push_back(temp);
  while(1){
    // cout << "\tstart\t cnt : " << dur << endl;
    int next_x = snake.back().x + dir[snake.back().dir][0];
    int next_y = snake.back().y + dir[snake.back().dir][1];
    // cout << "this is " << next_x << " / " << next_y << endl;
    // cout << " matrix value is : " << matrix[next_x][next_y] << endl;
    // border check
    if(next_x < 0 || next_x >= N || next_y < 0 || next_y >= N)
      break;

    // snake's body check
    if(matrix[next_x][next_y] == -1)
      break;

    // cout << "Moved" << endl;
    dur++;
    // Move forward in direction
    int next_val = matrix[next_x][next_y];
    matrix[next_x][next_y] = -1;   
    temp.x = next_x;
    temp.y = next_y;

    // check and change direction
    int next_dir = snake.back().dir;
    if(!q.empty()){
      if(q.front().sec == dur){
      if(q.front().dir == 'L')
        next_dir = (next_dir + 1) % 4;
      else
        next_dir = (next_dir + 3) % 4;
      q.pop();
    }}
    temp.dir = next_dir;
    snake.push_back(temp);
    
    // Check whether apple is exist
    if(next_val == 0) {
      // change matrix
      // cout << "---------------------------pop tail" << endl;
      matrix[snake.front().x][snake.front().y] = 0;
      snake.pop_front();
    }

    // cout << "\tend" << endl ;
  }
}
int main(){
  cin >> N >> K;
  for(int i=0;i<K;i++){
    int x, y;
    cin >> x >> y;
    matrix[x-1][y-1] = 1;
  }

  cin >> L;
  for(int i=0;i<L;i++){
    struct info temp_info;
    cin >> temp_info.sec >> temp_info.dir;
    q.push(temp_info);
  }

  // start
  matrix[0][0] = -1;
  Solved();

  cout << dur + 1 << endl;
  return 0;
}