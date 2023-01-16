

import java.util.Scanner;

public class Solution {
    static int T;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        for(int tc =0; tc<T; tc++){
            int[] arr = new int[10];
            StringBuilder sb = new StringBuilder();
            int sum = 0, min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
            for(int i=0;i<10;i++){
                arr[i] = sc.nextInt();
                sum += arr[i];
                min = Math.min(min, arr[i]);
                max = Math.max(max, arr[i]);
            }
            sum -= min;
            sum -= max;
            sb.append("#").append(tc+1).append(" ");

            sb.append(Math.round((double)sum / (arr.length-2)));
            System.out.println(sb.toString());
        }
    }
}
