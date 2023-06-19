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
int board[333+1][333+1];
int psum[333+1][333+1]; // 열에 대한 누적합
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < M; j++) {
            board[i][j] = s[j] - '0';
        }
    }

    // make prefix sum for 2-d array
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            psum[i][j] = psum[i - 1][j] + board[i - 1][j - 1];
        }
    }
}
void Solve() {
    // 완탐
    // O(1/4 * N * N * M * M) = 약 30억 연산 -> 1.x초
    int answer = 0;
    
    int sum = 0;
    int arr[333+1]; // row의 누적합을 임시로 저장할 배열
    for (int i = 1; i <= N; i++) { // 시작 row
        for (int j = i; j <= N; j++) { // 마지막 row
            memset(arr, 0, sizeof arr);
            int len = 0;
            for (int k = 1; k <= M; k++) { // col 탐색
                sum = psum[j][k] - psum[i - 1][k]; // (i, k) ~ (j, k) 까지의 합

                arr[k] = min(arr[k - 1] + sum, sum);

                if (arr[k] == 0) {
                    if (arr[k - 1] != arr[k]) len = 0;
                    answer = max(answer, ++len * (j - i + 1));
                }
            }
        }
    }
    cout << answer << endl;
}
int main() {
    init();
    Solve();
    return 0;
}
/*
4 7
1111000
1000001
1000001
1000001
*/