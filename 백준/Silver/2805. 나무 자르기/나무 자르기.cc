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
int N, M;
vector<int> arr;
bool possible(int value) {
    ll rest = 0;
    for (int i = N - 1; i >= 0; i--) {
        rest += max(arr[i] - value, 0);
        if (rest >= M) return true;
    }
    return false;
}
void Solve() {
    int s = 0;
    int e = 1'000'000'000 + 1;
    sort(arr.begin(), arr.end());
    while (s < e && (e - s) > 1) {
        int mid = s + (e - s) / 2;
        if (possible(mid)) s = mid;
        else e = mid;
    }

    cout << s << endl;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M; 
    arr.resize(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
}
int main() {
    init();
    Solve();
    return 0;
}