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
vector<int> input;
int arr[8];
int answer = 0;
int recur(int pos, int used) {
    if (pos == N) {
        int sum = 0;
        for (int i = 0; i < N - 1; i++) {
            sum += abs(arr[i] - arr[i + 1]);
        }
        answer = max(sum, answer);
        return 0;
    }

    for (int i = 0; i < N; i++) {
        if (used & (1 << i)) continue;
        arr[pos] = input[i];
        recur(pos + 1, used | (1 << i) );
    }
    return 0;
}
void Solve() {
    recur(0, 0);
    cout << answer << endl;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    input.resize(N);
    for (int i = 0; i < N; i++) cin >> input[i];
}
int main() {
    init();
    Solve();
    return 0;
}