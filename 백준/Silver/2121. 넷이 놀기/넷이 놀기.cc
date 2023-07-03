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
int N, A, B;
vector<pair<int,int>> v;
bool comp(pair<int, int>& a, pair<int, int>& b) {
    if (a.first == b.first) return a.second < b.second;
    else return a.first < b.first;
}
bool check(vector<pair<int,int>> & arr, pair<int, int> a) {


    // mid 보다 x좌표가 큼 : s := mid
    // mid 보다 x좌표가 작음 : e:=mid
    //          y 좌표가 큼 : s:=mid;
    //          y 좌표가 작다 : e:= mid;
    int s = 0;
    int e = N;

    while (s < e && (e - s) > 1) {
        int mid = s + (e - s) / 2;

        if (arr[mid] == a) return true;
        else if (arr[mid] > a) {
            e = mid;
        }
        else {
            // arr[mid] < a
            s = mid;
        }
    }

    return arr[s] == a;
}
void Solve() {
    sort(v.begin(), v.end(), comp);

    int answer = 0;
    for (int i = 0; i < N; i++) {
        if ( check(v, make_pair(v[i].first + A, v[i].second )) && 
            check(v, { v[i].first, v[i].second + B }) && 
            check(v, {v[i].first + A , v[i].second + B})
        )answer++;
    }
    cout << answer << endl;
    
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> A >> B;
    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        v.push_back({ a, b});
    }
}
int main() {
    init();
    Solve();
    return 0;
}