import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	static int N, M;
	private static int[] arr;
	private static int[] numbers;
	private static StringBuilder sb;
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		arr = new int[N];
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<N;i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		// N개 중, M개를 고름
		// nCm
		Arrays.sort(arr);
		sb = new StringBuilder();
		numbers = new int[M];
		comb(0,0,M);
		System.out.println(sb.toString());
	}
	static void comb(int start, int pos, int k) {
		if(pos == k) {
			for(int i : numbers) {
				sb.append(arr[i]).append(' ');
			}
			sb.append('\n');
			return;
		}
		
		for(int i=start; i<arr.length;i++) {
			numbers[pos] = i;
			comb(i, pos+1, k);
		}
	}
	static boolean perm(int[] num) {
		// 꼭대기 찾기
		int i = num.length - 1;
		while (i > 0 && num[i - 1] >= num[i])
			i--;

		if (i == 0)
			return false;

		// 바꿀 대상 찾기
		int j = num.length - 1;
		while (num[j] <= num[i - 1])
			j--;

		// swap
		swap(num, i-1, j);
		
		// 정렬
		int k = num.length-1;
		while( i < k) swap(num, i++, k--);
		return true;
	}

	static void swap(int[] arr, int a, int b) {
		int tmp = arr[a];
		arr[a] = arr[b];
		arr[b] = tmp;
	}
}
