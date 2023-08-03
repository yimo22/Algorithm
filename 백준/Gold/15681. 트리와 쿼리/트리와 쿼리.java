import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br;
    static StringTokenizer st;
    static StringBuilder sb;

    static int N, R, Q;
    static List<Integer>[] adj;
    static int[] depth, _siz;
    static boolean[] visited;
    static void recur(int cur){
        for(Integer nd : adj[cur]){
            if(!visited[nd]){
                visited[nd] = true;
                depth[nd] = depth[cur] + 1;
                recur(nd);
                _siz[cur] += _siz[nd];
            }
        }
        _siz[cur]++;
    }
    public static void main(String[] args) throws Exception{
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());
        Q = Integer.parseInt(st.nextToken());

        adj = new ArrayList[N+1];
        depth = new int[N+1];
        _siz = new int[N+1];
        visited = new boolean[N+1];
        for(int i=1;i<=N;i++) adj[i] = new ArrayList<Integer>();

        int U, V;
        for(int i=0;i<N-1;i++){
            st = new StringTokenizer(br.readLine());
            U = Integer.parseInt(st.nextToken());
            V = Integer.parseInt(st.nextToken());
            adj[U].add(V);
            adj[V].add(U);
        }

        // root
        visited[R] = true;
        depth[R] = 0;
        recur(R);

        for(int i=0;i<Q;i++){
            Integer c = Integer.parseInt(br.readLine());
            System.out.println(_siz[c]);
        }
    }
}