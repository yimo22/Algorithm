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
vector<int> selected;

void search(int pos, int start) {
    if (pos >= M) {
        for (int i = 0; i < M; i++) {
            cout << selected[i] << " ";
        }
        cout << endl;
        return;
    }


    for (int i = start; i < N; i++) {
        selected[pos] = arr[i];
        search(pos + 1, start);
    }
}
void Solve() {
    sort(arr.begin(), arr.end());
    search(0, 0);
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    arr.resize(N);
    selected.resize(M);
    for (int i = 0; i < N; i++) cin >> arr[i];
}
int main() {
    init();
    Solve();
    return 0;
}