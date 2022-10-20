

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    // a와 b로만 문자열이 주어질 때, a를 모두 연속으로 만들기 위해서 필요한 교환의 횟수
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();

        // a와 b의 수를 count
        int pivot = 0;
        for(int i=0;i<str.length();i++) if(str.charAt(i) == 'a') pivot++;

        int answer = str.length();
        // sliding window
        for(int i=0;i<str.length();i++){
            // [i, i+pivot) 까지 b의 갯수
            int _cnt = 0;
            for(int j=i, cnt = 0; cnt < pivot; cnt++, j++){
                j = (j%str.length());
                if(str.charAt(j) == 'b') _cnt++;
            }
            answer = Math.min(answer, _cnt);
        }
        System.out.println(answer);
    }
}
