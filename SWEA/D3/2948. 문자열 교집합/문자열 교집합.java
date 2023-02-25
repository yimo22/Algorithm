import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Solution {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        Set<String> set;

        int T = Integer.parseInt(st.nextToken());
        StringBuilder sb = new StringBuilder();
        for(int tc=0;tc<T;tc++){

            int N, M;
            set = new HashSet<>();
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());

            st = new StringTokenizer(br.readLine());
            for(int i=0;i<N;i++){
                set.add(st.nextToken());
            }

            st = new StringTokenizer(br.readLine());
            int cnt =0;
            for(int i=0;i<M;i++){
                if(set.contains(st.nextToken())){
                    cnt++;
                }
            }

            sb.append("#" + (tc+1) + " ").append(cnt).append('\n');
        }
        System.out.println(sb.toString());
    }
}
