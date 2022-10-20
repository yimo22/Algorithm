

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int N;
    static int[][] map;
    static final int[][] dir = {
            {1, 0}, {0, 1}, {-1, 0}, {0, -1}
    };
    static int idx = 1;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        N = Integer.parseInt(br.readLine());
        while (N != 0) {
            map = new int[N][N];
            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < N; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            // Solve
            Solve();
            idx++;
            N = Integer.parseInt(br.readLine());
        }

        // close
        br.close();
    }

    private static void Solve() {
        // (0,0) -> (n-1, n-1) 까지 최소 경로의 합
        // map[i] : 0 이상 9 이하의 정수
        // N <= 125
        // --> BFS 탐색 with visited 배열

        // init
        int[][] visited = new int[N][N]; // visit[i][j] : i,j 까지의 최소 경로값
        for(int i=0;i<N;i++) for(int j=0;j<N;j++) visited[i][j] = (int)Math.pow(N, 2) * 10;
        Queue<Integer[]> q = new LinkedList<>();
        q.add(new Integer[]{0,0});

        // start
        visited[0][0] = map[0][0];
        while(!q.isEmpty()){
            Integer[] cur = q.poll();

            for (int[] ints : dir) {
                int nx = cur[0] + ints[0];
                int ny = cur[1] + ints[1];

                // boundary check
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

                // 값이 더 작은 경우에만 진행
                if (visited[nx][ny] > visited[cur[0]][cur[1]] + map[nx][ny]) {
                    visited[nx][ny] = visited[cur[0]][cur[1]] + map[nx][ny];
                    q.add(new Integer[]{nx, ny});
                }
            }
        }

        // answer out
        System.out.printf("Problem %d: %d\n", idx, visited[N-1][N-1]);
    }
}

