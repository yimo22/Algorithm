import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static Long A, B;
    static Integer _cnt;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        A = Long.parseLong(st.nextToken());
        B = Long.parseLong(st.nextToken());

        _cnt = 0;
        recur("");
        System.out.println(_cnt);
    }

    public static void recur(String str){
        if("".equals(str) || Long.parseLong(str) < A){
            recur(str + "4");
            recur(str + "7");
            return;
        }
        Long value = Long.parseLong(str);
        if(value > B) return ;

        _cnt++;
        recur(str + "4");
        recur(str + "7");
        return;
    }

}