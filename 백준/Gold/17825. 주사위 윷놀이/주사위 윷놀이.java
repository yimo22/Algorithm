
import java.util.*;
import java.io.*;

public class Main {
	static final int[][] v = { { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40 },
			{ 0, 2, 4, 6, 8, 10, 13, 16, 19, 25, 30, 35, 40 },
			{ 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 25, 30, 35, 40 },
			{ 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 28, 27, 26, 25, 30, 35, 40 }, };
	static int[] num = new int[10];

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer sb = new StringTokenizer(br.readLine());
		for (int i = 0; i < 10; i++)
			num[i] = Integer.parseInt(sb.nextToken());

		// init
		Queue<Pair> q = new LinkedList<>();
		int answer = 0;

		// start
		Node[] nd = new Node[4];
		nd[0] = new Node(0);
		nd[1] = new Node(0);
		nd[2] = new Node(0);
		nd[3] = new Node(0);
		q.add(new Pair(nd, 0, 0));

		while (!q.isEmpty()) {
			Pair c = q.poll();
			Node[] nodelist = c.nodelist;
			int depth = c.depth;
			int sum = c.sum;
			// 종료 조건
			if (depth >= num.length)
				continue;

			// forwarding
			for (int i = 0; i < 4; i++) {
				// 현재 노드가 종료되면 pass
				Node cur = nodelist[i];
				if (cur.arrived)
					continue;

				Node[] newlist = new Node[4];
				newlist[0] = new Node(nodelist[0].pos, nodelist[0].route, nodelist[0].arrived);
				newlist[1] = new Node(nodelist[1].pos, nodelist[1].route, nodelist[1].arrived);
				newlist[2] = new Node(nodelist[2].pos, nodelist[2].route, nodelist[2].arrived);
				newlist[3] = new Node(nodelist[3].pos, nodelist[3].route, nodelist[3].arrived);
				int npos = cur.pos + num[depth];
				newlist[i].pos = npos;

				System.arraycopy(nodelist[0].history, 0, newlist[0].history, 0, 10);
				System.arraycopy(nodelist[1].history, 0, newlist[1].history, 0, 10);
				System.arraycopy(nodelist[2].history, 0, newlist[2].history, 0, 10);
				System.arraycopy(nodelist[3].history, 0, newlist[3].history, 0, 10);
				newlist[i].history[depth] = 1;
				// 만약 도착하는 경우
				if (npos >= v[newlist[i].route].length) {
					newlist[i].arrived = true;
					q.add(new Pair(newlist, depth + 1, sum));
					continue;
				}

				// 방향을 틀어야 하는 경우
				if (cur.route == 0 && (npos % 5 == 0) && ((npos / 5) < 4)) {
					newlist[i].route = (npos / 5);
				}

				if (check(nodelist, newlist[i]))
					continue;

				// answer update
				// 도착한 경우
				// 이동칸에 말이 있을 경우 이동불가
				int w = v[newlist[i].route][newlist[i].pos];

				int nsum = sum + w;
//				if (answer < nsum) {
//					System.out.println(Arrays.toString(newlist));
//				}
				answer = Math.max(answer, nsum);
				q.add(new Pair(newlist, depth + 1, nsum));
			}

		} // while end
		System.out.println(answer);
	}// main end

	private static boolean check(Node[] nodelist, Node node) {
		// TODO Auto-generated method stub
		int[] tmp = new int[] { 0, 9, 13, 19 };
		boolean check = false;
		for (Node cur : nodelist) {
			if (cur.arrived)
				continue;

			// 40인 경우 check
			if (v[cur.route][cur.pos] == 40 && v[node.route][node.pos] == 40)
				return true;
			if (cur.route == node.route && cur.pos == node.pos)
				return true;

			// 서로다른 루트, 같은 칸
			if(cur.route == 0 || node.route == 0) continue;
			
			int p1 = cur.pos - tmp[cur.route];
			int p2 = node.pos - tmp[node.route];
			
			if(p1 < 0 || p2 < 0) continue;
			
			if(p1 == p2) return true;

		}

		return check;
	}

	private static class Pair {
		Node[] nodelist;
		int depth;
		int sum;

		Pair(Node[] n, int d, int s) {
			this.nodelist = n;
			this.depth = d;
			this.sum = s;
		}
	}

	private static class Node {
		int pos;
		int route;
		boolean arrived;
		int[] history = new int[10];

		public Node(int p) {
			this.pos = p;
			this.route = 0;
			arrived = false;
		}

		public Node(int p, int r, boolean ar) {
			this.pos = p;
			this.route = r;
			this.arrived = ar;
		}

		@Override
		public String toString() {
			return "Node [pos=" + pos + ", route=" + route + ", arrived=" + arrived + ", history="
					+ Arrays.toString(history) + "]";
		}

	}

}
