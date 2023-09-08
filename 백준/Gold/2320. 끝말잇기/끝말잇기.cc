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
vector<string> v;
int dp[5][1 << 16];         // [앞문자][사용한집합] : 최대의 문자열 길이
int getIndex(char c) {
    switch (c) {
    case 'A': return 0;
    case 'E': return 1;
    case 'I': return 2;
    case 'O': return 3;
    case 'U': return 4;
    default: return -1;
    }
}
int recur(string cur, int used, int depth) {
    // 모두 사용한 경우
    if (used == ((1 << N) - 1)) return 0;
    int idx = getIndex(cur.front());
    int& w = dp[idx][used];
    if (w != -1) return w;

    w = 0;
    for (int i = 0; i < N; i++) {
        if ((1 << i) & used) continue;

        // 해당단어의 앞자리가 현재단어의 뒷자리와 같은 경우
        if (cur.back() == v[i].front())
            w = max(w, (int)(recur(v[i], used | (1 << i), depth + 1) + v[i].length()));
    }
    return w;
}
void Solve() {
    // 초기화
    memset(dp, -1, sizeof dp);

    int answer = 0;
    for (int i = 0; i < N; i++) {
        answer = max(answer, recur(v[i], 1 << i, 0) + (int)v[i].length());
    }
    cout << answer;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        v.push_back(s);
    }
    // 중복제거
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    N = v.size();
}
int main() {
    init();
    Solve();
    return 0;
}