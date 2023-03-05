#include <iostream>
#include <algorithm>


using namespace std;

#define MAX_ITEMS 100+1
#define MAX_W 100000+1
int N,K;
int dp[MAX_ITEMS][MAX_W]; // dp[i,j] : i번쨰 물건까지 탐색, 가방의 무게제한이 j일떄 가방에 담긴 물건들의 가치는 value
int W[MAX_ITEMS];
int V[MAX_ITEMS];
int main(){
  cin >> N >> K;
  for(int i=1;i<=N;i++){
    cin >> W[i] >> V[i] ;
  }

  // init
  for(int index = 1; index <= N;index++){
    for(int cur_weight = 1;cur_weight <= K ; cur_weight++){
      if(cur_weight >= W[index] )
        dp[index][cur_weight] = max(dp[index-1][cur_weight-W[index]]+V[index], dp[index-1][cur_weight]);
      else{
        dp[index][cur_weight] = dp[index-1][cur_weight];
      }
    }
  }
  
  cout << dp[N][K] << endl;

  return 0;
}