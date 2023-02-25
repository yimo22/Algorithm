#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string check(string s) {
	int i = 0;
	int j = s.size() - 1;
	while (i < j) {
		if (s[i++] != s[j--]) return "no";
	}
	return "yes";
}
int main() {
	
	while (1) {
		string s;
		cin >> s;
		if (s.size() == 1 && s[0] == '0') break;
		cout << check(s) << '\n';
	}

}