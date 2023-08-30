#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;

/* define */
#define ll long long
#define endl '\n'

/* var */
int T;
double getSize(pair<int, int>& a) {
    return sqrt((ll)a.first * a.first + (ll)a.second * a.second);
}
bool isVertical(pair<int, int>& a, pair<int, int>& b) {
    auto sa = getSize(a);
    auto sb = getSize(b);

    if (sa != sb) return false;
    if ( ((ll)a.first * b.first + (ll)a.second * b.second) != 0) return false;
    return true;
}
bool comp(pair<int,int> & a, pair<int,int> & b) {
    if (a.first == b.first) return a.second < b.second;
    else return a.first < b.first;
}
void Solve() {
    while (T-- > 0) {
        vector<pair<int, int>> v;
        int x, y;
        for (int i = 0; i < 4; i++) {
            cin >> x >> y;
            v.push_back({ x, y });
        }

        // sorting
        sort(v.begin(), v.end(), comp);

        // calc
        pair<int, int> p1 = { v[0].first - v[3].first, v[0].second - v[3].second };
        pair<int, int> p2 = { v[1].first - v[2].first, v[1].second - v[2].second };
        
        if (isVertical(p1, p2)) cout << 1 << endl;
        else cout << 0 << endl;
    }
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
}
int main() {
    init();
    Solve();
    return 0;
}