

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.AbstractMap;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(bf.readLine());
        int[] arr = new int[N];
        StringTokenizer stringTokenizer = new StringTokenizer(bf.readLine());
        for(int i=0;i<N;i++){
            arr[i] = Integer.parseInt(stringTokenizer.nextToken());
        }

        Solve2467(arr);
    }

    public static void Solve2467(int[] arr){
        // 해당하는 모든 수에 대하여 이분탐색
        int start, end, mid;
        int dist = Integer.MAX_VALUE;
        int[] answer = new int[]{0,0};
        for(int i=0;i<arr.length-1;i++){
            start = i+1;
            end = arr.length;

            while(start +1 < end){
                mid = (start + end) / 2;
                int sum = arr[i] + arr[mid];

                // 해당 조건에 될경우, 정답 update
                if(Math.abs(sum) < dist){
                    dist = Math.abs(sum);
                    answer[0] = arr[i];
                    answer[1] = arr[mid];
                }
                // update idx
                if(sum > 0) {
                    end = mid;
                }else{
                    start = mid;
                }
            }
            mid = (start + end) / 2;
            int _sum = arr[i] + arr[mid];
            if(Math.abs(_sum) < dist){
                dist = Math.abs(_sum);
                answer[0] = arr[i];
                answer[1] = arr[mid];
            }
        }

        System.out.println(answer[0] + " " + answer[1]);

    }
}
