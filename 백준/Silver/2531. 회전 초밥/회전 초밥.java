
import java.util.*;
import java.io.*;
import java.util.Map.Entry;

public class Main {
    static int N, D, K, C;
    static int[] arr;
    public static void main(String[] args) throws IOException {
        // Input
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        D = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        arr = new int[2*N];
        for(int i=0;i<N;i++){
            arr[i+N] = arr[i] = Integer.parseInt(br.readLine());
        }

        // init
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int i=0, cnt=0; cnt<K;i++, cnt++){
            map.put(arr[i], map.getOrDefault(arr[i], 0)+1); // 존재하면 ++, 없으면 1
        }

        // start
        int answer = map.size();
        if(!map.containsKey(C)) answer++;
        int left = 0, right = K;
//        System.out.println("_2531.main");
//        for(Entry<Integer, Integer> entry : map.entrySet()){
//            System.out.print("entry.getKey() = " + entry.getKey());
//            System.out.println("entry.getValue() = " + entry.getValue());
//        }
//        System.out.println("_2531.main");

        while(left <= N){
//            System.out.println("left / answer = " + left + " " +  answer);
            // left 를 빼고, right 를 추가
            int w = map.get(arr[left]);
            map.remove(arr[left]);
            if(w-1 > 0) map.put(arr[left], w-1);
            map.put(arr[right], map.getOrDefault(arr[right], 0)+1);

            left++; right++;

            // 해당 되는 갯수를  count하여 answer 갱신
            int cnt = map.size();
            if(!map.containsKey(C)) cnt++;
            answer = Math.max(answer, cnt);
        }

        System.out.println(answer);

    }
}
