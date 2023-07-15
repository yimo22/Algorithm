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
int arr[5];
void Solve() {
    int ans = 1;
    for (;; ans++) {
        int cnt = 0;
        for (int i = 0; i < 5; i++) {
            if (ans % arr[i] == 0) cnt++;
        }
        if (cnt >= 3) break;
    }
    cout << ans;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < 5; i++) cin >> arr[i];
}
int main() {
    init();
    Solve();
    return 0;
}