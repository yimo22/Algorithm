import java.util.*;
public class Solution {
	static Map<Character, Integer> map = new HashMap<>();
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		init();
		for(int tc =0; tc<T; tc++) {
			StringBuilder sb = new StringBuilder();
			sb.append("#").append(tc+1).append(" ");
			String str = sc.next();
			
			// 4개의 문자씩 읽어들임
			for(int i=0;i < str.length()/4; i++) {
				StringBuilder buffer = new StringBuilder();
				// 4개의 문자를 bit화
				for(int j=0;j<4;j++) {
					int val = map.get(str.charAt(i * 4 + j));
//					System.out.println("test : " + str.charAt(i * 4 + j)  + " " + val);
					String tmp = Integer.toBinaryString(val);
					//fill in 0
					int cnt =0;
					while(cnt + tmp.length() < 6) {
						buffer.append("0");
						cnt++;
					}
					buffer.append(tmp);
				}
				// 8bit 씩 읽으며 문자로 변환
				for(int j=0;j<3;j++) {
					sb.append(parse6TO8(buffer.substring(j * 8, (j+1) * 8)));
				}
			}
			// 출력
			System.out.println(sb.toString());
		}
	}

	private static char parse6TO8(String substring) {
		// TODO Auto-generated method stub
		// 해당 string을 숫자로 전환
		int sum = 0;
		int w = 1;
		for(int i=substring.length()-1;i>= 0; i--) {
			if(substring.charAt(i) == '1') {
				sum += w;
			}
			w <<= 1;
		}
		return (char) sum;
	}

	private static void init() {
		// TODO Auto-generated method stub
		// 소문자 insert
		for(int i='a'; i<='z'; i++) {
			map.put((char)i, i - 'a' + 26);
		}
		
		// 대문자 insert
		for(int i='A'; i<='Z'; i++) {
			map.put((char)i, i-'A' + 0);
		}
		
		// 숫자 insert
		for(int i=0;i<10;i++) {
			map.put((char)('0' + i), i + 52);
		}
		
		// 특수 문자 insert
		map.put('+', 62);
		map.put('/', 63);
	}
}
