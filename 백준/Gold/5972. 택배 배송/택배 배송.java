
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static int N, M;
    static ArrayList<Node>[] adj;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        // init
        adj = new ArrayList[N + 1];
        for(int i=0;i<adj.length;i++) adj[i] = new ArrayList<>();
        int s, e, w;
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            s = Integer.parseInt(st.nextToken());
            e = Integer.parseInt(st.nextToken());
            w = Integer.parseInt(st.nextToken());
            adj[s].add(new Node(e, w));
            adj[e].add(new Node(s, w));
        }

        // 1 -> V 까지의 최소 경로 구하기
        // Dijkstra
        System.out.println(Dijkstra(1));
    }


    private static int Dijkstra(int start) {

        // start -> N 까지의 최소 경로구하기
        // init
        int[] dist = new int[N+1];
        for(int i=1;i<=N;i++) dist[i] = Integer.MAX_VALUE;
        PriorityQueue<Node> pq = new PriorityQueue<>(new Comparator<Node>(){
            @Override
            public int compare(Node o1, Node o2){
                return o1.w < o2.w ? -1 : 1;
            }
        });

        // start
        dist[start] = 0;
        pq.add(new Node(start, 0)); // {vertex, distance}
        while(!pq.isEmpty()){
            Node cur = pq.poll();
            int v = cur.dest;
            int w = cur.w;

            if(dist[v] < w) continue;

            for(Node nxt : adj[cur.dest]){
                int nv = nxt.dest;
                int nw = w + nxt.w;

                if(dist[nv] > nw){
                    dist[nxt.dest] = nw;
                    pq.add(new Node(nv, nw));
                }
            }
        }

        // answer out
        return dist[N];
    }

    static class Node {
        int dest;
        int w;

        Node(int dest, int w) {
            this.dest = dest;
            this.w = w;
        }
    }
}
