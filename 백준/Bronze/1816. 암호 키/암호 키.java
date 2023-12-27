import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static List<Integer> list;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();
        list = new ArrayList<>();
        N = Integer.parseInt(st.nextToken());

        calc();
        Long s;
        for (int rep = 0; rep < N; rep++) {
            st = new StringTokenizer(br.readLine());
            s = Long.parseLong(st.nextToken());
            boolean isPossible = true;

            // 완탐
            for(int i=0;i<list.size();i++){
                int val = list.get(i);
                if(s % val == 0){
                    sb.append("NO").append("\n");
                    isPossible = false;
                    break;
                }
            }
            if(isPossible) sb.append("YES").append("\n");

        }

        System.out.println(sb.toString());
    }

    public static void calc() {
        // 10e6 까지의 소수 구하기
        int _VALUE = (int)10e5;
        boolean chk[] = new boolean[_VALUE + 1];
        // set
        Arrays.fill(chk, true);


        for (int i = 2; i <= (int) Math.sqrt(_VALUE); i++) {
            if (!chk[i]) continue;
            for (int j = i + i; j <= _VALUE; j += i) chk[j] = false;
        }

        for(int i=2 ; i<= _VALUE ; i++){
            if(chk[i]) {
                list.add(i);
            }
        }
    }
}