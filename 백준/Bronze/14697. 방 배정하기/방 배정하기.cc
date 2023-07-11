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
int arr[3];
int N;
int found = 0;
int recur(int depth, int rest) {
    if (found) return 0;
    if (depth >= 3) {
        if (rest == 0) found = 1;
        return 0;
    }

    // 사용하는 경우
    for (int i = 0; i * arr[depth] <= rest; i++) {
        recur(depth + 1, rest - i * arr[depth]);
    }
    // 사용안하는 경우
    recur(depth + 1, rest);

    return 0;
}
void Solve() {
    recur(0, N);
    cout << found << endl;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < 3; i++) cin >> arr[i];
    cin >> N;
}
int main() {
    init();
    Solve();
    return 0;
}