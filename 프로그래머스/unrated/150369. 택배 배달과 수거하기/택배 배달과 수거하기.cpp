#include <string>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    stack<pair<int,int>> deliv, pick;
    for(int i=0;i<deliveries.size();i++) deliv.push({i+1, deliveries[i]});
    for(int i=0;i<pickups.size();i++) pick.push({i+1, pickups[i]});
    
    while(1){
        if(deliv.empty() && pick.empty()) break;
        
        int cur = 0;
        int pos = 0;
        
        while(!deliv.empty() && deliv.top().second == 0) deliv.pop();
        if(!deliv.empty()) {
            
            answer += deliv.top().first;
            pos = deliv.top().first;
            while(!deliv.empty()){
                auto val = deliv.top(); deliv.pop();

                if(cur + val.second > cap){
                    deliv.push({val.first, cur + val.second - cap});
                    break;
                } 
                cur += val.second;
                
            }
        }
        // 돌아오면서 수거
        while(!pick.empty() && pick.top().second == 0) pick.pop();
            
        if(!pick.empty()){
            // 처음 수거장소까지 이동
            // 수거장소 -> 원점 까지 이동
            answer += abs(pick.top().first - pos);
            answer += pick.top().first;
            cur = 0;
            while(!pick.empty()){
                auto val = pick.top(); pick.pop();
                
                // 전부 수거하지 못하는 경우
                if(val.second + cur > cap){
                    pick.push({val.first, val.second + cur - cap});
                    break;
                }
                cur += val.second;
            }
        }else{
            answer += pos;
        }
        
    }
    return answer;
}