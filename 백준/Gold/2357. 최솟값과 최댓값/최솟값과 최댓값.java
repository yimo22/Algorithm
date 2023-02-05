
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	static int[] maxTree, minTree;
	private static int tmpN;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N, M;
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		int[] arr = new int[N];
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(br.readLine());
		}
		// making tree
		makeTree(arr);
		// finding answer
		for (int tc = 0; tc < M; tc++) {
			st = new StringTokenizer(br.readLine());
			int a, b;
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			// index는 0부터 시작해야됨
			System.out.println(getValueFromMinTree(a-1, b-1) + " " + getValueFromMaxTree(a-1, b-1));
		}
	} // main end

	static void makeTree(int[] arr) {
		tmpN = (int) Math.pow(2,Math.ceil(Math.log(arr.length) / Math.log(2)));
		maxTree = new int[2 * tmpN];
		minTree = new int[2 * tmpN];
		
		// filling
		Arrays.fill(maxTree, 0);
		Arrays.fill(minTree, 0);
		System.arraycopy(arr, 0, maxTree, tmpN, arr.length);
		System.arraycopy(arr, 0, minTree, tmpN, arr.length);

		// update
		for (int i = tmpN - 1; i > 0; i--) {
			maxTree[i] = Math.max(maxTree[2 * i], maxTree[2 * i + 1]);
			minTree[i] = Math.min(minTree[2 * i], minTree[2 * i + 1]);
		}
	}
	static int getValueFromMaxTree(int start, int end) {
		int spos = tmpN + start;
		int epos = tmpN + end;
		
		int result = Integer.MIN_VALUE;
		while(true) {
			if(spos > epos) break;
			
			// spos 가 우측 자식일 경우
			if((spos & 1) ==1) {
				result = Math.max(result, maxTree[spos]);
				spos++;
			}
			spos >>= 1;
			// epos 가 왼쪽 자식일 경우
			if((epos & 1) == 0) {
				result = Math.max(result, maxTree[epos]);
				epos--;
			}
			epos >>= 1;
		}
		return result;
	}
	static int getValueFromMinTree(int start, int end) {
		int spos = tmpN + start;
		int epos = tmpN + end;
		
		int result = Integer.MAX_VALUE;
		while(true) {
			if(spos > epos) break;
			
			// spos 가 우측 자식일 경우
			if((spos & 1) ==1) {
				result = Math.min(result, minTree[spos]);
				spos++;
			}
			spos >>= 1;
			
			// epos 가 왼쪽 자식일 경우
			if((epos & 1) == 0) {
				result = Math.min(result, minTree[epos]);
				epos--;
			}
			epos >>= 1;
		}
		return result;
	}
}
