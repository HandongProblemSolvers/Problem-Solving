import java.util.Scanner;

public class Square2 {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		
		int[] square = new int[n+1];
		square[0] = 0;
		
		for(int i = 1; i <= n; i++) {
			//just include only square of one
			square[i] = i;
			for(int j = 1; j*j <= i; j++)
				//fixing process to find smallest number of term
				square[i] = Math.min(square[i], square[i-j*j] + 1);
		}
		
		System.out.println(square[n]);
	}
}