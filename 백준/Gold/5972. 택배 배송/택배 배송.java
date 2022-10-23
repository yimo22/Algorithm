import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static List<List<Node>> l = new ArrayList<>();
    static int[] dist;

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        for(int i = 0; i<=N; i++)
            l.add(new ArrayList<>());

        dist = new int[N+1];
        for(int i = 1; i<=N; i++)
            dist[i] = Integer.MAX_VALUE;

        while(M-->0){
            st = new StringTokenizer(br.readLine());

            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            int value = Integer.parseInt(st.nextToken());

            l.get(A).add(new Node(B, value));
            l.get(B).add(new Node(A, value));
        }

        dijkstra();

        System.out.println(dist[N]);
    }

    static void dijkstra(){
        Queue<Node> q = new PriorityQueue<>();

        q.offer(new Node(1, 0));
        dist[1] = 0;

        while(!q.isEmpty()){
            Node a = q.poll();

            for(int i = 0; i<l.get(a.vertex).size(); i++){
                Node nextV = l.get(a.vertex).get(i);

                if(dist[nextV.vertex] > dist[a.vertex] + nextV.value){
                    dist[nextV.vertex] = dist[a.vertex] + nextV.value;
                    q.offer(new Node(nextV.vertex, dist[nextV.vertex]));
                }
            }
        }
    }
}

class Node implements Comparable<Node>{
    int vertex, value;

    Node(int vertex, int value){
        this.vertex = vertex;
        this.value = value;
    }

    @Override
    public int compareTo(Node a){
        return this.value - a.value;
    }
}