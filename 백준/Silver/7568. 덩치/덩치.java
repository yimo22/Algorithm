import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    private static int N;
    static int[][] list;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        list = new int[N][2];
        for(int i=0;i<N;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            list[i][0] = Integer.parseInt(st.nextToken());
            list[i][1] = Integer.parseInt(st.nextToken());
        }
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<N;i++){
            int k = 0;
            for(int j=0;j<N;j++){
                if(list[i][0] < list[j][0] && list[i][1] < list[j][1]){
                    k++;
                }
            }
            sb.append(k+1).append(' ');
        }
        System.out.println(sb.toString());
    }
    static class Node{
        int idx;
        int weight;
        int height;
        int rank;
        public Node(int idx, int weight, int height) {
            this.idx = idx;
            this.weight = weight;
            this.height = height;
        }
    }
}
