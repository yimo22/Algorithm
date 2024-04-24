import java.util.*;
import java.io.*;

public class Main {
    static Long N, K;
    static Map<Long, Long> mp;
    static List<Node> list;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Long.parseLong(st.nextToken());
        K = Long.parseLong(st.nextToken());
        mp = new HashMap<>();
        list = new ArrayList<>();
        for(int i=0;i<N;i++){
            st = new StringTokenizer(br.readLine());
            int X, Y;
            X = Integer.parseInt(st.nextToken());
            Y = Integer.parseInt(st.nextToken());
            list.add(new Node(X, Y));
            // b = y - K * x
            mp.put(Y - K * X, mp.getOrDefault(Y - K * X, 0L) + 1);
        }
        Long answer = 0L;
        for(Node node : list){
            answer += mp.getOrDefault(node.y - K * node.x, 1L) - 1;
        }

        System.out.println(answer);
    }

    static class Node{
        int x, y;
        Node(int x, int y){ this.x = x; this.y = y;}
    }

}