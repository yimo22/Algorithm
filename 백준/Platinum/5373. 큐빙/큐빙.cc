#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

const int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
const int rdir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
vector<pair<int,int>> orders;
// 0면의 시작은 (3, 0) -> w // U
// 1면의 시작은 (3, 3) -> g // L
// 2면의 시작은 (3, 6) -> y // D
// 3면의 시작은 (3, 9) -> b // R
// 4면의 시작은 (6, 6) -> r // F
// 5면의 시작은 (0, 6) -> o // B
char dice[9][12];
void testAllDice() {
	// 출력
	cout << "------------\n";
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 12; j++) {
			cout << dice[i][j];
		}
		cout << endl;
	}
	cout << "------------\n";
}
/* r, c를 기준으로 rotate */
void rotateMatrix(int r, int c, int rotate) {
	int map[3][3];
	
	if (rotate) {
		for (int i = r; i < r + 3; i++) {
			for (int j = c; j < c + 3; j++) {
				map[j-c][2-(i-r)] = dice[i][j];
			}
		}
	}
	else {
		for (int i = r; i < r + 3; i++) {
			for (int j = c; j < c + 3; j++) {
				map[2-(j-c)][i-r] = dice[i][j];
			}
		}
	}
	for (int i = r; i < r + 3; i++) {
		for (int j = c; j < c + 3; j++) {
			dice[i][j] = map[i - r][j - c];
		}
	}
}
/* Left 와 Right 를 기준으로 이동 */
void rotate13(int side, int rotate) {
	queue<int> q;
	int tmp[3][3];
	// left
	if (side == 1) {
		for (int i = 3; i < 6; i++) q.push(dice[i][12 - 1]);
		for (int i = 8; i >= 0; i--) q.push(dice[i][3]);
		if (rotate) {
			for (int i = 3 - 1; i >= 0; i--) {
				dice[i][3] = q.front();
				q.pop();
			}
			for (int i = 3; i < 6; i++) {
				dice[i][11] = q.front();
				q.pop();
			}
			for (int i = 8; i >= 3; i--) {
				dice[i][3] = q.front();
				q.pop();
			}
		}
		else {
			for (int i = 8; i >= 0; i--) {
				dice[i][3] = q.front();
				q.pop();
			}
			for (int i = 3; i < 6; i++) {
				dice[i][11] = q.front();
				q.pop();
			}
		}
		rotateMatrix(3, 0, rotate);
	}
	// right
	else {
		for (int i = 0; i < 9; i++) q.push(dice[i][5]);
		for (int i = 6-1; i >= 3; i--) q.push(dice[i][9]);

		if (rotate) {
			// 주변 회전
			for (int i = 5; i >= 3; i--) {
				dice[i][9] = q.front();
				q.pop();
			}
			for (int i = 0; i < 9; i++) {
				dice[i][5] = q.front();
				q.pop();
			}
		}
		else {
			for (int i = 3; i < 9; i++) {
				dice[i][5] = q.front();
				q.pop();
			}
			for (int i = 6 - 1; i >= 3; i--) {
				dice[i][9] = q.front();
				q.pop();
			}
			for (int i = 0; i < 3; i++) {
				dice[i][5] = q.front();
				q.pop();
			}
			
		}
		rotateMatrix(3, 6, rotate);
	}
}
/* Up 과 Down 을 기준으로 이동 */
void rotate02(int side, int rotate) {
	queue<int> q;
	if (side == 0) {
		for (int i = 0; i < 12; i++) q.push(dice[3][i]);

		if (rotate) {
			for (int i = 9; i < 12; i++) {
				dice[3][i] = q.front();
				q.pop();
			}
			for (int i = 0; i < 9; i++) {
				dice[3][i] = q.front();
				q.pop();
			}
		}
		else {
			
			for (int i = 3; i < 12; i++) {
				dice[3][i] = q.front();
				q.pop();
			}
			for (int i = 0; i < 3; i++) {
				dice[3][i] = q.front();
				q.pop();
			}
		}
		rotateMatrix(0, 3, rotate);
	}
	else {
		for (int i = 0; i < 12; i++) q.push(dice[5][i]);

		if (rotate) {
			for (int i = 3; i < 12; i++) {
				dice[5][i] = q.front();
				q.pop();
			}
			for (int i = 0; i < 3; i++) {
				dice[5][i] = q.front();
				q.pop();
			}
		}
		else {
			
			for (int i = 9; i < 12; i++) {
				dice[5][i] = q.front();
				q.pop();
			}
			for (int i = 0; i < 9; i++) {
				dice[5][i] = q.front();
				q.pop();
			}
		}
		rotateMatrix(6, 3, rotate);
	}
}
/* Front와 Back을 기준으로 이동 */
void rotate45(int side, int rotate){
	queue<int> q;
	if (side == 4) {
		for (int i = 3; i < 6; i++) q.push(dice[i][2]);
		for (int j = 3; j < 6; j++) q.push(dice[6][j]);
		for (int i = 5; i >= 3; i--) q.push(dice[i][6]);
		for (int j = 5; j >= 3; j--) q.push(dice[2][j]);

		if (rotate) {
			for (int j = 5; j >= 3; j--) {
				dice[2][j] = q.front(); 
				q.pop(); 
			}
			for (int i = 3; i < 6; i++) {
				dice[i][2] = q.front(); 
				q.pop();
			}
			for (int j = 3; j < 6; j++) {
				dice[6][j] = q.front();
				q.pop();
			}
			for (int i = 5; i >= 3; i--) {
				dice[i][6] = q.front();
				q.pop();
			}
		}
		else {
			for (int j = 3; j < 6; j++) {
				dice[6][j] = q.front();
				q.pop();
			}
			for (int i = 5; i >= 3; i--) {
				dice[i][6] = q.front();
				q.pop();
			}
			for (int j = 5; j >= 3; j--) {
				dice[2][j] = q.front();
				q.pop();
			}
			for (int i = 3; i < 6; i++) {
				dice[i][2] = q.front();
				q.pop();
			}
		}
		rotateMatrix(3, 3, rotate);
	}
	else {
		for (int j = 3; j < 6; j++) q.push(dice[0][j]);
		for (int i = 3; i < 6; i++) q.push(dice[i][8]);
		for (int j = 5; j >= 3; j--) q.push(dice[8][j]);
		for (int i = 6 - 1; i >= 3; i--) q.push(dice[i][0]);

		if (rotate) {
			for (int i = 6 - 1; i >= 3; i--) {
				dice[i][0] = q.front();
				q.pop();
			}
			for (int j = 3; j < 6; j++) {
				dice[0][j] = q.front();
				q.pop();
			}
			for (int i = 3; i < 6; i++) {
				dice[i][8] = q.front();
				q.pop();
			}
			for (int j = 5; j >= 3; j--) {
				dice[8][j] = q.front();
				q.pop();
			}
			
		}
		else {
			for (int i = 3; i < 6; i++) {
				dice[i][8] = q.front();
				q.pop();
			}
			for (int j = 5; j >= 3; j--) {
				dice[8][j] = q.front();
				q.pop();
			}
			for (int i = 6 - 1; i >= 3; i--) {
				dice[i][0] = q.front();
				q.pop();
			}
			for (int j = 3; j < 6; j++) {
				dice[0][j] = q.front();
				q.pop();
			}
		}
		rotateMatrix(3, 9, rotate);
	}
}
void init() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 12; j++) {
			dice[i][j] = ' ';
		}
	}
	// 0
	for (int i = 3; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			dice[i][j] = 'g';
		}
	}
	// 1
	for (int i = 3; i < 6; i++) {
		for (int j = 3; j < 6; j++) {
			dice[i][j] = 'r';
		}
	}
	// 2
	for (int i = 3; i < 6; i++) {
		for (int j = 6; j < 9; j++) {
			dice[i][j] = 'b';
		}
	}
	// 3
	for (int i = 3; i < 6; i++) {
		for (int j = 9; j < 12; j++) {
			dice[i][j] = 'o';
		}
	}
	// 4
	for (int i = 6; i < 9; i++) {
		for (int j = 3; j < 6; j++) {
			dice[i][j] = 'y';
		}
	}
	// 5
	for (int i = 0; i < 3; i++) {
		for (int j = 3; j < 6; j++) {
			dice[i][j] = 'w';
		}
	}
}
void calc() {
	// init
	init();
	for (int i = 0; i < orders.size(); i++) {
		int side = orders[i].first;

		if (side == 4 || side == 5) rotate45(side, orders[i].second);

		else if (side == 2 || side == 0) {
			rotate02(side, orders[i].second);
		}

		else { rotate13(side, orders[i].second); };

		//testAllDice();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		string s;
		orders.clear();
		for (int j = 0; j < N; j++) {
			cin >> s;
			int side = 0, rotate = 0;
			switch (s[0]) {
			case 'U': side = 0; break;
			case 'L': side = 1; break;
			case 'D': side = 2; break;
			case 'R': side = 3; break;
			case 'B': side = 5; break;
			case 'F': side = 4; break;
			default: break;
			}

			if (s[1] == '+') rotate = 1;
			orders.push_back({ side, rotate });
		}
		// calc
		calc();

		// 출력
		//testAllDice();
		for (int r = 0; r < 3; r++) {
			for (int c = 3; c<6; c++) {
				cout << dice[r][c];
			}
			cout << '\n';
		}
	}


	return 0;
}