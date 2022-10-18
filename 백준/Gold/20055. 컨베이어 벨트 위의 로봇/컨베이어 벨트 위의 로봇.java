
import java.util.*;
import java.io.*;

public class Main {
    static int N, K;
    static int MODULO;
    static Belt[] arr;
    static int[] isRobot;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.valueOf(st.nextToken());
        K = Integer.valueOf(st.nextToken());

        // init
        arr = new Belt[2 * N];
        isRobot = new int[N];
        MODULO = 2 * N;
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 2 * N; i++) {
            arr[i] = new Belt(Integer.valueOf(st.nextToken()), false);
        }

        // start
        // 한칸씩 회전
        // 내구도 0인 벨트가 최대 K개 일떄 종료, -> 종료될때의 단계를 구하라
        // 로봇은 이동 -> 내구도 != 0 && 이동하려는 칸에 로봇이 없음
        // ! 가장 먼저 벨트에 올라간 로봇부터 이동을 시작
        // ! 언제든지 로봇이 내리는 위치에 도달하면 그 즉시 내린다.
        // 로봇을 올리는 위치에 올림 or 로봇이 어떤 칸으로 이동 -> 그 칸의 내구도는 1 감소

        List<Integer> robots = new ArrayList<>(); // robot 의 beltIdx 관리하는 list
        int _cnt = 0; // 내구도가 0인 벨트의 갯수
        int answer = 0;
        int robotIdx = 0;
        while (_cnt < K) {
            // 벨트 이동
            Belt tmp = arr[arr.length - 1];
            for (int i = arr.length - 1; i > 0; i--) {
                arr[i] = arr[i - 1];
            }
            arr[0] = tmp;

            // 내리는 위치 로봇 move
            if (arr[N - 1].isRobot) arr[N - 1].isRobot = false;


            // 가장 먼저 올라간 로봇부터, 회전방향으로 이동 실시 (불가능 할시 stay)
            for (int i = N - 2; i >= 0; i--) {
                if (!arr[i + 1].isRobot && arr[i].isRobot && arr[i + 1].health > 0) {
                    arr[i + 1].isRobot = true;
                    arr[i + 1].health--;
                    arr[i].isRobot = false;
                }
            }
            arr[N-1].isRobot = false;

            // 올리는 위치를 check, 가능하면 로봇을 올린다.
            if (arr[0].health > 0) {
                arr[0].isRobot = true;
                arr[0].health--;
            }

            // 내구도 0 인 벨트수 check
            _cnt = 0;
            for (int i = 0; i < arr.length; i++) if (arr[i].health == 0) _cnt++;
            answer++;
        }
        System.out.println(answer);
    }

    static class Belt {
        int health;
        boolean isRobot;

        Belt(int health, boolean robot) {
            this.health = health;
            this.isRobot = robot;
        }
    }
}
