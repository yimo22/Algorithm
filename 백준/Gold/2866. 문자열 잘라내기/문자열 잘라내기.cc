#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <unordered_set>
using namespace std;

/* define */
#define ll long long
#define endl '\n'

/* var */
int R, C;
string board[1000+1];
void Solve() {

    // [0, R)
    int s, e;
    s = 0;
    e = R;

    while(s < e && (e-s) > 1){
        int count = s + (e-s) / 2;
        bool promising = true;
        // count 개가 정답이 될 수 있는지 체크
        unordered_set<string> st;
        for(int col=0; col<C; col++){
            string str = "";

            // 정답이 count개 
            // -> [count+1 ~ R-1][]

            for(int row=count; row<R; row++){
                str += board[row][col];
            }

            if(st.find(str) != st.end() || "" == str) {
                promising = false;
                break;
            }

            st.insert(str);
        }
        if(promising){
            s = count;
        }
        else e = count;
    }
    cout << s << endl;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;
    for(int i=0;i<R;i++){
        cin >> board[i];
    }
}
int main() {
    init();
    Solve();
    return 0;
}