#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define endl '\n'
#define ll long long
int N, S;
vector<int> v;
map<int, int> mp1;
map<int, int> mp2;
void getSum(int pos, int bound, int sum, map<int,int> & mp) {
	if (pos >= bound) return;



	// select
	mp[v[pos] + sum]++;
	getSum(pos + 1, bound, sum + v[pos], mp);

	// not select
	getSum(pos + 1, bound, sum, mp);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> S;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	
	// start
	getSum(0, N / 2, 0, mp1);
	getSum(N / 2, N, 0, mp2);

	// find Ans
	long long answer = 0;
	answer += mp1[S];
	answer += mp2[S];
	for (auto iter = mp1.begin(); iter != mp1.end(); iter++) {
		if (mp2.find(S - iter->first) != mp2.end()) {
			answer += ((ll)iter->second * mp2[S - iter->first]);
		}
	}
	cout << answer << endl;

	return 0;
}
/*
* 
5 1
-7 -3 -2 5 8
* 
* 
*/