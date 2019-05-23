import java.util.Scanner;

public class hps_11509 {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int[] check = new int[1000001];
		int b=0;
		int count=0;
		
		for(int i=0; i<N; i++) {
			b=sc.nextInt();
			//when there was no high balloon before, shoot.
			if(check[b+1]==0) {
				count++;
				check[b]++;
			}
			//when there was high balloon before
			else {
				check[b+1]--;
				check[b]++;
			}
		}
		System.out.println(count);
		sc.close();

	}

}
