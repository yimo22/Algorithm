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
int N;
void Solve() {
    if (N == 0) {
        cout << "NO";
        return;
    }

    for(int i=19;i>=0;i--){
        if (N >= pow(3, i)) N -= pow(3, i);
    }

    if (N == 0) cout << "YES";
    else cout << "NO";
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
}
int main() {
    init();
    Solve();
    return 0;
}