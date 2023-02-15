import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		for(int tc=0; tc<4; tc++) {
			Character answer = 'K';
			int x1=sc.nextInt(),y1=sc.nextInt(),p1=sc.nextInt(),q1=sc.nextInt();
			int x2=sc.nextInt(),y2=sc.nextInt(),p2=sc.nextInt(),q2=sc.nextInt();
			if(p1<x2 || p2<x1 || q1 < y2 || y1 > q2) answer = 'd';
			else if(p1==x2 || p2 == x1) {
				if((q1==y2 )|| (y1==q2)) answer = 'c';
				else answer = 'b';
			}
			else if(y1==q2 || q1==y2) {
				if(p1==x2 || p2 == x1) answer = 'c';
				else answer = 'b';
			}
			else
				answer = 'a';
			System.out.println(answer);
		}
	}
}
