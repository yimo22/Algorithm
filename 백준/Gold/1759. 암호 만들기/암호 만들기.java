import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static int L, C;
    static char[] arr;
    static char[] ans;
    static int checkBit;
    static int checkBit2;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        L = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        arr = new char[C];
        ans = new char[L];
        for(int i=0;i<C;i++){
            arr[i] = st.nextToken().charAt(0);
        }
        /* make check bit */
        checkBit |= (1 << ('a' - 'a'));
        checkBit |= (1 << ('e' - 'a'));
        checkBit |= (1 << ('i' - 'a'));
        checkBit |= (1 << ('o' - 'a'));
        checkBit |= (1 << ('u' - 'a'));
        checkBit2 = ((1 << ('z' - 'a' + 1)) - 1);
        checkBit2 ^= checkBit;
        /* making check end*/

        Arrays.sort(arr);
        comb(0, 0, 0);
    }
    static void comb(int start, int pos, int used){
        if(pos >= ans.length){
            // 자음이 2개 이상있는지, 모음이 1개 이상있는지 check
            int res = (int) (Math.log(used & checkBit2) / Math.log(2));
            if((used & checkBit) != 0 && (res != (Math.log(used & checkBit2) / Math.log(2))) && res > 0 ){
                for(char c : ans){
                    System.out.print(c);
                }
                System.out.println();
            }
            return;
        }

        for(int i=start; i<arr.length;i++){
            ans[pos] = arr[i];
            comb(i+1, pos+1, used | (1 << (ans[pos] - 'a')));
        }
    }
}
