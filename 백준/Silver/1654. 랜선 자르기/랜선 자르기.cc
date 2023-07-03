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
int K, N;
vector<int> arr;
void Solve() {
    int s = 1;
    ll e = 0x7fffffff;
    e++;

    while (s < e && (e - s) > 1) {
        int mid = s + (e - s) / 2;
        int cnt = 0;
        for (int w : arr) cnt += (w / mid);

        if (cnt >= N) s = mid;
        else e = mid;
    }
    cout << s << endl;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> K >> N;
    arr.resize(K);
    for (int i = 0; i < K; i++) cin >> arr[i];
}
int main() {
    init();
    Solve();
    return 0;
}