#include "bits/stdc++.h"

using namespace std;
int N, K;
const int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
typedef struct Node {
    int x, y, d;
    Node(int x, int y, int d) {
        this->x = x;
        this->y = y;
        this->d = d;
    }
} Node;
vector<vector<int>> mtrx(12, vector<int>(12, 0));
vector<Node *> counting[12][12];
vector<Node *> nodelist;
bool check() {}
void checkingNodeStatus(Node *node) {
    cout << "(" << node->x << " " << node->y << " " << node->d << ")";
}
void checkingMtrx(int cnt) {
    cout << "-----------------------" << cnt << "----------------\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << "for " << i << " " << j << " : ";
            if (counting[i][j].empty()) {
                cout << "empty\n";
                continue;
            }
            cout << counting[i][j].size();
            // for (Node *cur : counting[i][j]) checkingNodeStatus(cur);
            cout << endl;
        }
        cout << endl;
    }
    cout << "------------------------------\n";
}
int backward(int dir) {
    if (dir == 0)
        return 1;
    else if (dir == 1)
        return 0;
    else if (dir == 2)
        return 3;
    else if (dir == 3)
        return 2;
}
bool move() {
    for (Node *cur : nodelist) {
        if (cur != counting[cur->x][cur->y].front()) continue;
        // moving with
        int nx = cur->x + dir[cur->d][0];
        int ny = cur->y + dir[cur->d][1];

        if (nx < 0 || ny < 0 || nx >= N || ny >= N || mtrx[nx][ny] == 2) {
            cur->d = backward(cur->d);
            nx = cur->x + dir[cur->d][0];
            ny = cur->y + dir[cur->d][1];
        }

        if (nx < 0 || ny < 0 || nx >= N || ny >= N || mtrx[nx][ny] == 2)
            continue;
        // red && white
        else if (mtrx[nx][ny] == 1 || mtrx[nx][ny] == 0) {
            vector<Node *> insertList(counting[cur->x][cur->y]);
            counting[cur->x][cur->y].clear();
            // reversed
            if (mtrx[nx][ny] == 1)
                reverse(insertList.begin(), insertList.end());

            // update state
            for (Node *nd : insertList) {
                nd->x = nx;
                nd->y = ny;
            }
            // override
            counting[nx][ny].insert(counting[nx][ny].end(), insertList.begin(),
                                    insertList.end());

            // update cur countings
        }

        // checking
        if (counting[nx][ny].size() >= 4) return true;
    }
    return false;
}
int Solution() {
    // display nodes
    for (Node *cur : nodelist) {
        counting[cur->x][cur->y].push_back(cur);
    }
    int answer = 0;
    while (1) {
        answer++;
        if (move() || answer > 1000) break;
        // checkingMtrx(answer);
    }

    return answer > 1000 ? -1 : answer;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mtrx[i][j];
        }
    }
    for (int i = 0; i < K; i++) {
        int x, y, d;
        cin >> x >> y >> d;
        Node *ptr = new Node(x - 1, y - 1, d - 1);
        nodelist.push_back(ptr);
    }

    cout << Solution();

    return 0;
}