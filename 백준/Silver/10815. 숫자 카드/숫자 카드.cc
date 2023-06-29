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
void Solve() {
    cin >> M;
    int w;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < M; i++) {
        cin >> w;
        int pos = lower_bound(arr.begin(), arr.end(), w) - arr.begin();
        if (pos != N && arr[pos] == w) cout << "1 ";
        else cout << "0 ";
    }
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