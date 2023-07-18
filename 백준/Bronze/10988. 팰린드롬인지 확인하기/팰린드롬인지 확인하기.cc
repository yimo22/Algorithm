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
string str;
void Solve() {
    int s = 0;
    int e = str.size() - 1;
    while (s < e) {
        if (str[s++] != str[e--]) {
            cout << 0;
            return;
        }
    }
    cout << 1;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> str;
}
int main() {
    init();
    Solve();
    return 0;
}