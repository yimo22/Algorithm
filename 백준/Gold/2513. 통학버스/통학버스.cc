#include "bits/stdc++.h"

using namespace std;
int N, K, S;
vector<pair<int, int>> pos_behind;
vector<pair<int, int>> pos_front;
bool comp(pair<int, int>& a, pair<int, int>& b) { return a.first > b.first; }
int Solution() {
    // 총 이동거리의 최소값
    // sorting
    sort(pos_front.begin(), pos_front.end(), comp);
    sort(pos_behind.begin(), pos_behind.end(), comp);

    // greedy
    int distance = 0;
    int cur = 0, curDistance = 0;
    for (int i = 0; i < pos_behind.size(); i++) {
        curDistance = max(curDistance, pos_behind[i].first);
        int can = K - cur;
        if (can < pos_behind[i].second) {
            distance += 2 * curDistance;
            curDistance = 0;
            cur = 0;
            pos_behind[i].second -= (can);
            i--;
        } else if (can == pos_behind[i].second) {
            distance += 2 * curDistance;
            curDistance = 0;
            cur = 0;
            pos_behind[i].second -= (can);
        } else {
            // can > 태워야 하는 인원
            // 더 테울수 있는 경우
            cur += pos_behind[i].second;
        }
    }
    if (cur > 0) distance += 2 * curDistance;
    // front greedy
    cur = 0, curDistance = 0;
    for (int i = 0; i < pos_front.size(); i++) {
        curDistance = max(curDistance, pos_front[i].first);
        int can = K - cur;
        if (can < pos_front[i].second) {
            distance += 2 * curDistance;
            curDistance = 0;
            cur = 0;
            pos_front[i].second -= (can);
            i--;
        } else if (can == pos_front[i].second) {
            distance += 2 * curDistance;
            curDistance = 0;
            cur = 0;
            pos_front[i].second -= (can);
        } else {
            // can > 태워야 하는 인원
            // 더 테울수 있는 경우
            cur += pos_front[i].second;
        }
    }
    if (cur > 0) distance += 2 * curDistance;

    return distance;
}
int main() {
    cin >> N >> K >> S;
    int x, w;
    for (int i = 0; i < N; i++) {
        cin >> x >> w;
        if (x > S)
            pos_behind.push_back({x - S, w});
        else
            pos_front.push_back({S - x, w});
    }
    cout << Solution();
    return 0;
}