#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int dp[500][500];
int recur(int row, int pos, vector<vector<int>>& arr){
    if(row >= arr.size()) return -1;
    if(pos < 0 || pos > row) return -1;
    if(dp[row][pos] != -1) return dp[row][pos];
    return dp[row][pos] = max(recur(row+1, pos, arr), recur(row+1, pos+1, arr)) + arr[row][pos];
}
int solution(vector<vector<int>> triangle) {
    int answer = 0; 
    N = triangle.size();
    memset(dp, -1, sizeof dp);
    // init
    for(int i=0;i<N;i++) dp[N-1][i] = triangle[N-1][i];
    answer = recur(0, 0, triangle);
    return answer;
}