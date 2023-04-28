#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define endl '\n'
int N;
bool check = false;
string answer;
bool promising(string s) {
	int len = s.size();
	for (int i = 1; i <= len / 2; i++) {
		string a = s.substr(len -i, i);
		string b = s.substr(len - 2 * i, i);
		if (a == b) return false;
	}
	return true;
}
int search(string s) {
	if (check) return 0;
	if (!promising(s)) return 0;
	if (s.size() == N) {
		check = true;
		answer = s;
		return 0;
	}

	search(s + "1");
	search(s + "2");
	search(s + "3");
	return 0;
}
int main() {
	cin >> N;
	search("1");
	search("2");
	search("3");
	cout << answer << endl;
	return 0;
}