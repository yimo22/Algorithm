/*
	joon - #13460
	구슬 탈출 2 - 삼성SW 기출
	Coded by yimo22
*/	
#include <iostream>
#include <queue>
#include <string>
using namespace std;
#define Max 11
int map[Max][Max];
int direction[4][2] = { {1,0},{0,1},{-1,0},{0,-1}};
bool Isvisited[Max][Max][Max][Max];
int answ=-1;
typedef struct balls{
	int rx;
	int ry;
	int bx;
	int by;
	int depth;
	void Set(int rx, int ry, int bx, int by, int depth){
		this->rx = rx;
		this->ry = ry;
		this->bx = bx;
		this->by = by;
		this->depth =depth;
	}
	void rSetXY(int x, int y){
		this->rx = x;
		this->ry = y;
	}
	void bSetXY(int x, int y){
		this->bx = x;
		this->by = y;
	}
	void setDp(int dp){
		this->depth = dp;
	}
	int rGetX(){
		return this->rx;
	}
	int rGetY(){
		return this->ry;
	}
	int bGetX(){
		return this->bx;
	}
	int bGetY(){
		return this->by;
	}
	int GetDp(){
		return this->depth;
	}
}balls;
int destX, destY;
void Moving(int& x, int& y , int dir){
	while(1){
		x += direction[dir][0]; y+= direction[dir][1];
		if(map[x][y]==1) // 벽이 있어 움직이지 못하는 경우 
		{
			// 원상 복구시킨다.
			x -= direction[dir][0]; y-= direction[dir][1];
			break;
		}
		else if(map[x][y]==2) // 이미 도착지에 도달 한 경우
			break;
	}
}
int main(){
	int N , M;
	cin >> N >> M;
	// '.'은 빈 칸을 의미하고, 
	//'#'은 공이 이동할 수 없는 장애물 또는 벽을 의미하며, 
	//'O'는 구멍의 위치를 의미한다. 
	//'R'은 빨간 구슬의 위치, 
	//'B'는 파란 구슬의 위치이다.
	
	balls ptc;
	ptc.setDp(0);
	// 진행할수 없는 길=1 , 진행가능한 길 =0, 목적지 = 2
	string s;
	for(int i=0;i<N;i++){
		cin >> s;
		for(int j=0;j<M;j++){
			switch (s[j]){
			case '.' : map[i][j] = 0; break;
			case '#' : map[i][j] = 1; break;
			case 'O' : map[i][j] = 2; destX = i; destY = j; break;
			case 'R' : ptc.rSetXY(i,j); break;
			case 'B' : ptc.bSetXY(i,j); break;
			default: break;
			}
		}
	}

	// bfs 를 이용한 탐색
	queue<balls> q;
	q.push(ptc);
	while(!q.empty()){
		balls temp = q.front();
		q.pop();

		// 10번 보다 초과하는 경우 -1을 출력한다.
		if(temp.GetDp() > 10){
			answ = -1;
				break;
		}
		// 최적 경우를 찾은 경우
		if(temp.rGetX() == destX && temp.rGetY() == destY){
			answ = temp.GetDp();
			break;
		}
	
		// 4가지 방향에 대하여 움직인다.
		for(int i=0;i<4;i++){
		int bx,by,rx,ry;
		bx = temp.bGetX(); by = temp.bGetY();
		rx = temp.rGetX(); ry = temp.rGetY();
		Isvisited[rx][ry][bx][by] = true;
		Moving(bx,by,i);
		Moving(rx,ry,i);
		
		if(by == destY && bx == destX) // blue 만 도착한 경우 
			continue;


		// BlueBall 과 Redball이 동시 도착한 경우
		if(by == ry && ry == destY && bx == rx && rx == destX){
			continue;
		}
		

		if(bx == rx && by == ry){
			switch(i){
			// tilt downside
			case 0 : temp.rGetX()>temp.bGetX() ? bx-- : rx--; break;
			// tilt rightside
			case 1 : temp.rGetY()>temp.bGetY() ? by-- : ry--; break;
			// tilt upside
			case 2 : temp.rGetX()>temp.bGetX() ? rx++ : bx++; break;
			// tilt leftside
			case 3 : temp.rGetY()>temp.bGetY() ? ry++ : by++; break;
			default : break;
			}
		}

			// 이미 방문 했을 경우
			if(Isvisited[rx][ry][bx][by])
				continue;
			balls ptr= {rx,ry,bx,by,temp.GetDp()+1};
			q.push(ptr);
		}

	}
		cout << answ;
	return 0;
}