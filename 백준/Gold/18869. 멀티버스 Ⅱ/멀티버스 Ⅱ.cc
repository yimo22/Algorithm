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
int N, M;
vector<vector<int>> arr(100, vector<int>(10000, 0));
vector<vector<int>> sarr(100, vector<int>(10000, 0));

void Solve() {
    // 균등한 우주의 쌍이 몇개인지 
    // 구성이 같은데 순서만 다른 우주의 쌍은 한번만 센다
    // N <= 10K
    // M <= 100

    map<int, int> mp[100]; // value -> index
    
    for (int i = 0; i < M; i++) {
        sort(sarr[i].begin(), sarr[i].end());
        sarr[i].erase(unique(sarr[i].begin(), sarr[i].end()), sarr[i].end());
        for (int j = 0; j < sarr[i].size(); j++) {
            mp[i].insert({sarr[i][j], j});
        }
    }

    vector<vector<int>> crr(M, vector<int>(N, 0));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            crr[i][j] = mp[i][arr[i][j]];
        }
    }

    int cnt = 0;
    for (int i = 0; i < M; i++) {
        for (int j = i + 1; j < M; j++) {
            bool promising = true;
            for (int k = 0; k < N; k++) {
                if (crr[i][k] != crr[j][k]) {
                    promising = false;
                    break;
                }
            }
            if (!promising) continue;

            // 같은 수를 사용하는지 check
            promising = false;
            for (int k = 0; k < N ; k++) {
                int w = arr[i][k];
                if (mp[j].find(w) == mp[j].end()) {
                    promising = true;
                    break;
                }
            }

            if (promising) cnt++;
        }
    }
    cout << cnt;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> M >> N;
    arr.resize(M);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            sarr[i][j] = arr[i][j];
        }
    }
}
int main() {
    init();
    Solve();
    return 0;
}