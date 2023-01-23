
import java.util.*;
import java.io.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		BitSet bitSet = new BitSet(N);
		
		for(int i=0;i<N;i++) {
			if(sc.nextInt() == 1) bitSet.set(i);
		}
		
		int M = sc.nextInt();
		for(int i=0;i<M;i++) {
			int sex, num;
			sex = sc.nextInt();
			num = sc.nextInt();
			
			// 남
			if(sex == 1) {
				// 배수만큼 스위치 flip'
				for(int j=num; j<=N;j += num) bitSet.flip(j-1);
			}
			// 여
			else {
				bitSet.flip(num-1);
				for(int len=1; (num - 1 + len < N) && (num - 1 - len >= 0); len++) {
					if(bitSet.get(num-1 - len) != bitSet.get(num-1 + len)) break;
					bitSet.flip(num -1 - len);
					bitSet.flip(num -1 + len);
				}
			}
		}

		StringBuilder sb = new StringBuilder();
		for(int i=0;i<N;i++) {
			if(i > 0 && i % 20 == 0) sb.append("\n");
			if(bitSet.get(i)) sb.append("1 ");
			else sb.append("0 ");
		}
		System.out.println(sb.toString());
	}
}
