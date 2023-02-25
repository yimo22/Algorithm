// 소수의 갯수
#include <iostream>
#include <algorithm>

using namespace std;
int prime[1000 + 1];
int main() {
    int n;
    cin >> n;
    int cnt = 0;
    
    fill_n(prime, 1000 + 1, 1);
    prime[1] = prime[0] = 0;
    for (int i = 2; i <= 1000; i++) {
        if (prime[i]) {
            for (int j = i + i; j <= 1000; j += i)
                prime[j] = 0;
        }
    }


    for (int i = 0; i < n; i++) {
        int w;
        cin >> w;
        if (prime[w]) cnt++;
    }

    cout << cnt;
    return 0;
}