#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MAX 10'000
int T;
int dp[MAX + 1][2];  // [N][0] : 합 N을 표현 with 1, 2를 사용
// [N][1] : 3을 반드시 사용하여 표현
int Solve(int num) {
    // num 을 1, 2, 3의 합으로 나타내느 방법의 수
    if ((dp[num][0] + dp[num][1]) != 0) return dp[num][0] + dp[num][1];

    // start
    for (int i = 4; i <= num; i++) {
        dp[i][0] = dp[i - 2][0] + 1;
        dp[i][1] = dp[i - 3][0] + dp[i - 3][1];
    }

    // return
    return dp[num][0] + dp[num][1];
}
int main() {
    // init
    dp[1][0] = 1;
    dp[1][1] = 0;
    dp[2][0] = 2;
    dp[2][1] = 0;
    dp[3][0] = 2;
    dp[3][1] = 1;
    cin >> T;

    while (T > 0) {
        int n;
        cin >> n;
        cout << Solve(n) << "\n";
        T--;
    }
}