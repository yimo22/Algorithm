

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    static int T, K;
    static String str;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine());

        while (T > 0) {
            str = br.readLine();
            K = Integer.parseInt(br.readLine());
            Solve();
            T--;
        }
    }

    private static void Solve() {
        /*
        ans1. 어떤 문자를 정확히 K개를 포함하는 가장 짧은 연속 문자열의 길이를 구한다.
        ans2. 어떤 문자를 정확히 K개를 포함하고, 문자열의 첫 번째와 마지막 글자가 해당 문자로 같은 가장 긴 연속 문자열의 길이를 구한다.
         */

        // 1 <= K <= 문자열길이 <= 10,000
        // dp -> LCS
        // dp[i][j] = (w1, w2)
        // w1 : i<->j LCS
        // w2 : 문자 종류의 수

        // init
        int ans1 = 10_000 + 1;
        int ans2 = -1;
        // start
        for (int i = 0; i < str.length(); i++) {
            // 시작점은 i
            int[] cur = new int[26];
            cur[str.charAt(i) - 'a']++;
            // checking
            if(cur[str.charAt(i)-'a'] == K){
                // answer update
                ans2 = ans1 = 1;
            }

            // 탐색
            for (int j = i + 1; j < str.length(); j++) {
                int idx = str.charAt(j) - 'a';
                cur[idx]++;
                if(cur[idx] == K){
                    // ans1 update
                    ans1 = Math.min(ans1, j-i+1);

                    // ans2 update
                    if(str.charAt(i) == str.charAt(j)){
                        ans2 = Math.max(ans2, j-i+1);
                    }
                }
            }

        }

        ans1 = (ans1 == 10_000 + 1) ? -1 : ans1;
        if(ans1 == -1 && ans2 == -1)
            System.out.println(-1);
        else
            System.out.println(ans1 + " " + ans2);

    }
}
