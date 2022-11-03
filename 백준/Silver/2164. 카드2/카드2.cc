#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
int main() {
    cin >> N;
    queue<int> q;
    for (int i = 1; i <= N; i++) q.push(i);

    while (q.size() > 1) {
        q.pop();
        q.push(q.front());
        q.pop();
    }

    cout << q.front() << "\n";
    return 0;
}