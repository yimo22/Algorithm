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
int N, D, K, C;
vector<int> arr;
int cnt[3000+1];
void Solve() {


    int typeCount = 0;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (i == 0) {

            for (int j = 0; j < i + K; j++) {
                if (cnt[arr[j]] == 0) typeCount++;
                cnt[arr[j]]++;
            }

            if (cnt[C] == 0) ans = max(ans, typeCount + 1);
            else ans = max(ans, typeCount);

            continue;
        }

        cnt[arr[i - 1]]--;
        if (cnt[arr[i - 1]] == 0) typeCount--;

        if (cnt[arr[(i + K - 1) % N]] == 0) typeCount++;
        cnt[arr[(i + K - 1) % N]]++;

        if (cnt[C] == 0) ans = max(ans, typeCount + 1);
        else ans = max(ans, typeCount);
    }
    cout << ans << endl;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> D >> K >> C;
    arr.resize(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
}
int main() {
    init();
    Solve();
    return 0;
}