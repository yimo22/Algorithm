#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool comp(pair<pair<int, int>, string> a, pair<pair<int, int>, string> b)
{
	if (a.first.first == b.first.first) return a.first.second < b.first.second;
	else return a.first.first < b.first.first;
}

int main() {
	int N;
	cin >> N;
	vector<pair<pair<int, int>, string> > v;
	for (int i = 0; i < N; i++) {
		int age;
		string s;
		cin >> age >> s;
		v.push_back({ {age, i}, s });
	}

	sort(v.begin(), v.end(), comp);

	for (auto c : v) {
		cout << c.first.first << " " << c.second << '\n';
	}

	return 0;
}