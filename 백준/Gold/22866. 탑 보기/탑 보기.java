


import java.util.*;
import java.io.*;
public class Main {
    static int N;
    static int[] arr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        N = Integer.parseInt(br.readLine());
        arr = new int[N+1];

        st = new StringTokenizer(br.readLine());
        for(int i=1;i<=N;i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Solve();
    }

    private static void Solve() {
        // 해당 하는 탑에서의 보이는 건물의 갯수 return
        // 건물이 1개 이상이라면, 가장 가까운 건물(최소 번호)번호 출력
        // init
        Stack<Node> stack = new Stack<>();
        int[] cnt = new int[N+1];
        int[][] near = new int[N+1][2];
        for(int[] row : near) Arrays.fill(row, Integer.MAX_VALUE);
        // start
        for(int i=1;i<=N;i++){
            // pop out
            while(!stack.isEmpty() && stack.peek().height <= arr[i]) stack.pop();

            // answer update
            cnt[i] += stack.size();

            // idx update
            if(!stack.isEmpty()){
                int gap = Math.abs(stack.peek().num - i);
                if(gap < near[i][0]){
                    near[i][0] = gap;
                    near[i][1] = stack.peek().num;
                }else if(gap == near[i][0]) near[i][1] = Math.min(near[i][1], stack.peek().num);
            }

            // add
            stack.add(new Node(i, arr[i]));
        }

        stack.clear();

        for(int i=N; i>=1; i--){
            while(!stack.isEmpty() && stack.peek().height <= arr[i]) stack.pop();

            cnt[i] += stack.size();

            if(!stack.isEmpty()){
                int gap = Math.abs(i - stack.peek().num);
                if(gap < near[i][0]){
                    near[i][0] = gap;
                    near[i][1] = stack.peek().num;
                }else if(gap == near[i][0]) near[i][1] = Math.min(near[i][1], stack.peek().num);

            }

            stack.push(new Node(i, arr[i]));
        }

        // answer out
        for(int i=1;i<=N;i++){
            System.out.print(cnt[i]);
            if(cnt[i] > 0) System.out.print(" " + near[i][1]);
            System.out.println();
        }
    }

    private static class Node{
        int num, height;

        public Node(int num, int height) {
            this.num = num;
            this.height = height;
        }
    }

}
