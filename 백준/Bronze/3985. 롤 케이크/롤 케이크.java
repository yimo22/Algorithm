

import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int L, N;
		Scanner sc = new Scanner(System.in);
		L = sc.nextInt();
		N = sc.nextInt();
		int[] arr = new int[L + 1];
		Node[] cnt = new Node[N];
		Node[] nodelist = new Node[N];
		// 첫째 줄에 가장 많은 조각을 받을 것으로 기대하던 방청객의 번호를 출력
		// 가장 많은 조각을 받은 방청객의 번호를 출력
		for (int i = 0; i < N; i++) {
			int s = sc.nextInt();
			int e = sc.nextInt();
			nodelist[i] = new Node(e - s + 1, i + 1);
			cnt[i] = new Node(0, i + 1);
			for (int j = s; j <= e; j++) {
				if (arr[j] > 0) {
					continue;
				}
				arr[j] = (i + 1);
				cnt[arr[j] - 1].w++;
			}
		}
		Arrays.sort(cnt, (a,b) -> {return b.w - a.w;});
		Arrays.sort(nodelist, (a,b) -> {return b.w - a.w;});
		
		System.out.println(nodelist[0].pos);
		System.out.println(cnt[0].pos);
	}

	static class Node {
		int w;
		int pos;

		public Node(int w, int pos) {
			this.w = w;
			this.pos = pos;
		}
	}
}
