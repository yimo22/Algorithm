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
int N, M;
int answer, musicCount;
vector<ll> input; 

int getCount(ll used){
    int ans = 0;
    for(int i=0;i<M;i++){
        if(used & (1LL << i)) ans++;
    }
    return ans;
}
void recur(int depth, int gcnt, long long used){

    // 다 선택한 경우
    if(depth >= N){
        int curCount = getCount(used);

        if(curCount >= musicCount){

            musicCount = curCount;
            answer = min(answer, gcnt);

        }
        return ;
    }

    recur(depth+1, gcnt + 1, used | input[depth]);
    recur(depth+1, gcnt, used);

}

void Solve() {
    recur(0, 0, 0LL);    
    answer = answer == 0 ? -1 : answer;
    cout << answer << endl;
    return;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    input.resize(N);

    ll tmp = 0;
    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        input[i] = 0;
        cin >> s;
        for(int j=M-1; j>=0; j--){
            if(s[j] == 'Y') input[i] |= (1LL << (M - j - 1));
        }
        tmp |= input[i];
    }

    answer = N;
    musicCount = getCount(tmp);
}
int main() {
    init();
    Solve();
    return 0;
}