#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <tuple>
#include <queue>
using namespace std;

/* define */
#define ll long long
#define endl '\n'

/* var */
int A, B, C;
int visited[2000 + 1][2000 + 1]; 
void Solve() {
    queue<tuple<int, int, int>> q;
    vector<int> v{ A, B, C };
    sort(v.begin(), v.end());
    q.push({ v[0], v[1], v[2] });

    if ((A + B + C) % 3 != 0) {
        cout << 0;
        return;
    }
    while (!q.empty()) {
        int a, b, c;
        tie(a, b, c) = q.front(); q.pop();

        if (visited[a][c]) continue;
        visited[a][c] = 1;

        if (a == b && b == c) {
            cout << 1;
            return;
        }


        if (a != b) {
            vector<int> tmp{ a + a, b - a, c };
            sort(tmp.begin(), tmp.end());
            q.push({ tmp[0], tmp[1], tmp[2] });
        }

        if (a != c) {
            vector<int> tmp{ a + a, b , c - a };
            sort(tmp.begin(), tmp.end());
            q.push({ tmp[0], tmp[1], tmp[2] });
        }

        if (b != c) {
            vector<int> tmp{ a , b + b, c - b };
            sort(tmp.begin(), tmp.end());
            q.push({ tmp[0], tmp[1], tmp[2] });
        }
    }
    int sum = A + B + C;
    cout << visited[sum / 3][sum / 3];
    return;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> A >> B >> C;
}
int main() {
    init();
    Solve();
    return 0;
}