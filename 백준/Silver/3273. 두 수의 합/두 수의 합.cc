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
int N, x;
vector<int> arr;
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    cin >> x;
}
void Solve() {
    sort(arr.begin(), arr.end());
    int s = 0, e = arr.size() - 1;
    int ans = 0;
    while (s < e) {
        int sum = arr[s] + arr[e];
        
        if (sum == x) {
            ans++;
            e--;
        }
        else if (sum > x) e--;
        else s++;
    }
    cout << ans << endl;
}
int main() {
    init();
    Solve();
    return 0;
}