#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int N;
vector<int> v;
void Solve() {
    // Longest Increasing Sequences (LIS)
    vector<int> list;
    for (int i = 0; i < v.size(); i++) {
        if (list.empty() || list.back() < v[i]) {
            list.push_back(v[i]);
            continue;
        }
        int pos = lower_bound(list.begin(), list.end(), v[i]) - list.begin();
        list[pos] = v[i];
    }

    cout << v.size() - list.size() << "\n";
}
int main() {
    cin >> N;
    int w;
    for (int i = 0; i < N; i++) {
        cin >> w;
        v.push_back(w);
    }

    Solve();
}