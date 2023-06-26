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
int N, K, B;
int arr[100000+1];
void Solve() {
    // 정상적인 연속K개의 신호등 존재위한 최소의 신호등 수리 갯수
    fill_n(arr, 100001, 1);

    for (int i = 0; i < B; i++){
        int num;
        cin >> num;
        arr[num]--;
    }

    for (int i = 2; i <= N; i++)
        arr[i] += arr[i - 1];

    int m = 0;
    for (int i = K; i <= N; i++)
        m = max(m, arr[i] - arr[i - K]);

    cout << K - m;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K >> B;
}
int main() {
    init();
    Solve();
    return 0;
}