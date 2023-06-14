import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int N, M;
    static int arr[];
    static int dp[][];
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        arr = new int[N];
        dp = new int[N][N];
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        for(int i=0;i<N;i++) arr[i] = Integer.parseInt(st.nextToken());
        for(int i=0;i<dp.length;i++) Arrays.fill(dp[i], -1);
        M = Integer.parseInt(br.readLine());
        int s, e;
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<M;i++){
            st = new StringTokenizer(br.readLine(), " ");
            s = Integer.parseInt(st.nextToken());
            e = Integer.parseInt(st.nextToken());
            sb.append(search(s-1, e-1)).append("\n");
        }
        System.out.println(sb.toString());
    }
    private static int search(int s, int e){
        if(e - s <= 1){
            return dp[s][e] = (arr[s] == arr[e]) ? 1 : 0;
        }
        if(dp[s][e] != -1) return dp[s][e];
        if(arr[s] != arr[e]) return dp[s][e] = 0;
        return dp[s][e] = search(s+1, e-1);
    }
}
