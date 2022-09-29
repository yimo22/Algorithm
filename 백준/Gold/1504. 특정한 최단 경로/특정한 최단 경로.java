

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.util.*;
class Node implements Comparable<Integer>{
    int end;
    int weight;

    Node(int e, int w){
        this.end = e;
        this.weight = w;
    }
    @Override
    public int compareTo(Integer o){
        return 0;
    }
}
class Info{
    int idx;
    int distance;
    Info(int nodeIndex, int distance){
        this.idx = nodeIndex;
        this.distance = distance;
    }

    @Override
    public String toString() {
        return idx + " "  + distance;
    }
}
public class Main {
    static final int MAX = 200000;
    static final int MAX_PATH = 1000 * 200000;
    static int V1, V2;
    static int N, E;
    static ArrayList<ArrayList<Node>> adj = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(br.readLine());

         N = Integer.parseInt(stringTokenizer.nextToken()); E = Integer.parseInt(stringTokenizer.nextToken());

         // 양방향 인접리스트 구현
        for(int i=0;i<=N;i++){
            adj.add(new ArrayList<>());
        }
        for(int i=0;i<E;i++){
            stringTokenizer = new StringTokenizer(br.readLine());
            int s, e, w;
            s = Integer.parseInt(stringTokenizer.nextToken()); e = Integer.parseInt(stringTokenizer.nextToken()); w = Integer.parseInt(stringTokenizer.nextToken());
            adj.get(s).add(new Node(e,w));
            adj.get(e).add(new Node(s,w));
        }

        stringTokenizer = new StringTokenizer(br.readLine());
        V1 = Integer.parseInt(stringTokenizer.nextToken()); V2 = Integer.parseInt(stringTokenizer.nextToken());



        Solve();
    }

    public static void Solve(){
        // 1번 정점에서 출발하여, V1과 V2를 반드시 거쳐, N까지 도달하는 최소의 경로길이
        // 다익스트라 를 통해서 1->다른 모든 정점까지의 최소 길이를 구한다.
        // v1 -> v2 || v2 -> v1 중 최소값을 택한다.
        // 경로가 없을 경우 -1을 출력한다.

        int res1 = dijkstra(1, V1) + dijkstra(V2, N) + dijkstra(V1, V2);
        int res2 = dijkstra(1, V2) + dijkstra(V1, N) + dijkstra(V1, V2);
        int answer;
        answer = (res1 >= MAX_PATH && res2 >= MAX_PATH) ? -1 : Math.min(res1, res2);
        System.out.println(answer);
    }

    static int dijkstra(int start, int end){
        // start -> end 로 가는 최단 경로
        Integer[] dist = new Integer[N+1];
        for(int i=0;i<=N;i++) dist[i] = MAX_PATH;
        dist[start] = 0;
        PriorityQueue<Info> pq = new PriorityQueue<>(new Comparator<Info>() {
            @Override
            public int compare(Info o1, Info o2) {
                return o1.distance > o2.distance ? 1 : -1;
            }
        });

        pq.add(new Info(start, 0));
        while(!pq.isEmpty()){
            Info cur = pq.poll();
//            System.out.println("cur = " + cur);
            // 이미 알고있는 거리가 더 짧은 경우 -> pass
            if(dist[cur.idx] < cur.distance) continue;

            // 인접한 노드에 대하여
            for(Node nxt : adj.get(cur.idx)){
                int nxtIdx = nxt.end;
                int nxtDist = nxt.weight + cur.distance;
//                System.out.println("nxt : " + nxtIdx + " " + nxtDist);
                if(dist[nxtIdx] > nxtDist){
//                    System.out.println("\tpushed : " + nxtIdx + " " + nxtDist);
                    dist[nxtIdx] = nxtDist;
                    pq.add(new Info(nxtIdx, nxtDist));
                }
            }
        }

        // start -> end 까지의 최소거리 return
        return dist[end];
    }
}
