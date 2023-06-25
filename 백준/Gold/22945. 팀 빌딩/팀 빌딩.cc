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
int N;
vector<int> arr;
void Solve() {
    // (A와 B 사이에 존재하는 개발자수) * min(A의 능력치, B의 능력치)
    // 최대길이 -> 최소길이로 탐색
    // min값을 증가시키며 발생할 수 있는 edge 탐색

    int mValue = 0;
    int ans = 0;
    int s = 0, e = N-1;
    while (s < e) {
        ans = max(ans, min(arr[s], arr[e]) * (e - s - 1));
        if (arr[s] > arr[e]) {
            e--;
        }
        else s++;
    }
    cout << ans << endl;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
}
int main() {
    init();
    Solve();
    return 0;
}