#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define endl '\n'
#define ll long long
int N;
vector<char> oper;
ll maxV = 0;
string maxS;
ll minV = 0x7fff'ffff'ffff'ffff;
string minS;
int perm(int pos, int used, string val) {
	if (val.length() >= N+1) {
		ll value = stoll(val);
		if (value > maxV) {
			maxV = value;
			maxS = val;
		}
		if (value < minV) {
			minV = value;
			minS = val;
		}
		return 0;
	}

	for (int i = 0; i <= 9; i++) {
		if (used & (1 << i)) continue; // already used
		if (pos > 0) {
			int prev = val[pos-1] - '0';
			char _op = oper[pos];
			if (_op == '<' && prev >= i) continue;
			if (_op == '>' && prev <= i) continue;
		}

		perm(pos + 1, used | (1 << i), val + to_string(i));
	}
	return 0;
}
void Solve() {
	perm(0, 0, "");
	cout << maxS << endl << minS << endl;
}
int main() {
	cin >> N;
	char c;
	oper.push_back(' ');
	for (int i = 0; i < N; i++) {
		cin >> c;
		oper.push_back(c);
	}

	Solve();
	return 0;
}