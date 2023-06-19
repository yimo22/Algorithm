#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

/* define */
#define ll long long
#define endl '\n'

/* var */
int N;
vector<int> arr, brr;
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    arr.resize(N);
    brr.resize(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    for (int i = 0; i < N; i++) cin >> brr[i];
}
void Solve() {
    vector<int> crr(N, 0);
    for (int i = 0; i < N; i++) crr[i] = arr[i] - brr[i];

    map<int, int> mp;
    vector<ll> psum(N+1, 0);
    for (int i = 1; i <= N; i++) {
        psum[i] = psum[i - 1] + crr[i - 1];
        mp[psum[i]]++;
    }
    // 0은 자체가 답
    ll answer = mp[0];


    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        int count = iter->second;
        answer += (ll)count * (count - 1) / 2;
    }

    cout << answer << endl;

}
int main() {
    init();
    Solve();
    return 0;
}