#include <iostream>
#include <vector>
using namespace std;
#define MAX 15
int N;
int p[MAX+1];
int t[MAX+1];
int answer = 0;
void dfs(int cur, int pay){
  // 현재 idx 는 cur
  // 현재 idx 가 N보다 클경우, 해당 결과 update
  if(cur >= N){
    answer = max(answer, pay);
    return ;
  }

  // cur를 포함하여 하는 경우
  if(cur + t[cur] <= N)
    dfs(cur+t[cur], pay + p[cur]);

  // cur를 포함하지 않는 경우
  dfs(cur+1, pay);

  return ;
}
void Solve(){
  dfs(0,0);
}
int main(){
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> t[i] >> p[i];
  }

  Solve();

  cout << answer << "\n";
  return 0;
}