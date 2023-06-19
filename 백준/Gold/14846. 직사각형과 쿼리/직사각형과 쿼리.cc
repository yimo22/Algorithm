#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/* define */
#define ll long long
#define endl '\n'

/* var */
int N, Q;
int arr[300][300];
int pset[300 + 1][300 + 1][10 + 1];
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    // init
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int w = 1; w <= 10; w++) {
                pset[i][j][w] = pset[i - 1][j][w] + pset[i][j - 1][w] - pset[i - 1][j - 1][w];
            }
            pset[i][j][arr[i - 1][j - 1]]++;
        }
    }
}
void Solve() {
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int count = 0;
        for (int w = 1; w <= 10; w++) {
            int cnt = pset[x2][y2][w] - pset[x2][y1 - 1][w] - pset[x1 - 1][y2][w] + pset[x1 - 1][y1 - 1][w];
            if (cnt > 0) count++;
        }
        cout << count << endl;
    }

}
int main() {
    init();
    Solve();
    return 0;
}