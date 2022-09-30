import java.util.*;
class Solution {
    public int solution(int n) {
        int answer = 0;
        List<Integer> list = new ArrayList();
        // init
        for(int i=1;i<=n;i++) list.add(i);
        
        // list 탐색
        int left = 0, right = 1;
        int sum = list.get(left);
        while(left < right && right <= list.size()){
            if(sum == n){
                answer++;
                sum -= list.get(left++);
            }
            else if(sum < n){ 
                if(right >= list.size()) break;
                sum += list.get(right++);
            }
            else sum -= list.get(left++);
            
            // right update
            if(left == right){
                right++;
            }
        }
        return answer;
    }
}