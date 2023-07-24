#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <tuple>
using namespace std;

/* define */
#define ll long long
#define endl '\n'

/* var */
int N;
vector<tuple<string, int, int>> query;
int selected[3];
int answer = 0;
void recur(int pos, int used) {
    if (pos == 3) {
        for (tuple<string, int, int>& q : query) {
            int strike = 0;
            int ball = 0;
            string str;
            int a, b;
            tie(str, a, b) = q;

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (selected[i] == (str[j] - '0')) {
                        if (i == j) strike++;
                        else ball++;
                        break;
                    }
                }
            }
            if (strike != a || ball != b) return;
        }
        /*
        for (int w : selected) cout << w << " ";
        cout << endl;*/
        answer++;

        return;
    }



    for (int i = 0; i < 9; i++) {
        if (used & (1 << i)) continue;
        selected[pos] = (i + 1);
        recur(pos + 1, used | (1 << i));
    }
}
void Solve() {
    recur(0, 0);
    cout << answer;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    string a;
    int b, c;
    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c;
        query.push_back({ a,b,c });
    }
}
int main() {
    init();
    Solve();
    return 0;
}