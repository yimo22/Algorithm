import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static int P;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        P = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        for(int tc=0; tc<P; tc++){
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            int testCase = Integer.parseInt(st.nextToken());
            int arr[] = new int[20];
            for(int i=0;i<20;i++) arr[i] = Integer.parseInt(st.nextToken());

            sb.append(testCase + " ");
            sb.append(Solve(arr) + "\n");
        }
        System.out.println(sb.toString());
    }

    private static int Solve(int[] arr) {
        List<Integer> list = new ArrayList<>();
        int count = 0;
        for(int i=0;i<arr.length;i++){
            list.add(arr[i]);
            // 앞에 존재하는지 탐색
            for(int j=0;j<i;j++){
                if(list.get(j) > list.get(i)){
                    Integer value = list.get(list.size()-1);
                    list.remove(list.size()-1);
                    list.add(j, value);
                    count += (i - j);
                    break;
                }
            }


        }
        return count;
    }

}
