#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

/* define */
#define ll long long
#define endl '\n'

/* var */
int N;
vector<int> arr;
void Solve() {
    vector<int> psum(N + 1, 0);
    int maxW = psum[0];
    int minW = psum[0];
    for (int i = 1; i <= N; i++) {
        if (arr[i - 1] == 2) psum[i] = psum[i - 1] - 1;
        else psum[i] = psum[i - 1] + 1;
        maxW = max(maxW, psum[i]);
        minW = min(minW, psum[i]);
    }

    cout << abs(maxW - minW);

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