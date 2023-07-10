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
int arr[10];
int selected[10];
int answer = 0;
void search(int pos) {
    if (pos == 10) {
        int cnt = 0;
        for (int i = 0; i < 10; i++) {
            if (i >= 2 && ( (selected[i] == selected[i - 1]) && (selected[i-1] == selected[i - 2]))) return;
            if (arr[i] == selected[i]) cnt++;
        }
        if (cnt >= 5) answer++;
        return;
    }

    for (int i = 1; i <= 5; i++) {
        selected[pos] = i;
        search(pos + 1);
    }
}
void Solve() {
    // 5점 이상일 경우의 수 
    search(0);
    cout << answer << endl;
}
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < 10; i++) cin >> arr[i];
}
int main() {
    init();
    Solve();
    return 0;
}