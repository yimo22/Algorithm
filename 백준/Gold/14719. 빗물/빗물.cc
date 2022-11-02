#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int H, W;
vector<int> v;
void Solve() {
    stack<int> stk;

    int head = -1;
    int answer = 0;
    for (int i = 0; i < v.size(); i++) {
        if (stk.empty() && v[i] == 0) {
            continue;
        } else if (stk.empty()) {
            head = v[i];
            stk.push(v[i]);
            continue;
        }

        // start
        // top 값보다 작을 경우, stack push
        if (head > v[i]) {
            // v[i] 가 마지막일 경우
            // 현재상황 : head > v[i], head ~ v[i] 사이에 v[i] 보다 큰값이 있을
            // 수 있음 -> stk을 하나씩 까면서, 해당 값이 높을경우를 check
            if (i == v.size() - 1) {
                vector<int> list;
                int val = v[i];
                while (!stk.empty()) {
                    if (stk.top() <= val)
                        list.push_back(stk.top());
                    else {
                        // list 내의 모든 것들을 더함
                        for (int w : list) answer += (val - w);
                        list.clear();

                        // val update
                        val = stk.top();
                    }

                    stk.pop();
                }
            }

            // v[i] 가 마지막이 아닐 경우
            else
                stk.push(v[i]);

        } else {
            // top 보다 크거나 같은 경우
            while (!stk.empty()) {
                answer += (head - stk.top());
                stk.pop();
            }

            stk.push(v[i]);
            head = v[i];
        }
    }
    cout << answer << "\n";
}
int main() {
    cin >> H >> W;
    int w;
    for (int i = 0; i < W; i++) {
        cin >> w;
        v.push_back(w);
    }

    Solve();

    return 0;
}