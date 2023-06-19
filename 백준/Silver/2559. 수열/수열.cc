#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/* define */
#define ll long long
#define endl '\n'

/* var */
int N, K;
vector<int> v;
vector<int> psum;
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    v.resize(N);
    psum.resize(N + 1);
    for (int i = 0; i < N; i++) cin >> v[i];

    // init
    psum[0] = 0;
    for (int i = 1; i <= N; i++) psum[i] = v[i - 1] + psum[i - 1];
}
void Solve() {

    // 연속 K일의 최대 합
    // i일을 기준으로 연속 K일의 합 : psum[i+K] - psum[i-1]
    int answer = psum[1 + K - 1] - psum[0];
    for (int i = 2; i + K - 1 <= N; i++) {
        answer = max(answer, psum[i + K - 1] - psum[i - 1]);
    }
    cout << answer << endl;
}
int main() {
    init();
    Solve();
    return 0;
}