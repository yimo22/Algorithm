import java.util.*;
import java.util.Map.Entry;

public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		for(int tc=0; tc<T; tc++) {
			StringBuilder sb = new StringBuilder();
			sb.append("#").append(tc+1).append(" ");
			int N, M, K;
			N = sc.nextInt();
			M = sc.nextInt();
			K = sc.nextInt();
			
			int[] ctime = new int[N];
			HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
			for(int i=0;i<N;i++) {
				int w= sc.nextInt();
				map.put(w, map.getOrDefault(w	, 0) + 1);
			}
			
			// sort
			List<Entry<Integer, Integer>> entries = new ArrayList<>(map.entrySet());
			Collections.sort(entries, new Comparator<Entry<Integer, Integer>>(){
				public int compare(Entry<Integer, Integer> o1, Entry<Integer, Integer> o2) {
					return o1.getKey() - o2.getKey();
				}
			});
			
			int cnt=0;
			int pos = 0;
			boolean found = true;
			for(int time=0; time<= 11111; time++) {
				if(time > 0 && time % M == 0)  cnt+= K;
				if(entries.size() <= pos) break;
				if(entries.get(pos).getKey() == time) {
					int need = entries.get(pos++).getValue();
					if(need > cnt) {
						found = false;
						break;
					}
					cnt -= need;
				}
			}
			if(found) sb.append("Possible");
			else sb.append("Impossible");
			
			System.out.println(sb.toString());
		}
	}
}
