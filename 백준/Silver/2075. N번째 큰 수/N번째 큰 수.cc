#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 1500
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    priority_queue<int> pq;
    for (int i = 0; i < N; i++) {
        int w;
        for (int j = 0; j < N; j++) {
            cin >> w;
            pq.push(-w);
        }

        while (pq.size() > N) pq.pop();
    }

    cout << -pq.top();
}