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
vector<int> arr, brr, crr;
void Solve() {
    int i = 0, j = 0;
    int pos = 0;
    for (; i < N && j < M; pos++) {
        if (arr[i] >= brr[j]) {
            crr[pos] = brr[j++];
        }
        else crr[pos] = arr[i++];
    }

    if (i == N) {
        for (; pos < N + M; pos++) {
            crr[pos] = brr[j++];
        }
    }
    else {
        for (; pos < N + M; pos++) {
            crr[pos] = arr[i++];
        }
    }

    for (int w : crr) cout << w << " ";
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    arr.resize(N);
    brr.resize(M);
    crr.resize(N + M);
    for (int i = 0; i < N; i++) cin >> arr[i];
    for (int j = 0; j < M; j++) cin >> brr[j];
}
int main() {
    init();
    Solve();
    return 0;
}