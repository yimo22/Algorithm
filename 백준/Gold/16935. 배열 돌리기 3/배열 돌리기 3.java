
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	private static int N, M;
	private static int R;
	private static int[][][] map;
	private static int time = 0;
	private static int[] arr;
	private static int len, curN, curM;

	public static void main(String[] args) throws Exception {
		init();
		/* start */
		StringBuilder sb = new StringBuilder();
//		int[] faster=new int[R];
//		int size=0;
//		for(int i=0;i<arr.length;i++) {
//			switch(arr[i]) {
//			
//			}
//		}
		for (int i = 0; i < arr.length; i++) {
			switch (arr[i]) {
			case 1:
				func1();
				break;
			case 2:
				func2();
				break;
			case 3:
				func3();
				break;
			case 4:
				func4();
				break;
			case 5:
				func5();
				break;
			case 6:
				func6();
				break;
			default:
				break;
			}
			time++;
//			printArr(curN, curM, time);
		} // for문 end
		
		for(int i=0;i<curN;i++) {
			for(int j=0;j<curM;j++) {
				sb.append(map[time%2][i][j]).append(" ");
			}
			sb.append('\n');
		}
		System.out.println(sb.toString());
	}
	
	/**
	 * DEBUG
	 */
	static void printArr(int curN, int curM, int time) {
		System.out.println("<<<<<<<<<<<<<<<");
		for(int i=0;i<curN;i++) {
			for(int j=0;j<curM;j++) {
				System.out.print(map[time%2][i][j] + " ");
			}
			System.out.println();
		}
	}
	
	
	/**
	 * 배열의 상하반전을 시키는 연산
	 */
	static void func1() {
		int idx = time % 2;
		int nxtIdx = (time + 1) % 2;

		for (int i = 0; i < curN; i++) {
			for(int j=0;j<curM;j++)
				map[nxtIdx][curN-i-1][j]=map[idx][i][j];
		}
	}

	/**
	 * 배열의 좌우 반전시키는 연산
	 */
	static void func2() {
		int idx = time % 2;
		int nxtIdx = (time + 1) % 2;

		for (int i = 0; i < curN; i++) {
			for (int j = 0; j < curM; j++) {
				map[nxtIdx][i][j] = map[idx][i][curM - 1 - j];
			}
		}
	}

	/**
	 * 오른쪽으로 90도 회전시키는 연산
	 */
	static void func3() {
		int idx = time % 2;
		int nxtIdx = (time + 1) % 2;

		for (int i = 0; i < curM; i++) {
			for (int j = 0; j < curN; j++) {
				map[nxtIdx][i][j] = map[idx][curN - 1 - j][i];
			}
		}
		// swap
		int tmp = curM;
		curM = curN;
		curN = tmp;
	}

	/**
	 * 왼쪽으로 90도 회전
	 */
	static void func4() {
		int idx = time % 2;
		int nxtIdx = (time + 1) % 2;

		for (int i = 0; i < curM; i++) {
			for (int j = 0; j < curN; j++) {
				map[nxtIdx][i][j] = map[idx][j][curM - i - 1];
			}
		}

		// swap
		int tmp = curM;
		curM = curN;
		curN = tmp;
	}

	/**
	 * 크기 나누고 오른쪽으로 회전
	 */
	static void func5() {
		int idx = time % 2;
		int nxtIdx = (time + 1) % 2;

		// 4 번을 1번으로 옮김
		for (int i = 0; i < curN / 2; i++) {
			for (int j = 0; j < curM / 2; j++) {
				map[nxtIdx][i][j] = map[idx][i + curN / 2][j];
			}
		}

		// 3번을 4번으로 옮김
		for (int i = 0; i < curN / 2; i++) {
			for (int j = 0; j < curM / 2; j++) {
				map[nxtIdx][i + curN / 2][j] = map[idx][i + curN / 2][j + curM / 2];
			}
		}

		// 2번을 3번으로 옮김
		for (int i = 0; i < curN / 2; i++) {
			for (int j = 0; j < curM / 2; j++) {
				map[nxtIdx][i + curN / 2][j + curM / 2] = map[idx][i][j + curM / 2];
			}
		}

		// 1번을 2번으로 옮김
		for (int i = 0; i < curN / 2; i++) {
			for (int j = 0; j < curM / 2; j++) {
				map[nxtIdx][i][j + curM / 2] = map[idx][i][j];
			}
		}

	}

	/**
	 * 크기나누고 왼쪽으로 회전
	 */
	static void func6() {
		int idx = time % 2;
		int nxtIdx = (time + 1) % 2;

		// 1번을 4번으로 옮김
		for (int i = 0; i < curN / 2; i++) {
			for (int j = 0; j < curM / 2; j++) {
				map[nxtIdx][i + curN / 2][j] = map[idx][i][j];
			}
		}

		// 4번을 3번으로 옮김
		for (int i = 0; i < curN / 2; i++) {
			for (int j = 0; j < curM / 2; j++) {
				map[nxtIdx][i + curN / 2][j + curM / 2] = map[idx][i + curN / 2][j];
			}
		}

		// 3번을 2번으로 옮김
		for (int i = 0; i < curN / 2; i++) {
			for (int j = 0; j < curM / 2; j++) {
				map[nxtIdx][i][j + curM / 2] = map[idx][i + curN / 2][j + curM / 2];
			}
		}

		// 2번을 1번으로 옮김
		for (int i = 0; i < curN / 2; i++) {
			for (int j = 0; j < curM / 2; j++) {
				map[nxtIdx][i][j] = map[idx][i][j + curM / 2];
			}
		}
	}

	static void init() throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		curN = N = Integer.parseInt(st.nextToken());
		curM = M = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());
		arr = new int[R];
		len = Math.max(N, M);
		map = new int[2][len][len];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				map[0][i][j] = Integer.parseInt(st.nextToken());
			}
		}

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < R; i++)
			arr[i] = Integer.parseInt(st.nextToken());

	}
}
