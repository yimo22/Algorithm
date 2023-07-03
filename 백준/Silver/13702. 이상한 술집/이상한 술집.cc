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
    // k명에게 똑같은 양으로 나눔
    // K명에게 최대한 많은 막걸리를 분배할수 있는 용량
    int s = 0;
    ll e = 0x7fffffff;
    e++;

    while (s < e && (e - s) > 1) {
        int mid = s + (e - s) / 2;
        int cnt = 0;
        for (int w : arr) {
            cnt += (w / mid);
        }

        if (cnt >= K) s = mid;
        else e = mid;
    }
    cout << s << endl;
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