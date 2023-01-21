import java.util.*;
public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int T = sc.nextInt();
		
		for(int tc=0; tc<T; tc++) {
			String s1 = sc.next();
			String s2 = sc.next();
			
			String answer = "";
			
			if(s1.length() != s2.length()) answer = "DIFF";
			else if(getCount(s1) != getCount(s2)) answer = "DIFF";
			else if(!isSame(s1, s2))answer = "DIFF";
			else answer = "SAME";
			
			System.out.printf("#%d %s\n",tc+1, answer);
		}
	}

	private static boolean isSame(String s1, String s2) {
		// TODO Auto-generated method stub
		for (int i = 0; i < s1.length(); i++) {
			if(s1.charAt(i) == 'B' && s2.charAt(i) != 'B') return false;
			if(s1.charAt(i) != 'B' && s2.charAt(i) == 'B') return false;
			if("ADOPQR".contains(s1.substring(i, i+1)) && !"ADOPQR".contains(s2.substring(i, i+1))) return false;
			if(!"ADOPQR".contains(s1.substring(i, i+1)) && "ADOPQR".contains(s2.substring(i, i+1))) return false;
		}
		return true;
	}

	private static int getCount(String s2) {
		// TODO Auto-generated method stub
		int cnt = 0;
		for (int i = 0; i < s2.length(); i++) {
			if(s2.charAt(i) == 'B') cnt+=2;
			else if("ADOPQR".contains(s2.substring(i, i+1))) cnt++;
		}
		return cnt;
	}
}
