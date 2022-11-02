#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int N, D;
int Answer = 10'000 + 1;
vector<tuple<int, int, int>> roads;
bool compare(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
    // 출발 시점 ASC, 거리에 대하여 sort
    return get<0>(a) < get<0>(b);
}
void dfs(int total, int cur, int depth) {
    if (cur > D)
        return;
    else if (cur == D) {
        Answer = min(Answer, total);
        return;
    }

    // 해당하는 지름길을 모두 탐색해도 목적지에 도달하지 못한 경우
    if (depth >= roads.size()) {
        Answer = min(Answer, total + (D - cur));
        return;
    }

    int s, e, w;
    tie(s, e, w) = roads[depth];
    // progress
    // 현재 roads[depth] 에 대하여 진행
    // 해당 도로를 타는 경우
    if (cur <= s) dfs(total + (s - cur) + w, e, depth + 1);

    // 해당 도로를 타지 않는 경우
    dfs(total, cur, depth + 1);

    return;
}
void Solution() {
    dfs(0, 0, 0);

    // answer out
    cout << Answer << "\n";
    return;
}
int main() {
    cin >> N >> D;
    int s, e, w;
    for (int i = 0; i < N; i++) {
        cin >> s >> e >> w;
        roads.push_back(make_tuple(s, e, w));
    }

    // sorting
    sort(roads.begin(), roads.end());

    // solve
    Solution();

    return 0;
}