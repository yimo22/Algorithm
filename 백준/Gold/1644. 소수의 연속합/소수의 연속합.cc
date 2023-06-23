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
vector<int> primeList;
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;

    vector<int> isPrime(N+1, 1);
    // prime 만들기
    isPrime[1] = 0;
    for (int i = 2; i <= sqrt(N); i++) {
        if (isPrime[i]) {
            for (int j = i + i; j <= N; j += i) isPrime[j] = 0;
        }
    }
    for (int i = 2; i <= N; i++) if (isPrime[i]) primeList.push_back(i);
}
void Solve() {
    // 연속된 소수의 합으로 나타낼 수 있는 경우의 수
    // -> N까지의 소수에서, 합이 N이 되는 경우의수
    int s = 0;
    int e = 1;
    int ans = 0;
    if (N == 1) {
        cout << 0 << endl;
        return;
    }
    int sum = primeList[s];
    while (s < e && e < primeList.size()) {
        if (sum == N) {
            ans++;
            sum += primeList[e++];
        }
        else if (sum < N) {
            // 불가능한 경우
            sum += primeList[e++];
        }
        else {
            sum -= primeList[s++];
            if (s == e) {
                sum += primeList[e++];
            }
        }
    }

    // e가 끝점에 도달한 경우
    while (s < e) {
        if (sum <= N) {
            if (sum == N) ans++;
            break;
        }
        else {
            sum -= primeList[s++];
        }
    }
    EX1:
    cout << ans << endl;
}
int main() {
    init();
    Solve();
    return 0;
}