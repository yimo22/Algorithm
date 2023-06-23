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
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    arr.resize(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
}
void Solve() {
    int s = 0;
    int e = 1;

    int sum = arr[s];
    int ans = 0;
    // 끝점 입장에서 조사
    // sum := [s, e)의 합
    while (e < arr.size()) {
        if (sum == M) {
            ans++;
            sum += arr[e++];
        }
        else if (sum < M) {
            // e 입장에서 현재까지 합이 M보다 작은경우
            // -> 더이상 조사할 필요가 없음. (e를 끝점으로 합이 M인것은 존재하지 않음)
            sum += arr[e++];
        }
        else {
            // sum > M
            sum -= arr[s++];
            if (s == e) {
                sum += arr[e++];
            }
        }
    }
    // e가 이미 끝에 도달한경우
    while (s < e) {
        if (sum <= M) {
            if (sum == M) ans++;
            break;
        }
        else {
            sum -= arr[s++];
        }
    }
    cout << ans << endl;
}
int main() {
    init();
    Solve();
    return 0;
}