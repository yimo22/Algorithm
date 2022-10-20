

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    static int N, M;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        HashMap<String, Integer> map = new HashMap<>();

        for(int i=0;i<N;i++){
            map.put(br.readLine(), 0);
        }

        // start
        for(int i=0;i<M;i++){
            st = new StringTokenizer(br.readLine(), ",");
            while(st.hasMoreTokens()){
                String cur = st.nextToken();
                map.remove(cur);
            }
            System.out.println(map.size());
        }

    }
}
