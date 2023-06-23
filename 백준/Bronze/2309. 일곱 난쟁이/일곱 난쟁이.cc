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
vector<int> arr(9, 0);
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < 9; i++) cin >> arr[i];
}
void Solve() {
    // 7 명 합이 100
    // -> 2명의 합이 sum - 100
    int sum = 0;
    for (int i = 0; i < 9; i++) sum += arr[i];

    sort(arr.begin(), arr.end());
    int s = 0;
    int e = arr.size() - 1;
    while (s < e) {
        int tsum = arr[s] + arr[e];
        // e 입장에서 check
        if (tsum > sum - 100) {
            e--;
        }
        else if (tsum == sum - 100) {
            for (int i = 0; i < arr.size(); i++) {
                if (i == s || i == e) continue;
                cout << arr[i] << endl;
            }
            break;
        }
        else {
            s++;
        }
    }
}
int main() {
    init();
    Solve();
    return 0;
}