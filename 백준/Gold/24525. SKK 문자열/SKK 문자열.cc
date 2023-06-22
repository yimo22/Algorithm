#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <map>
using namespace std;

/* define */
#define ll long long
#define endl '\n'

/* var */
string s;
vector<int> psum;
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s;
}
void Solve() {
    map<int, int> mp; // psum -> maxIndex
    // 누 저 캅
    psum.resize(s.size() + 1);
    vector<int> psum_k(s.size() + 1, 0);
    vector<int> psum_s(s.size() + 1, 0);
    for (int i = 1; i <= s.size(); i++) {
        psum_k[i] = psum_k[i - 1];
        psum_s[i] = psum_s[i - 1];

        if (s[i - 1] == 'S') {
            psum[i] = psum[i - 1] + 2;
            psum_s[i]++;
        }
        else if (s[i - 1] == 'K') {
            psum[i] = psum[i - 1] - 1;
            psum_k[i]++;
        }
        else psum[i] = psum[i - 1];

        mp[psum[i]] = max(i, mp[psum[i]]);
    }

    // find
    int ans = -1;
    for (int i = 1; i <= s.size(); i++) {
        // i ~ psum[i-1] 조사
        if ( (mp.find(psum[i - 1]) != mp.end()) &&
            (psum_k[mp[psum[i-1]]] - psum_k[i-1] > 0) && 
            (psum_s[mp[psum[i - 1]]] - psum_s[i - 1] > 0)
        ) {
            ans = max(ans, mp[psum[i-1]] - i + 1);
        }
    }
    cout << ans << endl;
}
int main() {
    init();
    Solve();
    return 0;
}