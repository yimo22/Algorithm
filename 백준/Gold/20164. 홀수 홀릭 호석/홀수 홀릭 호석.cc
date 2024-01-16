#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <unordered_map>
using namespace std;

/* define */
#define ll long long
#define endl '\n'
#
/* var */
string s;
unordered_map<int, int> mp1; // {현재값, 최대값}
unordered_map<int, int> mp2; // {현재값, 최소값}

// 최소값 찾기
int recur2(string cur) {
    int w = stoi(cur);
    // 방문한경우
    if (mp2.find(w) != mp2.end()) return mp2[w];

    mp2.insert({ w, 0 });
    // 현재 홀수갯수
    for (int i = 0; i < cur.size(); i++) {
        if ((cur[i] - '0') & 1) mp2[w]++;
    }

    if (cur.size() == 1) {
        // 1자리인 경우
        return mp2[w];
    }
    else if (cur.size() == 2) {
        // 2자리 
        return mp2[w] += recur2(to_string(cur[0] - '0' + cur[1] - '0'));
    }
    else {
        // 3자리
        // 임의로 나누기
        int mx = '????';
        for (int i = 0; i < cur.size(); i++) {
            for (int j = i + 1; j < cur.size() - 1; j++) {
                // grp1(0~i), grp2(i+1~j), grp3(j+1, N)
                int w1 = stoi(cur.substr(0, i + 1));
                int w2 = stoi(cur.substr(i + 1, j - i));
                int w3 = stoi(cur.substr(j + 1, cur.size() - j - 1));
                mx = min(mx, recur2(to_string(w1 + w2 + w3)));
            }
        }
        return mp2[w] += mx;
    }
}
// 최대값 찾기
int recur1(string cur) {
    int w = stoi(cur);     
    // 방문한경우
    if (mp1.find(w) != mp1.end()) return mp1[w];

    mp1.insert({ w, 0 });
    // 현재 홀수갯수
    for (int i = 0; i < cur.size(); i++) {
        if ((cur[i] - '0') & 1) mp1[w]++;
    }

    if (cur.size() == 1) {
        // 1자리인 경우
        return mp1[w];
    }
    else if (cur.size() == 2) {
        // 2자리 
        return mp1[w] += recur1(to_string(cur[0] - '0' + cur[1] - '0'));
    }
    else {
        // 3자리
        // 임의로 나누기
        int mx = 0;
        for (int i = 0; i < cur.size(); i++) {
            for (int j = i + 1; j < cur.size()-1; j++) {
                // grp1(0~i), grp2(i+1~j), grp3(j+1, N)
                int w1 = stoi(cur.substr(0, i + 1));
                int w2 = stoi(cur.substr(i + 1, j - i));
                int w3 = stoi(cur.substr(j + 1, cur.size() - j - 1));
                mx = max(mx, recur1(to_string(w1 + w2 + w3)));
            }
        }
        return mp1[w] += mx;
    }
}

void Solve() {
    // 최종값 중 최소/최대 구하기
    cout << recur2(s) << " " << recur1(s);
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s;
}
int main() {
    init();
    Solve();
    return 0;
}