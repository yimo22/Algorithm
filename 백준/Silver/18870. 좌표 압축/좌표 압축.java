

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(buff.readLine());
        int[] arr = new int[N];
        StringTokenizer stringtk = new StringTokenizer(buff.readLine());
        for(int i=0;i<N;i++){
            arr[i] = Integer.parseInt(stringtk.nextToken());
        }

        Solve(arr);
    }

    public static void Solve(int[] value){

        Map<Integer, Integer> map = new HashMap<Integer, Integer>();

        int[] arr = value.clone();
        Integer[] tmpArr = Arrays.stream(arr).boxed().toArray(Integer[]::new);
        // 중복 제거후 sorting
        HashSet<Integer> arrSet = new HashSet<Integer>(Arrays.asList(tmpArr));
        Integer[] newArr = arrSet.toArray(new Integer[0]);
        Arrays.sort(newArr);

        int idx = 0;
        for(int w : newArr){
            map.put(w, idx++);
        }

        // printout
        StringBuilder answer = new StringBuilder();
        for(int w : value){
            answer.append(map.get(w)).append(' ');
        }

        System.out.println(answer);
    }
}
