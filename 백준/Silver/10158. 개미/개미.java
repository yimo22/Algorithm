
import java.util.*;
import java.io.*;

public class Main {

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int w, h, p, q, t;
		w = Integer.parseInt(st.nextToken());
		h = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		p = Integer.parseInt(st.nextToken()); 
		q = Integer.parseInt(st.nextToken());
		t = Integer.parseInt(br.readLine());

		// t범위 : [1,200M]
		// w와 h의 최소공배수 -> 순환주기
		// A * B = GCD * LCM
		int xt = (t + p) % (2 * w);
		int yt = (t + q) % (2 * h);
		int x = (xt / w > 0) ? w - (xt % w) : xt % w;
		int y = (yt / h > 0) ? h - (yt % h) : yt % h;
		StringBuilder sb = new StringBuilder();
		sb.append(x).append(" ").append(y);
		System.out.println(sb.toString());
	}
}
