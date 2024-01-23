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
vector<int> v;
void Solve() {
    sort(v.begin(), v.end());

    // 나눠주는과자의 길이 
    // 최대 : 1B <> 최소 : 1
    
    // 과자길이에 따라, 이분탐색


    int s = 0;
    int e = 1e9 + 1;

    while (s < e && (e -s) > 1) {
        int mid = s + (e - s) / 2;

        int cnt = 0;
        for (int w : v) cnt += w / mid;

        // 가능
        if (cnt >= M) s = mid;
        else e = mid;
    }

    // 왼쪽것 선택
    cout << s;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> M >> N;
    int w;
    for (int i = 0; i < N; i++) {
        cin >> w;
        v.push_back(w);
    }
}
int main() {
    init();
    Solve();
    return 0;
}