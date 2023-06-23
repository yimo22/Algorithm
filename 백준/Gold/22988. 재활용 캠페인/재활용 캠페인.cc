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
ll X;
vector<ll> arr;
void Solve() {
    // A, B -> min(A +B + X/2, X)
    // 적당한 순서로 교환 -> 합이 X인 쌍을 최대한 많이
    // 구 : 최대 몇개?

    // 분석
    // 2개의 합 : X/2 -> 꽉참
    // (A, B, C) 를 반납 -> ((A, B), C) : 용량에 관계없이 꽉참

    // sol. 두개의 합이 X/2 인 경우의수 구함
    // -> 남은 갯수 / 3 을 합

    /* Solution Section Start */
    int ans = 0;
    int found = 0;
    int cnt = 0;
    ll target = (X+1) / 2;
    // find Sum == X/2
    sort(arr.begin(), arr.end());
    int s = 0;
    int e = arr.size() - 1;
    // 이미 꽉찬 경우
    while (e >= 0 && arr[e] >= X) {
        cnt++;
        e--;
    }

    while (s < e) {
        ll sum = arr[s] + arr[e];
        if (sum >= target) {
            found++;
            e--;
            s++;
        }
        else if (sum < target) {
            s++;
        }
    }

    int rest = N - cnt - found * 2;
    ans = rest / 3 + cnt + found;
    cout << ans << endl;
    /* Solution Section End */
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> X;
    arr.resize(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
}
int main() {
    init();
    Solve();
    return 0;
}