#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

/* define */
#define ll long long
#define endl '\n'

/* var */
int N, answer;
vector<int> cost;
vector<vector<pair<int,int>>> discount;

int recur(int depth, int total, int used){
    if(depth == N){
        answer = min(answer, total);
        return 0;
    }
    if(total >= answer) return 0;



    for(int i=0;i<N;i++){
        if(used & (1 << i)) continue;

        // i번쨰 물약을 구매
        // discount 적용
        vector<int> history;
        for(auto p : discount[i]){
            history.push_back(cost[p.first]);
            cost[p.first] -= p.second;
            cost[p.first] = cost[p.first] <= 0 ? 1 : cost[p.first];
        }
        recur(depth+1, total + cost[i], used | (1 << i));
        // roll back
        for(int j=0;j<history.size();j++){
            cost[ discount[i][j].first ] = history[j];
        }
    }

    return 0;
}
void Solve() {
    // 물약을 모두 구매
    // 싸게 샀을 때 그 비용   
    answer = '????';
    recur(0, 0, 0);
    cout << answer << endl;

    return;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    cost.resize(N);
    discount.resize(N);
    for(int i=0;i<N;i++) cin >> cost[i];

    int tmp;
    for(int i=0;i<N;i++){
        cin >> tmp;
        int a, b;
        for(int j=0;j<tmp;j++){
            cin >> a >> b;
            a--;
            discount[i].push_back({a,b});
        }
    }
    return;
}
int main() {
    init();
    Solve();
    return 0;
}