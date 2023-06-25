#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

/* define */
#define ll long long
#define endl '\n'

/* var */
int G;
void Solve() {
    // G = (x+y)(x-y)
    // G : 자연수 -> 기억몸무게는 더 작아야됨
    vector<int> ans;
    for (int i = 1; i < sqrt(G); i++) {
        if (G % i == 0) {
            int w = i + (G / i);
            if (!(w & 1)){
                ans.push_back(w / 2);
            }
        }
    }
    if (ans.empty()) cout << -1 << endl;
    else
        for (auto iter = ans.rbegin(); iter != ans.rend(); iter++) cout << *iter << endl;

}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> G;
}
int main() {
    init();
    Solve();
    return 0;
}