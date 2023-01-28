
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int[][] map = new int[1001][1001];

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());

		for (int i = 0; i < N; i++) {
			int x, y, w, h;
			StringTokenizer st = new StringTokenizer(br.readLine());
			x = Integer.parseInt(st.nextToken());
			y = Integer.parseInt(st.nextToken());
			w = Integer.parseInt(st.nextToken());
			h = Integer.parseInt(st.nextToken());

			for (int j = x; j < x + w; j++) {
				for (int k = y; k < y + h; k++) {
					map[j][k] = i + 1;
				}
			}
		}
		
		// 각자의 넓이 구하기
		int[] _size = new int[N+1];
		for(int i=0;i<map.length;i++) {
			for(int j=0;j<map[i].length;j++) {
				_size[map[i][j]]++;
			}
		}
		for(int i=1;i<_size.length;i++) System.out.println(_size[i]);
	}

}
