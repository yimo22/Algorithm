#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

/* define */
#define ll long long
#define endl '\n'

/* var */
int N, M;
int arr[1024][1024];
int psum[1024+1][1024+1];
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    // init
    memset(psum, 0, sizeof psum);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            psum[i][j] = arr[i - 1][j - 1] + psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];
        }
    }
}
void Solve() {

    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << psum[x2][y2] - psum[x2][y1 - 1] - psum[x1 - 1][y2] + psum[x1 - 1][y1 - 1] << endl;
    }

}
int main() {
    init();
    Solve();
    return 0;
}