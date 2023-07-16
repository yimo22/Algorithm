#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    int N = routes.size();
    vector<pair<int,int>> arr;
    for(int i=0;i<N;i++){
        arr.push_back({routes[i][0], routes[i][1]});
    }
    sort(arr.begin(), arr.end(), [](pair<int,int>& a, pair<int,int> & b){return a.second < b.second;});
    
    int w = -30000 - 1;
    
    for(pair<int,int> & a : arr){
        int s= a.first;
        int e= a.second;
        if(s <= w && w <= e) continue;
        
        w = e;
        answer++;
    }
    
    return answer;
}