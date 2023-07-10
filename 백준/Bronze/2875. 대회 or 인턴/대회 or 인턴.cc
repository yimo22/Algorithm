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
int N, M, K;
void Solve() {
    // K명은 반드시 인턴쉽 프로그랩에 참여
    int answer = 0;
    for (int i = 0; i <= K; i++) {
        // 여학생에 i명 인턴십 하는경우
        int wm = N - i;
        int m = M - (K - i);

        if (wm >= m * 2) answer = max(answer, m);
        else answer = max(answer, wm / 2);
    }
    cout << answer << endl;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K;
}
int main() {
    init();
    Solve();
    return 0;
}