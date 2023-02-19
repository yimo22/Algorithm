import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	static int A, B;
	static List<Integer> list;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		A = Integer.parseInt(st.nextToken());
		B = Integer.parseInt(st.nextToken());
		list = new ArrayList<>();
		for (int i = -1000_000; i <= 1000_000; i++) {
			if(((long)i * i + 2 * A * i + B )== 0) list.add(i);
		}
		
		for(int i=0;i<list.size();i++) {
			sb.append(list.get(i) + " ");
		}
		System.out.println(sb.toString());
	}
}
