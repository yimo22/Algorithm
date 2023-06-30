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
int T, N;
vector<int> arr;
void Solve() {

    // 간격이 같은 세 점으로 가능한 경우
    for (int tc = 0; tc < T; tc++) {
        cin >> N;
        arr.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        int answer = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                int distance = arr[j] - arr[i];
                int value = arr[j] + distance;
                auto res = lower_bound(arr.begin() + j + 1, arr.end(), value);
                
                if (res != arr.end() && *res == value) answer++;
            }
        }

        cout << answer << endl;
    }
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
}
int main() {
    init();
    Solve();
    return 0;
}