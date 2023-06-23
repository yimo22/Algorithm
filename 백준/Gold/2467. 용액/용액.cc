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
vector<int> arr;
void Solve() {
    int s = 0, e = N -1;
    int diff = 0x7fffffff;
    pair<int, int> ans;
    while (s < e) {
        int sum = arr[s] + arr[e];
        int curDiff = abs(sum);

        if (abs(sum) < abs(diff)) {
            diff = sum;
            ans = { s, e };
        }
        if (sum >= 0) {
            e--;
        }
        else {
            s++;
        }
    }
    cout << arr[ans.first] << " " << arr[ans.second] << endl;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
}
int main() {
    init();
    Solve();
    return 0;
}