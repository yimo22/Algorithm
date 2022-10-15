import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static int[][] dp;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s1 = br.readLine(), s2 = br.readLine();
        int answer = 0;
        // init dp
        dp = new int[s1.length()+1][s2.length()+1];
        // start
        for(int i=1;i<=s1.length();i++){
            for(int j=1;j<=s2.length();j++){
                if(s1.charAt(i-1) == s2.charAt(j-1)){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    answer = Math.max(answer, dp[i][j]);
                }
            }
        }
        System.out.println(answer);
    }
}
