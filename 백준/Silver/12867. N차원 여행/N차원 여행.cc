#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

/* define */
#define ll long long
#define endl '\n'

/* var */
int N, M;
vector<int> arr;
string oper;
int board[50+2][50];
void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    arr.resize(M);
    for (int i = 0; i < M; i++) cin >> arr[i];
    cin >> oper;
}
int getIndex(int w, vector<int>& arr) { return lower_bound(arr.begin(), arr.end(), w) - arr.begin();}
void Solve() {
    vector<int> brr(arr);
    sort(brr.begin(), brr.end());
    brr.erase(unique(brr.begin(), brr.end()), brr.end()); // 중복제거

    
    // brr의 사이즈만큼의 좌표만 보면됨 -> max 50개
    // 좌표압축을 사용안하면, N개(1B) 의 좌표를 모두 탐색해야됨

    for (int i = 0; i <= M; i++) {
        if (i == 0) continue; // board[0] 는 원점임

        // copy from prev
        for (int j = 0; j < brr.size(); j++) board[i][j] = board[i - 1][j];

        if (oper[i - 1] == '+') board[i][getIndex(arr[i - 1], brr)]++;
        else board[i][getIndex(arr[i - 1], brr)]--;
    }

    // 탐색
    int answer = 1;
    for (int i = 0; i <= M; i++) {
        for (int j = i + 1; j <= M; j++) {
            // i행과 j행이 중복되는지 check
            // 모두 같으면 유망 x -> 하나라도 다르면 유망
            bool promising = true;
            for (int k = 0; k < brr.size(); k++) {
                if (board[i][k] != board[j][k]) {
                    promising = false;
                    break;
                }
            }
            if (promising) {
                answer = 0;
                goto EX1;
            }
        }
    }
EX1:
    cout << answer << endl;
}
int main() {
    init();
    Solve();
    return 0;
}