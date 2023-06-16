import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;


public class Main {
    static BufferedReader br;
    static StringTokenizer st;
    static StringBuilder sb;
    static int N, K;
    static int arr[];
    static int prefix_sum[];
    public static void main(String[] args) throws Exception{
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine(), " " );
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine(), " ");
        arr = new int[N];
        for(int i=0;i<N;i++) arr[i] = Integer.parseInt(st.nextToken());
        prefix_sum = new int[N+1];

        for(int i=1;i< prefix_sum.length;i++) prefix_sum[i] = prefix_sum[i-1] + arr[i-1];

        HashMap<Integer, Integer> mp = new HashMap<>();
        // 최악의 경우, N * N / 2 -> int 범위 초과
        long answer = 0;
        for(int i=1;i<=N;i++){
            if(prefix_sum[i] == K) answer ++;
            answer += mp.getOrDefault(prefix_sum[i]-K, 0);
            mp.put(prefix_sum[i], mp.getOrDefault(prefix_sum[i], 0) + 1);
        }

        System.out.println(answer);
    }
}