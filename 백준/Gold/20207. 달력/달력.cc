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
int S, E;
int arr[1000 + 2]; // 0 ~ i일 까지의 합
void Solve() {
    int ans = 0;
    int cm = 0;
    int prev = 0;
    for (int i = 1; i <= 1000 + 1; i++) {
        if (arr[i] == 0) {
            ans += (i - prev - 1) * cm;
            cm = 0;
            prev = i;
        }
        else cm = max(cm, arr[i]);
    }
    cout << ans;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    int rep = N;
    while (rep-- > 0) {
        cin >> S >> E;
        for (int i = S; i <= E; i++) arr[i]++;
    }

}
int main() {
    init();
    Solve();
    return 0;
}