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
int N;
vector<int> arr;
void Solve() {
    // 세 팀원의 합이 0
    // 최대의 경우의수
    sort(arr.begin(), arr.end());


    // 순서 상관 없음
    // 가장 실력좋은놈 + 가장실력안좋은놈
    
    // 3명을 뽑았을때, 왼쪽끝과 오른쪽끝을 결정
    // 1. 두명을 뽑음
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = N-1; j > i; j--) {
            int need = -(arr[i] + arr[j]);

            // 가능한 학생들 경우의 수 찾기
            // 범위 : [i+1, j)
            ans += upper_bound(arr.begin() + i + 1, arr.begin() + j, need) - lower_bound(arr.begin() + i + 1, arr.begin() + j, need);
        }
    }
    cout << ans;
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