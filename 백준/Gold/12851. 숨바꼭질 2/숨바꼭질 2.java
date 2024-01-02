import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br;
    static StringTokenizer st;
    static StringBuilder sb;

    static int N, K;
    static final int INF = 100000;
    public static void main(String[] args) throws Exception{
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        // {위치, 시간}
        Queue<Integer[]> que = new ArrayDeque<>();
        int[] visited = new int[2 * INF +1];
        int[] ans = new int[2 * INF + 1];
        Arrays.fill(visited, INF);

        que.add(new Integer[]{N, 0});

        while(!que.isEmpty()){
            Integer[] cur = que.peek(); que.poll();
            int pos = cur[0];
            int time = cur[1];

            if(visited[pos] >= time){
                if(visited[pos] > time) ans[pos] = 0;
                visited[pos] = time;
                ans[pos]++;

                if(pos -1 >= 0)
                    que.add(new Integer[]{pos-1, time+1});

                if(pos + 1 < 2 * INF + 1)
                    que.add(new Integer[]{pos+1, time+1});

                if(pos * 2 < 2 * INF + 1)
                    que.add(new Integer[]{pos * 2, time + 1});
            }
        }

        System.out.println(visited[K] + "\n" + ans[K]);
    }
}