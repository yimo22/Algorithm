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
vector<int> arr;
void Solve() {
    int s = 0;
    int e = 1;
    int sum = (arr[s] & 1);
    int ans = 0;
    while (s < e && e < N) {
        if (sum <= K) {
            ans = max(ans, e - s - sum);
            sum += (arr[e++] & 1);
        }
        else {
            sum -= (arr[s++]&1);
            if (s == e) {
                sum += (arr[e++] & 1);
            }
        }
    }
    // e가 끝점에 도달한 경우
    while (s < e) {
        if (sum <= K) {
            ans = max(ans, e - s - sum);
        }
        sum -= (arr[s++] & 1);
    }
    cout << ans << endl;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    arr.resize(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
}
int main() {
    init();
    Solve();
    return 0;
}