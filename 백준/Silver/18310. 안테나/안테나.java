import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * 1차원 자표를 하나로 모으는 문제
 */
public class Main {
	static int N;
	static int[] arr;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		arr = new int[N];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++)
			arr[i] = Integer.parseInt(st.nextToken());

		// 중간수 뽑기
		Arrays.sort(arr);

		int pos = N / 2;
		if (N % 2 == 0)
			pos--;
		
		System.out.println(arr[pos]);
	}
}
