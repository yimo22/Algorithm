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
int N, M;
vector<int> arr;
void Solve() {
    // 최대한 공평하게 나눠가졌을때, 최소의수
    // 나눠줄 보석의 갯수
    int s = 0;
    int e = 1e9;
    while (s < e && (e - s) > 1) {
        int mid = s + (e - s) / 2;

        int count = 0;
        for (int w : arr) {
            count += (w / mid);
            if (w % mid != 0) count++;
        }
        if (count <= N) e = mid;
        else s = mid;
    }
    cout << e << endl;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    arr.resize(M);
    for (int i = 0; i < M; i++) cin >> arr[i];
}
int main() {
    init();
    Solve();
    return 0;
}