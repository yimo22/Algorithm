
import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        for (int i = 0; i < N; i++) {
            StringBuilder sb = new StringBuilder();
            String str = sc.next();
            int res = (check(str)) ? 1 : 0;

            sb.append("#").append(i+1).append(" ").append(res);
            System.out.println(sb.toString());
        }
    }

    /**
     * 회문인지 검사하는 함수
     * @param str
     * @return
     */
    private static boolean check(String str) {
        int start = 0, end = str.length()-1;

        while(start <= end){
            if(str.charAt(start) != str.charAt(end)) return false;
            start++;
            end--;
        }
        return true;
    }
}
