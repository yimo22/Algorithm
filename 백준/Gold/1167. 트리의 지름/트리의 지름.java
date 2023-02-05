
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main { // 트리의 지름
	static int V;
	static ArrayList<Integer[]>[] adj;
	static boolean[] visited;
	static int maxV;
	static int maxLen;
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		V = Integer.parseInt(br.readLine());
		adj = new ArrayList[V+1];
		for(int i=0;i<adj.length;i++) adj[i] = new ArrayList<>();
		for(int i=0;i<V;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int vertex = Integer.parseInt(st.nextToken());
			while(true) {
				int W = Integer.parseInt(st.nextToken());
				if(W == -1) break;
				int path = Integer.parseInt(st.nextToken());
				
				adj[vertex].add(new Integer[] {W, path});
			}
		}
		
		
		// 트리의 지름
		visited = new boolean[V+1];
		visited[1] = true;
		dfs(1, 0);
		maxLen = -1;
		Arrays.fill(visited, false);
		visited[maxV] = true;
		dfs(maxV, 0);
		System.out.println(maxLen);
		
	}
	private static void dfs(int v, int len) {
		// TODO Auto-generated method stub
		if(maxLen < len) {
			maxV = v;
			maxLen = len;
		}
		
		for(Integer[] nd : adj[v]) {
			int nv = nd[0];
			int w = nd[1];
			
			if(!visited[nv]) {
				visited[nv] = true;
				dfs(nv, len + w);
				visited[nv] = false;
			}
		}
		
	}
}
