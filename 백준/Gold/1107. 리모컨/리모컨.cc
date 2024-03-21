#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/* define */
#define ll long long
#define endl '\n'

/* var */
int N, M;
bool isBroke[10+1];
ll answer;
int recur(int cur){
    for(int num=0; num<10; num++){
        if(isBroke[num]) continue;
        int nxt = cur * 10 + num;
        int count = abs(N-nxt) + to_string(nxt).length();
        answer = min(answer, (ll)count);

        if(nxt == cur) continue;

        if(to_string(nxt).length() < 6)
            recur(nxt);
    }
    return 0;
}

void Solve() {
    answer = abs(100 - N);
    recur(0);
    cout << answer << endl;

}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef BOJ
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> N >> M;
    int w;
    for(int i=0;i<M;i++) {
        cin >> w;
        isBroke[w] = true;
    }
}
int main() {
    init();
    Solve();
    return 0;
}