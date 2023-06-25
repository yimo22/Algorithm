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
int N, S;
vector<int> arr;
void Solve() {
    // 연속된 부분합 중, 합이 S이상이 되는 것 중 , 가장 짧은 것의 길이
    
    int s = 0;
    int e = 1;
    int sum = arr[s];
    int ans = 0x7fffffff;
    while (s < e && e < N) {
        if (sum >= S) {
            ans = min(ans, e - s);
            sum -= arr[s++];
            if (s == e) {
                sum += arr[e++];
            }
        }
        else if (sum < S) {
            sum += arr[e++];
        }
    }

    // e가 끝점에 도달한 경우
    while (s < e) {
        if (sum >= S) {
            ans = min(ans, e - s);
            sum -= arr[s++];
            if (s == e) break;
        }
        else break;
    }

    ans = (ans == 0x7fffffff) ? 0 : ans;
    cout << ans << endl;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> S;
    arr.resize(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
}
int main() {
    init();
    Solve();
    return 0;
}