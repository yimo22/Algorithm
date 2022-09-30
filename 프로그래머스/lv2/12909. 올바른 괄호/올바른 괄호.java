import java.util.*;
class Solution {
    boolean solution(String s) {
        boolean answer = true;
        
        Stack<Integer> stack = new Stack();
        // stack 사용
        
        for(int i=0;i<s.length();i++){
            if(s.charAt(i) == '('){
                stack.push(1);
            }
            else if(s.charAt(i) == ')'){
                if(stack.isEmpty()) return false;
                
                stack.pop();
            }
        }
        // stack 이 비어있지 않을 경우, false
        answer = stack.isEmpty();
        return answer;
    }
}