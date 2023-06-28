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
vector<int> arr;
void Solve() {
    // 두 합이 최소가 되는 두쌍
    sort(arr.begin(), arr.end());
    int answer = 0x7fffffff;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int tgt = arr[i] + arr[j];

            int s = 0;
            int e = N - 1;

            while (s == i || s == j) s++;
            while (e == i || e == j) e--;

            int startSum = arr[s] + arr[e];
            if (tgt == startSum) {
                answer = 0;
                goto EX1;
            }

            while (s < e) {
                if (s == i || s == j) {
                    s++;
                    continue;
                }
                if (e == i || e == j) {
                    e--;
                    continue;
                }

                int sum = arr[s] + arr[e];
                if (tgt < startSum) {
                    answer = min(answer, abs(tgt - sum));
                    if (sum > tgt) {
                        e--;
                    }
                    else {
                        s++;
                    }
                }
                else {
                    answer = min(answer, abs(tgt - sum));
                    if (sum < tgt) {
                        s++;
                    }
                    else {
                        e--;
                    }
                }
            }
        }
    }
EX1:    cout << answer << endl;
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