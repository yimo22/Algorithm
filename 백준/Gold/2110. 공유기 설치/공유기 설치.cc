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
int N, C;
vector<int> arr;
void Solve() {
    sort(arr.begin(), arr.end());
    // 두 공유기 사이의 거리에 대하여 탐색
    int s = 1;
    int e = 1e9 + 1;
    while (s < e && (e - s) > 1) {
        int mid = s + (e - s) / 2;

        int cnt = 0;
        int prev;
        for (int i = 0; i < N; i++) {
            if (i == 0) {
                prev = arr[i];
                cnt++;
                continue;
            }

            if (arr[i] - prev >= mid) {
                prev = arr[i];
                cnt++;
            }
        }

        if (cnt >= C) s = mid;
        else e = mid;
    }
    cout << s << endl;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> C;
    arr.resize(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
}
int main() {
    init();
    Solve();
    return 0;
}