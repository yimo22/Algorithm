#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
int N, M;
bool comp(const pair<string, int>& a, const pair<string, int>& b) {
    if (a.second == b.second && a.first.size() == b.first.size()) {
        return a < b;
    } else if (a.second == b.second)
        return a.first.size() > b.first.size();
    else
        return a.second > b.second;
}
bool comp2(const pair<string, int>& a, const pair<string, int>& b) {
    if (a.first.size() == b.first.size() && a.second == b.second) {
        return a.first < b.first;
    } else if (a.second == b.second) {
        return a.first.size() > b.first.size();
    }
    return a.second > b.second;
}
int main() {
    string s;
    cin >> N >> M;
    map<string, int> mp;
    for (int i = 0; i < N; i++) {
        cin >> s;
        if (s.length() >= M) mp[s]++;
    }

    // value update
    vector<pair<string, int>> v(mp.begin(), mp.end());
    sort(v.begin(), v.end(), comp);

    for (auto cur : v) {
        cout << cur.first << "\n";
    }
    return 0;
}