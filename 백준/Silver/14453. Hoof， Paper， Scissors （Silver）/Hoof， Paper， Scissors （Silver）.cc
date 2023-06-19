#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/* define */
#define ll long long
#define endl '\n'

/* var */
int N;
vector<char> v;
int psum[3][100'000+1]; // H:0 / P:1 / S:2

void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            psum[j][i] = psum[j][i - 1];
        }
        if (v[i - 1] == 'P') psum[1][i]++;
        else if (v[i - 1] == 'H') psum[0][i]++;
        else psum[2][i]++;
    }
}
void Solve() {
    // 중간점에 대하여 탐색
    int answer = 0;
    for (int i = 1; i <= N; i++) {
        // 1~i 까지는 첫번쨰, i+1~N 까지 두번쨰
        // H -> P
        answer = max(answer, psum[0][i] - psum[0][0] + psum[1][N] - psum[1][i]);
        // H -> S
        answer = max(answer, psum[0][i] - psum[0][0] + psum[2][N] - psum[2][i]);
        // P -> H
        answer = max(answer, psum[1][i] - psum[1][0] + psum[0][N] - psum[0][i]);
        // P -> S
        answer = max(answer, psum[1][i] - psum[1][0] + psum[2][N] - psum[2][i]);
        // S -> H
        answer = max(answer, psum[2][i] - psum[2][0] + psum[0][N] - psum[0][i]);
        // S -> P
        answer = max(answer, psum[2][i] - psum[2][0] + psum[1][N] - psum[1][i]);
    }
    // 안바꾸는 경우
    for (int i = 0; i < 3; i++) answer = max(answer, psum[i][N]);
    cout << answer << endl;
}
int main() {
    init();
    Solve();
    return 0;
}