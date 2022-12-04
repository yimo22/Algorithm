#include "bits/stdc++.h"
using namespace std;
#define MAX 20
#define endl "\n"
int N;
vector<vector<int>> maping(MAX, vector<int>(MAX, 0));
void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}
int search(int x, int y, int d1, int d2) {
    /* divide sector
     sector 1. : 0 <= r <= x + d1 && 0 <= c <= y
     sector 2. : 0 <= r <= x + d2 && y < c < N
     sector 3. : x + d1 <= r < N && 0 <= c < y-d1+d2
     sector 4. : x + d2 < r < N && y-d1+d2 <= c < N
     */

    vector<vector<int>> marked(N, vector<int>(N, -1));
    int maxValue, minValue;
    // sector 5 marking
    // making indent and count
    int indent[d1 + d2];
    for (int i = d1; i >= 0; i--) indent[d1 - i] = i;
    for (int i = 1; i <= d2; i++) indent[d1 + i] = i;

    int sum = 0;
    for (int i = x; i <= x + d1 + d2; i++) {
        // phase : i - x
        int phase = i - x;
        int cnt = (d2 + d1 + 1) - abs(d2 - phase) - abs(d1 - phase);
        for (int j = y - d1 + abs(d1 - phase), colCount = 0; colCount < cnt;
             colCount++, j++) {
            marked[i][j] = 5;
            sum += maping[i][j];
        }
    }
    minValue = maxValue = sum;

    // start section 1 searching
    sum = 0;
    for (int i = 0; i < x + d1; i++) {
        for (int j = 0; j <= y; j++) {
            if (marked[i][j] == -1) {
                marked[i][j] = 1;
                sum += maping[i][j];
            }
        }
    }
    minValue = min(minValue, sum);
    maxValue = max(maxValue, sum);

    // start section 2 searching
    sum = 0;
    for (int i = 0; i <= x + d2; i++) {
        for (int j = y + 1; j < N; j++) {
            if (marked[i][j] == -1) {
                marked[i][j] = 2;
                sum += maping[i][j];
            }
        }
    }
    minValue = min(minValue, sum);
    maxValue = max(maxValue, sum);

    // start section 3 searching
    sum = 0;
    for (int i = x + d1; i < N; i++) {
        for (int j = 0; j < y - d1 + d2; j++) {
            if (marked[i][j] == -1) {
                marked[i][j] = 3;
                sum += maping[i][j];
            }
        }
    }
    minValue = min(minValue, sum);
    maxValue = max(maxValue, sum);

    // start section 4 searching
    sum = 0;
    for (int i = x + d2 + 1; i < N; i++) {
        for (int j = y - d1 + d2; j < N; j++) {
            if (marked[i][j] == -1) {
                marked[i][j] = 4;
                sum += maping[i][j];
            }
        }
    }
    minValue = min(minValue, sum);
    maxValue = max(maxValue, sum);

    return maxValue - minValue;
}
void Solution() {
    // for all sectoin (x, y)
    int answer = numeric_limits<int>::max();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int d1 = 1; d1 <= N; d1++) {
                for (int d2 = 1; d2 <= N; d2++) {
                    // checking boundary
                    if (i + d1 + d2 >= N || j - d1 < 0 || j + d2 >= N) continue;

                    int result = search(i, j, d1, d2);
                    if (answer > result) {
                        answer = min(answer, result);
                    }
                }
            }
        }
    }

    cout << answer << endl;
    return;
}
int main() {
    // setting
    init();
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> maping[i][j];
        }
    }
    Solution();
}