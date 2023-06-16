import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br;
    static StringTokenizer st;
    static StringBuilder sb;
    static int T, N, M;
    static int arr[], brr[];
    static int[] apsum, bpsum;
    public static void main(String[] args) throws Exception{
        // init
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine(), " ");
        T = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(br.readLine());
        arr = new int[N];
        st = new StringTokenizer(br.readLine(), " ");
        for(int i=0;i<N;i++) arr[i] = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(br.readLine());
        brr = new int[M];
        st = new StringTokenizer(br.readLine(), " ");
        for(int i=0;i<M;i++) brr[i] = Integer.parseInt(st.nextToken());

        // prefix
        apsum = new int[N+1];
        bpsum = new int[M+1];

        for(int i=1;i<=N;i++) apsum[i] = apsum[i-1] + arr[i-1];
        for(int i=1;i<=M;i++) bpsum[i] = bpsum[i-1] + brr[i-1];

        // get subset of sum
        HashMap<Integer, Integer> amp = new HashMap<>();
        HashMap<Integer, Integer> bmp = new HashMap<>();
        for(int i=0;i<=N;i++){
            for(int j=i+1; j<=N;j++){
                amp.put(apsum[j]- apsum[i], amp.getOrDefault(apsum[j] - apsum[i], 0) + 1);
            }
        }
        for(int i=0;i<=M;i++){
            for(int j=i+1;j<=M;j++){
                bmp.put(bpsum[j] - bpsum[i], bmp.getOrDefault(bpsum[j] - bpsum[i], 0) + 1);
            }
        }


        // search
        long answer =0;
        for(Integer key : amp.keySet()){
            if(!bmp.containsKey(T - key)) continue;
            answer += (long) amp.get(key) * bmp.get(T-key);
        }
        System.out.println(answer);
    }
}