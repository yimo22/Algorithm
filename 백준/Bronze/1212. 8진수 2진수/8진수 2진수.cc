#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

/* define */
#define ll long long
#define endl '\n'
#define MAX 3333334
string OCTO[8] = {
    "000",
    "001",
    "010",
    "011",
    "100",
    "101",
    "110",
    "111"
};
/* var */
string s;
void Solve() {

    int tmp;
    for (int i = 0; i < s.length(); i++) {
        tmp = s[i] - '0';
        if (i == 0) cout << stoi(OCTO[tmp], nullptr, 10);
        else cout << OCTO[tmp];
    }

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