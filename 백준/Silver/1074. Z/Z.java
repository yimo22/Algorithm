import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, R, C;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        // start
        System.out.println(divide(R, C, N));

    }

    static int divide(int x, int y,  int n){
        // 기저 조건
        if(n == 1){
            // 4개의 위치를 파악해서 종료
            if(x == 0 && y == 0) return 0;
            else if(x == 0 && y == 1) return 1;
            else if (x == 1  && y == 0) return 2;
            else return 3;
        }

        // 현재 좌표의 위치를 파악
        int len = (int) Math.pow(2, n); // 한 변의 길이
        int pivot = (len >> 1);
        int mul = 0;
        if(pivot <= x && pivot <= y){
            mul = 3;
        }
        else if(pivot <= x && pivot > y){
            mul = 2;
        }
        else if(pivot > x && pivot <= y){
            mul = 1;
        }
        else mul = 0;

        return pivot * pivot * mul +  divide(x % pivot, y%pivot, n-1);
    }
}
