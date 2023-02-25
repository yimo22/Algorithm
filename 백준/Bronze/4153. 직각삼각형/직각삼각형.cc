#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	while (1) {
		int a,b,c;
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) break;

		// sorting
		vector<int> v{ a,b,c };
		sort(v.begin(), v.end());
		if (v.back() * v.back() != v[0] * v[0] + v[1] * v[1]) cout << "wrong\n";
		else cout << "right\n";
	}

	return 0;
}