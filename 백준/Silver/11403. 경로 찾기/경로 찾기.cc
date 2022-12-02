#include "bits/stdc++.h"
#define INF 200
using namespace std;
int N;
void Solution(vector<vector<int>> map) {
    vector<vector<int>> available(N, vector<int>(N, 0));
    // init
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 0) {
                map[i][j] = INF;
            }
        }
    }

    // start
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                map[i][j] = min(map[i][k] + map[k][j], map[i][j]);
            }
        }
    }

    // sort
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == INF)
                map[i][j] = 0;
            else
                map[i][j] = 1;
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    vector<vector<int>> map(N, vector<int>(N, 0));
    int w;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
    Solution(map);
    return 0;
}