#include <string>
#include <vector>
#include <cstring>
#include <unordered_set>
#include <iostream>
#include <algorithm>
using namespace std;
/* define */
constexpr int dir[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};

int N, M;
unordered_set<int> visitedList;
bool isIn(int x, int y){
    if(x < 0 || y <0 || x >= N || y >= M) return false;
    return true;
}


int recur(int x, int y, vector<vector<int>> & land, vector<vector<int>> & visited){
    visitedList.insert(y);
    int cnt = 1;
    for(int d=0; d<4; d++){
        int nx = dir[d][0] + x;
        int ny = dir[d][1] + y;
        
        if(!isIn(nx,ny)) continue;
        if(visited[nx][ny]) continue;
        if(land[nx][ny] == 0) continue;
        
        visited[nx][ny] = 1;
        cnt += recur(nx,ny, land, visited);
    }
    return cnt;
}
int solution(vector<vector<int>> land) {
    int answer = 0;
    N = land.size();
    M = land[0].size();
    
    vector<int> psum(M, 0);
    vector<vector<int>> visited(N, vector<int>(M, 0));
    // 완탐
    for(int i=0;i<M;i++){
        // i열을 뚫는 경우
        
        for(int j=0;j<N;j++){
            
            if(land[j][i] && !visited[j][i]) {
                
                int _cnt = 0;
                visitedList.clear();
                visited[j][i] = 1;
                _cnt += recur(j, i, land, visited);
                for(int w : visitedList) {
                    psum[w] += _cnt;
                }
                
            }
        }
    }
    
    answer = *max_element(psum.begin(), psum.end());
    
    return answer;
}