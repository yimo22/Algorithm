import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static int N ,S;
    static int cnt;
    static int[] arr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());
        arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for(int i=0;i<N;i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        // 부분집합
        dfs(0, 0);
        if(S == 0) cnt--;
        System.out.println(cnt);
    }
    static void dfs(int depth, int sum){
        if(depth >= arr.length) {
            if(sum == S) cnt++;
            return;
        }
        // 사용
        dfs(depth+1, sum + arr[depth]);
        // 사용안함
        dfs(depth+1, sum);
    }
}
