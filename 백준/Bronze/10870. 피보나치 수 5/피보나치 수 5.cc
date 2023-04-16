#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 987654321
int N;
vector<int> f(20 + 1, INF);
int fibo(int w) {
	if (w == 0) return f[w] = 0;
	if (w == 1) return f[w] = 1;

	if (f[w] != INF) return f[w];

	return f[w] = fibo(w - 1) + fibo(w - 2);
}
int main() {
	cin >> N;
	cout << fibo(N);
	return 0;
}