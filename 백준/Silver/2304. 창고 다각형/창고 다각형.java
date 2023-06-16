import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br;
    static StringTokenizer st;
    static StringBuilder sb;
    static int N, L, H;
    static List<Integer[]> list;
    public static void main(String[] args) throws Exception{
        br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        list = new ArrayList<>();
        for(int i=0;i<N;i++) {
            st = new StringTokenizer(br.readLine(), " ");
            L = Integer.parseInt(st.nextToken());
            H = Integer.parseInt(st.nextToken());
            list.add(new Integer[]{L, H});
        }

        // start
        Collections.sort(list, (o1, o2)->{
            return o1[0] - o2[0];
        });
        int prefixSum[] = new int[list.size()+1];
        int sufixSum[] = new int[list.size()+1];
        for(int i=1;i<N+1;i++){
            prefixSum[i] = Math.max(prefixSum[i-1], list.get(i-1)[1]);
        }
        for(int i=N-1;i>=0;i--){
            sufixSum[i] = Math.max(sufixSum[i+1], list.get(i)[1]);
        }

        int answer = 0;
        for(int i=0, pos = list.get(0)[0];pos <= list.get(list.size()-1)[0];){
            if(list.get(i)[0] > pos){
                answer += Math.min(prefixSum[i], sufixSum[i]);
                pos++;
                continue;
            }

            // i번쨰와 pos가 같거나 큰경우
            answer += Math.min(prefixSum[i+1], sufixSum[i]);
            pos++;
            i++;
        }
        System.out.println(answer);
    }
}