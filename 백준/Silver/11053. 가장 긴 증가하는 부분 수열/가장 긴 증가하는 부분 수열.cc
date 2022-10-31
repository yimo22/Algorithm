#include <iostream>
#include <deque>
#include <utility>

using namespace std;

int N;
int input[1000];
int dp[1000];
int answ = 0;
void solved(){
  int max_pos = 0;
  for(int i=0;i<N;i++){
    for(int j=i-1;j>=0;j--){
      if(input[j] < input[i]){
        dp[i] = max(dp[i], dp[j]+1);
      }
    }
    answ = max(dp[i],answ);
  }
  return ;
}
int main(){
  cin >> N;
  for(int i=0;i<N;i++) 
    cin >> input[i];

  // start
  fill_n(dp,1000,1);
  solved();
  cout << answ << endl;

  return 0;
}