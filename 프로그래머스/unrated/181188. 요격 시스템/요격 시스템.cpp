#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int solution(vector<vector<int>> targets) {
    int answer = 0;
    N = targets.size();
    vector<pair<int,int>> arr;
    for(int i=0;i<N;i++) arr.push_back({targets[i][0], targets[i][1]});
    sort(arr.begin(), arr.end(), [](pair<int,int> & a, pair<int,int> & b){return a.second < b.second;});
    vector<int> used(N, false);
    double w = -1;
    for(int i=0;i<N;i++){
        int s = arr[i].first;
        int e= arr[i].second;
        if(s < w && w < e) continue;
        
        w = arr[i].second - 0.1;
        answer++;
    }
    
    return answer;
}