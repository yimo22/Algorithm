
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		// 별(4), 원(3), 네모(2), 세모(1)
		// low <---------------> high
		// 전자 A, 후자 B, 비기면 D 출력
		int N = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();
		for (int t = 0; t < N; t++) {
			int[] pa = new int[4];
			int na;
			int[] pb = new int[4];
			int nb;
			
			// A 입력
			StringTokenizer st = new StringTokenizer(br.readLine());
			na = Integer.parseInt(st.nextToken());
			for(int i=0;i<na;i++) {
				pa[Integer.parseInt(st.nextToken())-1]++;
			}
			
			// B 입력
			st = new StringTokenizer(br.readLine());
			nb = Integer.parseInt(st.nextToken());
			for(int i=0;i<nb;i++) {
				pb[Integer.parseInt(st.nextToken())-1]++;
			}
			
			// 비교
			for(int i=3; i>=0; i--) {
				if(pa[i] == pb[i]) {
					if(i == 0) sb.append("D\n");
					continue;
				}
				
				if(pa[i] > pb[i]) {
					sb.append("A\n");
					break;
				}
				else {
					sb.append("B\n");
					break;
				}
			}
		}
		System.out.println(sb.toString());
	}
}
