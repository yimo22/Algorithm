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
int N, K;
int ans[12];
int cnt = 0;
int found;
int recur(int sum, int pos) {
    if (found) return 0;
    if (sum > N) return 0;
    if (sum == N) {
        cnt++;
        if (cnt == K) {
            found = true;
            cout << ans[0];
            for (int i = 1; i < pos; i++) {
                cout << "+" << ans[i];
            }
        }
        return 0;
    }

    for (int i = 1; i <= 3; i++) {
        ans[pos] = i;
        recur(sum + i, pos+1);
    }
    return 0;
}
void Solve() {
    // 1, 2, 3의 합으로 나타내는 방법 중 K번쨰 오는 식
    recur(0, 0);
    if (!found) cout << "-1";
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
}
int main() {
    init();
    Solve();
    return 0;
}