import java.io.*;
import java.util.*;
public class Solution {
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		
		for(int tc=0; tc<T; tc++) {
			int N, D;
			StringTokenizer st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			D = Integer.parseInt(st.nextToken());
			int[] map = new int[N+2];
			int pos = 0, cnt=0;
			map[0] = 1;
			map[map.length-1] = 1;
			
			st = new StringTokenizer(br.readLine());
			for(int i=0;i<N;i++) {
				map[i+1] = Integer.parseInt(st.nextToken());
			}
			
			// start
			while(true) {
				if(pos >= map.length-1) break;
				
				boolean found = false;
				for(int dist=D; dist>0; dist--) {
					int npos = pos + dist;
					if(npos >= map.length) continue;
					if(map[npos] == 1) {
						pos = npos;
						found = true;
						break;
					}
				}
				
				if(!found) {
					cnt++;
					pos = pos+D;
				}
			}
			System.out.printf("#%d %d\n", tc+1, cnt);
		}
		
	}
}
