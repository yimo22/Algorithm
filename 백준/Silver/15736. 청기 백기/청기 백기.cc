#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;
/* define*/
/* var*/
int N;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	// 1~N까지의 약수의 갯수가 홀수인 수 
	cout << (int)sqrt(N) << '\n';
	return 0;
}