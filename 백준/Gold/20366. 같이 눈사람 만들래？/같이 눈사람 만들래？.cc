#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <tuple>
using namespace std;

/* define */
#define ll long long
#define endl '\n'
bool comp(tuple<int, int, int>& a, tuple<int, int, int>& b) {
    return get<0>(a) < get<0>(b);
}
/* var */
int N;
vector<int> arr;
void Solve() {
    // 두 합이 최소가 되는 두쌍
    int answer = 0x7fffffff;
    vector<tuple<int, int, int>> v;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            v.push_back({ arr[i] + arr[j], i, j });
        }
    }
    sort(v.begin(), v.end(), comp);

    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            int o1_x, o1_y, o2_x, o2_y;
            int o1_sum, o2_sum;
            tie(o1_sum, o1_x, o1_y) = v[i];
            tie(o2_sum, o2_x, o2_y) = v[j];
            
            if (o1_x != o2_x && o1_y != o2_y && o1_x != o2_y && o1_y != o2_x) {
                answer = min(answer, abs(o1_sum - o2_sum));
                break;
            }
        }
    }
    cout << answer << endl;
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