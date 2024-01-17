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
string s;
void recur(string cur) {
    if (cur.size() == 1) {
        cout << cur << endl;
        return;
    }


    // 현재 string 중 하나를 뺌
    string ans = cur.substr(0, cur.size() - 1);
    for (int i = 0; i < cur.size(); i++) {
        // [0,i) + [i+1, cur.size())
        string tmp = cur.substr(0, i) + cur.substr(i + 1, cur.size() - (i + 1));
        ans = min(ans, tmp);
    }
    recur(ans);
    cout << cur << endl;
}
void Solve() {
    recur(s);
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s;
}
int main() {
    init();
    Solve();
    return 0;
}