import java.util.*;
class cmp implements Comparator<Integer>{
    @Override
    public int compare(Integer o1, Integer o2){
        return o1 > o2 ? -1 : 1;
    }
}
class Solution
{
    public int solution(int []A, int []B)
    {
        int answer = 0;
        Integer[] newB = new Integer[B.length];
        for(int i=0;i<B.length;i++) newB[i] = B[i];
        Arrays.sort(A);
        Arrays.sort(newB, new cmp());
        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        for(int i=0;i<A.length;i++){
            answer += (A[i] * newB[i]);
        }
        return answer;
    }
}