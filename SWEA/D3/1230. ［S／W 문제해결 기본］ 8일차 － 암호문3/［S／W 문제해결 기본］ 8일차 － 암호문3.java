import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	private Node head;
	private Node tail;

	public Solution() {
		// TODO Auto-generated constructor stub
		head = null;
		tail = null;
	}

	/* */
	public void addFirst(int data) {
		Node newNode = new Node(data);
		newNode.nxt = head;
		head = newNode;

		if (head.nxt == null)
			tail = head;
	}

	public void addLast(int data) {
		Node newNode = new Node(data);

		if (head == null)
			addFirst(data);
		else {
			tail.nxt = newNode;
			tail = newNode;
		}
	}

	public void add(int k, int[] data) {
		int spos = 0;
		if (k == 0) {
			// 맨 앞에 자료를 추가
			if (head != null) {
				Node nd = new Node(data[0]);
				nd.nxt = head;
				head = nd;
			} else {
				head = new Node(data[0]);
			}
			spos++;
		}

		Node cur = head;
		for (int i = 1; i < k; i++) { // index 이동
			cur = cur.nxt;
		}
		// cur 뒤로 insert
		for (int i = spos; i < data.length; i++) {
			Node next = new Node(data[i]);
			next.nxt = cur.nxt;
			cur.nxt = next;
			cur = next;
		}
		
		if(cur.nxt == null) tail = cur;
	}

	public void remove(int k, int y) {
		if (k == 0) {
			removeFirst();
			return;
		}
		Node cur = getKNode(k - 1); //
		Node nxt = cur;
		for (int i = 0; i < y; i++) {
			nxt = nxt.nxt;
		}
		cur.nxt = nxt.nxt;
	}

	public void removeFirst() {
		Node cur = head;
		head = cur.nxt;
	}

	public Node getKNode(int k) {
		Node cur = head;
		for (int i = 0; i < k; i++)
			cur = cur.nxt;
		return cur;
	}

	public String getAnswer() {
		Node tmp = head;
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < 10; i++) {
			sb.append(tmp.data).append(' ');
			tmp = tmp.nxt;
		}
		return sb.toString();
	}

	public String toString() {
		if (head == null)
			return "-1";

		Node tmp = head;
		String str = " ";

		while (tmp.nxt != null) {
			str += (tmp + " ");
			tmp = tmp.nxt;
		}

		str += (tmp + " ");
		return str;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		for (int t = 0; t < 10; t++) {
			int N = Integer.parseInt(br.readLine());
			Solution list = new Solution();
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int i = 0; i < N; i++) {
				list.addLast(Integer.parseInt(st.nextToken()));
			}

			int M = Integer.parseInt(br.readLine());
			st = new StringTokenizer(br.readLine(), " ");
			for (int i = 0; i < M; i++) {
				char ord = st.nextToken().charAt(0);
				if (ord == 'I') {
					// 앞에서부터 x의 위치 바로앞에 y개의 숫자를 삽입
					int x = Integer.parseInt(st.nextToken());
					int y = Integer.parseInt(st.nextToken());
					int arr[] = new int[y];
					for (int j = 0; j < y; j++) {
						arr[j] = Integer.parseInt(st.nextToken());
					}
					list.add(x, arr);
				} else if (ord == 'D') {
					int x = Integer.parseInt(st.nextToken());
					int y = Integer.parseInt(st.nextToken());
					list.remove(x, y);
				} else if (ord == 'A') {
					int y = Integer.parseInt(st.nextToken());
					for (int j = 0; j < y; j++) {
						int w = Integer.parseInt(st.nextToken());
						list.addLast(w);
					}
				}
			}
			sb.append('#').append(t + 1).append(' ');
			sb.append(list.getAnswer()).append('\n');
		}
		System.out.println(sb.toString());
	}
}

class Node {
	int data;
	Node nxt;

	public Node(int data) {
		this.data = data;
	}

	@Override
	public String toString() {
		return "Node [data=" + data + "]";
	}

}