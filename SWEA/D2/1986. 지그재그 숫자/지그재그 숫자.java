

import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        for(int tc =1; tc<=T; tc++){
            StringBuilder sb = new StringBuilder();
            int N = sc.nextInt();
            sb.append("#").append(tc).append(" ");
            sb.append(Solve(N));
            System.out.println(sb.toString());
        }
    }

    /**
     * 1~N 까지의 숫자에서 홀수는 더하고 짝수는 뺏을 때, 누적된 값
     * @param N
     * @return
     */
    private static int Solve(int N) {
        int sum = 0;
        for(int i=1;i<=N;i++){
            if(i % 2 == 0) sum -= i;
            else sum += i;
        }
        return sum;
    }
}
