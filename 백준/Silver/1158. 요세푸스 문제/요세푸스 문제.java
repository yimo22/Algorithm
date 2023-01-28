

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N, K;
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		int[] num = new int[N];

		LinkedList<Integer> linkedList = new LinkedList<Integer>();
		for (int i = 0; i < N; i++) {
			linkedList.add(i+1);
		}

		int[] arr = new int[N];
		int pos = 0;
		for (int i = 0; i < N; i++) {
			pos  = (pos - 1 + K) % linkedList.size();
			arr[i] = linkedList.get(pos);
			linkedList.remove(pos);
		}

		StringBuilder sb = new StringBuilder();
		sb.append("<");
		for (int i = 0; i < arr.length; i++) {
			if (i > 0)
				sb.append(", ");
			sb.append(arr[i]);
		}
		sb.append(">");
		System.out.println(sb.toString());
	}
}
