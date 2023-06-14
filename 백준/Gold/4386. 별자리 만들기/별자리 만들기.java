import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static Double list[][];
    static List<Edge> edges;
    static int parent[];
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        N = Integer.parseInt(st.nextToken());
        list = new Double[N][2];
        parent = new int[N];
        edges = new ArrayList<>();
        for(int i=0;i<N;i++){
            parent[i] = i;
            st = new StringTokenizer(br.readLine(), " ");
            list[i][0] = Double.parseDouble(st.nextToken());
            list[i][1] = Double.parseDouble(st.nextToken());
        }


        // get Edge info
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                edges.add(new Edge(i, j, getDist(i, j)));
            }
        }

        // Kruskal
        Collections.sort(edges, (o1, o2) -> {
            return o1.dist - o2.dist > 0 ? 1 : -1;
        });

        double answer = 0;
        for(Edge e : edges){
            if(getParent(e.n1) == getParent(e.n2)) continue;

            union(e.n1, e.n2);
            answer += e.dist;
        }
        System.out.println(answer);
    }

    static int union(int a, int b){
        int pa = getParent(a);
        int pb = getParent(b);

        if(pa == pb) return 0;

        if(pa < pb){
            parent[pb] = pa;
        }
        else{
            parent[pa] = pb;
        }
        return 1;
    }
    static int getParent(int a){
        if(a == parent[a]) return a;
        else return parent[a] = getParent(parent[a]);
    }
    static double getDist(int n1, int n2){
        return Math.sqrt(Math.pow(list[n1][0] - list[n2][0], 2) + Math.pow(list[n1][1] - list[n2][1], 2));
    }
    static class Edge{
        int n1;
        int n2;
        double dist;
        Edge(int n1, int n2, double dist){
            this.n1 = n1;
            this.n2 = n2;
            this.dist = dist;
        }
    }
}