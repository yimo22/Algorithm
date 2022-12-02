#include "bits/stdc++.h"

using namespace std;
#define endl "\n"

int Solution(int N, int K, vector<int> arr) {
    // 최장 연속 부분 수열의 길이
    map<int, int> mp;  // value, count
    int l = 0, r = 0;
    int answer = 0;
    while (r < N) {
        int lv = arr.at(l);
        int rv = arr.at(r);
        if (mp[rv] < K) {
            mp[rv]++;
            r++;
            answer = max(answer, r - l);
        } else {
            // 갯수가 K개를 넘는 경우
            mp[lv]--;
            l++;
        }
    }
    return answer;
}
int main() {
    // init
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K, w;
    vector<int> v;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> w;
        v.push_back(w);
    }
    cout << Solution(N, K, v);

    return 0;
}