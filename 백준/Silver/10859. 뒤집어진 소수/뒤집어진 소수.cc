#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

/* define*/
#define endl '\n'
#define ll long long
/* var*/
string N;

bool isPrime(ll num) {
	if (num == 1) return false;
	if (num == 2) return true;
	for (ll i = 2; i * i <= num; i++) {
		if ( (num % i) == 0) return false;
	}
	return true;
}
void init() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> N;
}
bool Solve() {
	// case 1. 3/4/7 은 포함되면 안됨
	// case 2. 뒤집혀도 소수인지 확인
	
	// check prime
	if (!isPrime(stoll(N))) return false;

	// 1. reversing
	string s = "";
	for (int i = N.size()-1; i >=0; i--) {
		if (N[i] == '3' || N[i] == '4' || N[i] == '7') return false;
		if (N[i] == '6') s += '9';
		else if (N[i] == '9') s += '6';
		else s += N[i];
	}
	// check
	return isPrime(stoll(s));
}
int main() {
	init();
	if (Solve()) cout << "yes" << endl;
	else cout << "no" << endl;
	return 0;
}