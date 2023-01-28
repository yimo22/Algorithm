

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N, K;
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		int[][] room = new int[6+1][2];
		for(int t=0; t<N; t++) {
			int sex, year;
			st = new StringTokenizer(br.readLine());
			sex = Integer.parseInt(st.nextToken());
			year = Integer.parseInt(st.nextToken());
			room[year][sex]++;
		}
		
		int cnt =0;
		for(int i=1; i<=6; i++) {
			cnt += room[i][0] / K;
			if(room[i][0] % K != 0) cnt++;
			cnt += room[i][1] / K;
			if(room[i][1] % K != 0) cnt++;
		}
		System.out.println(cnt);
	}
}
