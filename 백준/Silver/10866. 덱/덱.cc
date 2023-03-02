#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
using namespace std;
int main() {
	int N;
	cin >> N;
	deque<int> dq;
	for (int i = 0; i < N; i++) {
		string s;
		int w;
		cin >> s;
		if (s == "push_front") {
			cin >> w;
			dq.push_front(w);
		}
		else if (s == "push_back") {
			cin >> w;
			dq.push_back(w);
		}
		else if (s == "pop_front") {
			if (dq.empty()) cout << "-1\n";
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (s == "pop_back") {
			if (dq.empty()) cout << "-1\n";
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (s == "size") {
			cout << dq.size() << '\n';
		}

		else if (s == "empty") {
			cout << dq.empty() << '\n';
		}

		else if (s == "front") {
			if (dq.empty()) cout << "-1\n";
			else cout << dq.front() << '\n';
		}

		else if (s == "back") {
			if (dq.empty()) cout << "-1\n";
			else cout << dq.back() << '\n';
		}
	}
}