import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());

		StringBuilder sb = new StringBuilder();
		for (int tc = 0; tc < T; tc++) {
			int N, M;
			StringTokenizer st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			int lb = (1 << N) - 1;
			sb.append("#").append(tc+1).append(' ');
			if(lb == (M & lb)) sb.append("ON").append('\n');
			else sb.append("OFF").append('\n');
		}
		System.out.println(sb.toString());
	}
}
