import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N, M, K;
    static int[][][] sharkDir; // idx 가 i인 상어의 방향이 j 일때 방향우선순위들
    static int[][] dir = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    }; // 위, 아래, 왼쪽, 오른쪽
    static int[][][] smell; // smell[i,j,0] : smell 시간, smell[i,j,1] : 냄새를 낸 상어의 index
    static int[][] map;
    private static ArrayList<Shark> sharkList;
    private static Queue<Integer[]> smellList;
    static int curSharkCount;

    public static void main(String[] args) throws Exception {
        // 1000 보다 오래 걸릴경우 -> -1 출력
        //
        init();

        int answer = 0;
        // 초기조건
        for (Shark sk : sharkList) {
            smell[sk.x][sk.y][0] = K;
            smell[sk.x][sk.y][1] = sk.idx;
        }

        while (true) {
            // 상어 Move
            sharkMove();
            // 냄새 제거
            smellRemove();

            answer++;
            if (curSharkCount == 1 || answer > 1000) break;
        }

        if (answer > 1000) System.out.println(-1);
        else {
            System.out.println(answer);
        }
    }

    static void smellRemove() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (smell[i][j][0] > 1) smell[i][j][0]--;
                else {
                    smell[i][j][0] = smell[i][j][1] = 0;
                }
            }
        }

        // list 추가
        while (!smellList.isEmpty()) {
            Integer[] cur = smellList.poll();
            smell[cur[0]][cur[1]][0] = K;
            smell[cur[0]][cur[1]][1] = cur[2];
        }
    }

    /**
     * 상어를 이동
     */
    static void sharkMove() {
        // shark존재 여부 배열 초기화
        boolean[][] isShark = new boolean[N][N];

        for (int i = 0; i < sharkList.size(); i++) {
            Shark cur = sharkList.get(i);
            // 샤크가 죽은 경우 pass
            if (cur.isAlive == false) continue;

            // 이동
            // 인접한 칸에 빈 칸이 있는지 check
            int cnt = 0;
            for (int[] nd : dir) {
                int nx = cur.x + nd[0];
                int ny = cur.y + nd[1];

                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

                if (smell[nx][ny][0] > 0) continue;
                cnt++;
            }
            if (cnt > 0) {
                // 빈칸이 여러개 있을 경우 or 1칸 있을 경우
                // 우선순위에 따라서 이동 or 해당칸으로 이동
                for (int rep = 0; rep < 4; rep++) {
                    int nd = sharkDir[cur.idx][cur.d][rep];
                    int nx = cur.x + dir[nd][0];
                    int ny = cur.y + dir[nd][1];

                    // boundary check
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

                    // 가능한 경우
                    if (smell[nx][ny][0] == 0) {
                        // 이미 샤크가 있는 경우
                        if (isShark[nx][ny]) {
                            cur.isAlive = false;
                            curSharkCount--;
                            break;
                        }

                        // 이동
                        isShark[nx][ny] = true;
                        cur.x = nx;
                        cur.y = ny;
                        cur.d = nd;
                        smellList.add(new Integer[]{nx, ny, cur.idx});

                        break;
                    }
                }
            } else {
                // 빈칸이 없을 경우 (냄새가 없는 칸)
                // 우선순위에 맞춰서 칸을 이동한다.
                for(int rep=0; rep<4; rep++){
                    int nd = sharkDir[cur.idx][cur.d][rep];
                    int nx = cur.x + dir[nd][0];
                    int ny = cur.y + dir[nd][1];

                    // boundary check
                    if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    // smell check
                    if(smell[nx][ny][1] == cur.idx){
                        isShark[nx][ny] = true;
                        cur.x = nx;
                        cur.y = ny;
                        cur.d = nd;
                        smellList.add(new Integer[]{nx,ny,cur.idx});
                        break;
                    }
                }
            } // if-else 문 종료
        } // 샤크 for문 종료
    } // sharkMove 종료


    static void init() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        map = new int[N][N];
        smell = new int[N][N][2];
        sharkList = new ArrayList<Shark>();
        smellList = new LinkedList<>();
        sharkDir = new int[M+1][4][4];
        curSharkCount = M;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                if (map[i][j] > 0) {
                    sharkList.add(new Shark(map[i][j], i, j, -1));
                }
            }
        }
        // 상어 번호에 따라 정렬
        Collections.sort(sharkList, (o1, o2) -> {
            return o1.idx - o2.idx;
        });

        // 상어 방향 input
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < M; i++) {
            sharkList.get(i).d = Integer.parseInt(st.nextToken()) - 1;
        }


        // 상어 방향순위 input
        for (int i = 0; i < M; i++) {
            /* dir의 방향 순서 : 위(0) > 아래(1) > 왼쪽(2) > 오른쪽(3) */
            /* 입력 방향 순서 : 위 > 아래 > 왼쪽 > 오른쪽 */
            for(int j=0;j<4;j++){
                st =new StringTokenizer(br.readLine());
                for(int rep=0;rep<4;rep++){
                    sharkDir[i+1][j][rep] = Integer.parseInt(st.nextToken()) -1;
                }
            }

        }
    }

    static class Shark {
        int idx;
        int x, y;
        int d;
        boolean isAlive;

        public Shark(int idx, int x, int y, int d) {
            this.idx = idx;
            this.x = x;
            this.y = y;
            this.d = d;
            isAlive = true;
        }

        @Override
        public String toString() {
            return "Shark{" +
                    "idx=" + idx +
                    ", x=" + x +
                    ", y=" + y +
                    ", d=" + d +
                    ", isAlive=" + isAlive +
                    '}';
        }
    }

    /** debug Util */
    static void printSmell(){
        for(int i=0;i<smell.length;i++){
            for(int j=0;j<smell[i].length;j++){
                System.out.print("[" +smell[i][j][0] + " " + smell[i][j][1] + "] ");
            }
            System.out.println();
        }
    }

    static void printShakrState(){
        for(Shark c : sharkList){
            System.out.println(c);
        }
    }
}
