import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br;
    static StringTokenizer st;
    static StringBuilder sb;
    static int H, W;
    static int arr[];
    public static void main(String[] args) throws Exception{
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine(), " ");
        H = Integer.parseInt(st.nextToken());
        W = Integer.parseInt(st.nextToken());
        arr = new int[W];
        st = new StringTokenizer(br.readLine(), " ");
        for(int i=0;i<W;i++) arr[i] = Integer.parseInt(st.nextToken());

        // start
        int pmax[] = new int[W+1];
        int smax[] = new int[W+1];
        for(int i=1;i<=W;i++) pmax[i] = Math.max(arr[i-1], pmax[i-1]);
        for(int i=W-1;i>=0;i--) smax[i] = Math.max(smax[i+1], arr[i]);

        int fill[] = new int[W+1];
        int answer =0;
        for(int i=1;i<=W;i++) {
            fill[i] = Math.min(pmax[i], smax[i-1]);
            answer += fill[i] - arr[i-1];
        }
        System.out.println(answer);

    }
}