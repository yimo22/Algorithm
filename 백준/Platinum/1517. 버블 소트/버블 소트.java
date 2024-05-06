import java.util.*;
import java.io.*;
import java.util.stream.Collectors;

public class Main {
    static BufferedReader br;
    static StringTokenizer st;
    static int N;
    static Pair[] arr;
    static final int _INDENT_ = 1_000_000_000;
    static int[] tree;
    static Map<Integer, List<Integer>> mp;
    public static void main(String[] args) throws Exception{
//        System.setIn(new FileInputStream("src/com/home/input.txt"));
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        arr = new Pair[N];
        tree = new int[N * 4];
        // 1 <= N <= 500K
        // 0 <= A[i] <= 1B
        mp = new HashMap<>();
        st = new StringTokenizer(br.readLine());
        Long ans = 0L;

        for(int i=1;i<=N;i++){
            arr[i-1] = new Pair(i-1, Integer.parseInt(st.nextToken()));
        }

        // Sorting
        Arrays.sort(arr, (o1, o2) -> {
            return o1.y - o2.y;
        });

        int [] list = new int[N];
        SegmentTree sTree = new SegmentTree(N);
        for(int i=0;i<N;i++){
            list[i] = arr[i].y;
            ans += sTree.get(arr[i].x + 1, N);
            sTree.update(arr[i].x + 1, 1);
        }

        System.out.println(ans);
    }
    static class Pair{
        int x, y;
        Pair(int x, int y) {this.x = x; this.y = y;}
    }

    static class SegmentTree{
        int [] arr;
        int _size;
        SegmentTree(int N){
            this.arr = new int[N * 4];
            this._size = N;
        }

        SegmentTree(int [] _ary){
            this._size = _ary.length;
            this.arr = new int[_size * 4];
            setArr(1, 1, N, _ary);
        }

        private void setArr(int idx, int l, int r, int [] origin){
            if(l > r) return;

            if( l== r){
                this.arr[idx] = origin[l-1];
                return;
            }

            int mid = l + (r-l) / 2;
            setArr(idx * 2, l, mid, origin);
            setArr(idx * 2 + 1, mid + 1, r, origin);

            arr[idx] = arr[idx * 2] + arr[idx * 2 + 1];
        }

        /**
         * Position 위치의 값을 value 만큼 증분시킴
         * @param position
         * @param value
         */
        void update(int position, int value){
            recur(1, 1, _size, position, value);
        }

        void recur(int idx, int l, int r, int pos, int val){
            // 범위 out
            if(pos < l || pos > r) return;

            // leaf-Node
            if(l == r){
                arr[idx] += val;
                return;
            }

            // non-leaf
            int mid = l + (r-l) / 2;
            recur(idx * 2, l, mid, pos, val);
            recur(idx * 2 + 1, mid + 1, r, pos, val);
            arr[idx] = arr[idx *2] + arr[idx * 2 + 1];
        }
        int get(int l, int r){
            return getValue(1, 1, _size, l, r);
        }

        /**
         * lb ~ rb 사이 범위의 값을 리턴
         * @param l
         * @param r
         * @return
         */
        int getValue(int idx, int l, int r, int lb, int rb){
            if(r < lb || rb < l) return 0;
            if(l == r) return arr[idx];
            // 완전 안에 겹치는 경우
            if(lb <= l && r <= rb) return arr[idx];

            // 중간에 걸치는 경우
            int mid = l + (r - l) / 2;
            return getValue(idx * 2, l, mid, lb, rb) + getValue(idx * 2 + 1, mid + 1, r, lb, rb);
        }
    }
}