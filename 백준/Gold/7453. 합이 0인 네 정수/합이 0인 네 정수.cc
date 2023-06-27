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
int arr[4000][4];
void Solve() {
    // 합이 0인 쌍의 갯수
    vector<int> tmp1, tmp2;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tmp1.push_back(arr[i][0] + arr[j][1]);
            tmp2.push_back(arr[i][2] + arr[j][3]);
        }
    }
    sort(tmp1.begin(), tmp1.end());
    sort(tmp2.begin(), tmp2.end());

    ll answer = 0;
    int s = 0;
    int e = tmp2.size() - 1;
    int sum = tmp1[s] + tmp2[e];
    while (1) {
        if (s >= tmp1.size() || e < 0) break;

        sum = tmp1[s] + tmp2[e];

        if (sum == 0) {
            // s의 입장에서 가능한 e를 전부 탐색
            int pa = s;
            int pb = e;

            while ((s < tmp1.size()) && (tmp1[s] == tmp1[pa])) s++;
            while ((e >= 0) && (tmp2[e] == tmp2[pb])) e--;

            answer += ((ll)s - pa) * ((ll)pb - e);
        }
        else if (sum < 0) {
            s++;
        }
        else {
            e--;
        }
    }

    cout << answer << endl;
    // -83, 8, 56
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> arr[i][j];
        }
    }
}
int main() {
    init();
    Solve();
    return 0;
}