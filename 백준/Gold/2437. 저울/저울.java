import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static int N;
    static List<Integer> list;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        list = new ArrayList<>();
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0;i<N;i++){
            list.add(Integer.valueOf(st.nextToken()));
        }
        Solution();
    }

    private static void Solution() {
        // list에 주어진 추들로 측정할 수 없는 양의 정수 무게 중 최소값을 출력
        // 완전탐색 : N! -> TO
        // 가능한 무게 : [1,1_000_000_000]

        // 가장 최소의 불가능한 무게를 고르므로, sort 하여 작은 무게부터 선택
        Collections.sort(list);

        int start= 0, end=0;
        for(int w : list){
            int ns = start + w;
            int ne = end + w;

            // 두 구간이 연속되는지 판단
            if(ns-1 <= end){
                end = ne;
            } else break;
        }

        // end + 1 이 만들수 없는 최소의 무게임.
        System.out.println(end+1);
    }
}
