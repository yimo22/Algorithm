
import java.util.*;
import java.io.*;
public class Main {
    static final int _PATH_MAX_ = 200;
    static int N, M;
    static int[][] dist;
    static int[][] dp;
    static List<Integer> list;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());

        dist = new int[N+1][N+1];
        dp = new int[N+1][N+1];
        list = new ArrayList<>();

        for(int i=0;i<N;i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<N;j++){
                int w = Integer.parseInt(st.nextToken());
                if(i == j){
                    dist[i+1][j+1] = 0;
                    continue;
                }
                dist[i+1][j+1] = (w == 0) ? _PATH_MAX_ : 1;
            }
        }

        st = new StringTokenizer(br.readLine());
        while(st.hasMoreTokens()) list.add(Integer.parseInt(st.nextToken()));



        // i -> j 까지 갈수 있는지 여부 확인
        // V : [1,200] -> 밸만포드 O(V^3)
        for(int k=1;k<=N;k++){
            for(int i=1;i<=N;i++){
                for(int j=1;j<=N;j++){
                    dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        String answer = "YES";
        for(int i=0;i<list.size()-1;i++){
            int cur = list.get(i), nxt = list.get(i+1);
            if(dist[cur][nxt] == _PATH_MAX_) {
                answer = "NO";
                break;
            }
        }

        System.out.println(answer);
    }
}
