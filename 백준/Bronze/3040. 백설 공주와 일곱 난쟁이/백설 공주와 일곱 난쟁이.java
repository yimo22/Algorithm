import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
	private static int[] arr;

	static int[] number;
	
	static boolean check = false;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		arr = new int[9];
		for(int i=0;i<9;i++) {
			arr[i] = Integer.parseInt(br.readLine());
		}
		
		// combination
		number = new int[7];
		comb(0, 0);
		
		Arrays.stream(number).forEach(e -> System.out.println(e));
	}
	static void comb(int cnt, int start) {
		if(check) return;
		if(cnt == 7) {
			// check
			int sum = 0;
			for(int w : number) sum += w;
			
			if(sum == 100) {
				check =true;
			}
			return;
		}
		
		for(int i=start;i<9;i++) {
			if(check) return;
			
			number[cnt] = arr[i];
			comb(cnt+1, i+1);
		}
	}
}
