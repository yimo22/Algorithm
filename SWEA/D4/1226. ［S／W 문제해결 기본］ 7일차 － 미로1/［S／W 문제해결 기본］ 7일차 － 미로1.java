
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

/*
   사용하는 클래스명이 Solution 이어야 하므로, 가급적 Solution.java 를 사용할 것을 권장합니다.
   이러한 상황에서도 동일하게 java Solution 명령으로 프로그램을 수행해볼 수 있습니다.
 */
class Solution {
    static Pos start, end;
    static int[][] map;
    static final int _MAX = 16;
    static final int dir[][] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    public static void main(String args[]) throws Exception {
		/*
		   아래의 메소드 호출은 앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
		   여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
		   이 코드를 프로그램의 처음 부분에 추가하면 이후 입력을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
		   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 메소드를 사용하셔도 좋습니다.
		   단, 채점을 위해 코드를 제출하실 때에는 반드시 이 메소드를 지우거나 주석 처리 하셔야 합니다.
		 */
//        System.setIn(new FileInputStream("C:\\Users\\rladu\\Downloads\\input (4).txt"));

		/*
		   표준입력 System.in 으로부터 스캐너를 만들어 데이터를 읽어옵니다.
		 */
        Scanner sc = new Scanner(System.in);
        StringBuilder sb;
        int T;
        T = 10;
		/*
		   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
		*/

        for (int test_case = 1; test_case <= T; test_case++) {
            int tc = sc.nextInt();
            sb = new StringBuilder();
            map = new int[_MAX][_MAX];
            for (int i = 0; i < _MAX; i++) {
                String str = sc.next();
                for (int j = 0; j < _MAX; j++) {
                    map[i][j] = str.charAt(j) - '0';
                    if (map[i][j] == 2) start = new Pos(j, i);
                    if (map[i][j] == 3) end = new Pos(j, i);
                }
            }
            sb.append("#").append(tc).append(" ").append(Solve());
            System.out.println(sb);
        }
    }

    private static int Solve() {
        // bfs 탐색
        // init
        Queue<Pos> q = new LinkedList<>();
        boolean[][] visited = new boolean[_MAX][_MAX];

        // set
        q.add(new Pos(start.x, start.y));
        visited[start.y][start.x] = true;
        map[start.y][start.x] = map[end.y][end.x] = 0;

        // start
        while(!q.isEmpty()){
            Pos cur = q.poll();
            // check
            if(cur.x == end.x && cur.y == end.y){
                return 1;
            }

            // progress
            for(int[] d : dir){
                int nx = cur.x + d[0];
                int ny = cur.y + d[1];

                // progress
                if(!visited[ny][nx] && map[ny][nx] == 0){
                    visited[ny][nx] = true;
                    q.add(new Pos(nx, ny));
                }
            }
        }
        return 0;
    }

    static class Pos {
        int x, y;

        public Pos(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public String toString() {
            return "Pos{" +
                    "x=" + x +
                    ", y=" + y +
                    '}';
        }
    }
}