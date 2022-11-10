import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    static int G, P;
    static int[] arr;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        G = Integer.parseInt(br.readLine());
        P = Integer.parseInt(br.readLine());
        arr = new int[P];
        for(int i=0;i<P;i++) arr[i] = Integer.parseInt(br.readLine());
        
        Solution();
    }

    private static void Solution() {
        // 최대한 뒤쪽으로 비행기를 배치한다.
        // Union-find 를 통한 최적화
        // p[i] : 해당 최대 게이트가 i일때, 들어갈 Gate 번호

        // init
        int[] p = new int[G+1];
        int answer = 0;
        for(int i=0;i<p.length;i++) p[i] = i;

        for(int i=0;i<arr.length;i++){
            int w = arr[i];
            if(getp(p, w) > 0){
                answer++;
                union(p, getp(p, w), getp(p, w)-1);
            }else break;
//            System.out.println(Arrays.toString(p));
        }
        System.out.println(answer);
    }

    private static int getp(int[] p, int w) {
        if(p[w] == w) return w;
        else{
            return p[w] = getp(p, p[w]);
        }
    }

    private static void union(int[] set, int a, int b){
        // a와 b 중에서 더 작은 것으로 union
        int pa = getp(set, a);
        int pb = getp(set, b);

        if(pa < pb){
            set[b] = pa;
        }else set[a] = pb;
    }
}
