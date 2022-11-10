import java.util.*;
import java.io.*;

public class Main {
    static int N;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        N = Integer.parseInt(br.readLine());
        boolean[] isContained = new boolean[20+1];
        int bitset = 0;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            String order = st.nextToken();
            if (order.equals("add")) {
                int w = Integer.parseInt(st.nextToken());
                // check
                bitset |= (1 << (w-1));
            } else if (order.equals("check")) {
                int w = Integer.parseInt(st.nextToken());
                int answer = 0;
                if( (bitset & (1 << (w-1))) > 0) answer = 1;
                sb.append(answer + "\n");
            } else if (order.equals("remove")) {
                int w = Integer.parseInt(st.nextToken());
                bitset &= ~(1 << (w-1));
            } else if (order.equals("toggle")) {
                int w = Integer.parseInt(st.nextToken());
                bitset ^= (1 << (w-1));
            } else if (order.equals("all")) {
                bitset |= (~0);
            } else if (order.equals("empty")) {
                bitset = 0;
            }
        }
        bw.write(sb.toString());
        bw.flush();
        bw.close();
        br.close();
    }
}
