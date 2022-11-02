#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int N;
void Solve() {
    // A(창근) , B(창영)
    // 돌은 1 or 3개를 가져 갈 수 있음
    // 마지막 돌을 가져가는 사람이 이김
    // 게임을 이기는 사람을 구해라. (상근이 시작)

    // 돌이 2n 개 or 2n+1 개

    // case 1. 2n개 일경우, 반드시 상근 승
    // case 2. 2n+1 개 일경우, 반드시 창영 승
    if ((N & 1))
        cout << "SK\n";
    else
        cout << "CY\n";
}
int main() {
    cin >> N;
    Solve();
    return 0;
}