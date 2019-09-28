import java.util.Scanner;

public class Ball {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int M = sc.nextInt();
		int N=0;
		double result=1.0;
		double ans = 0.0;
		
		int[] box = new int[M];
		
		for(int j=0; j<M; j++) {
			box[j]=sc.nextInt();
			N+=box[j];
		}
		
		int K=sc.nextInt();
		
		//calculate probability
		for(int k=0; k<M; k++) {
			int ball = box[k];
			double n = N;
			for(int l=1; l<=K; l++) {
				result*=ball/n;
				ball--;
				n--;
			}
			ans+=result;
			result=1.0;
		}
		
		System.out.println(ans);
		
		sc.close();
	}
}
