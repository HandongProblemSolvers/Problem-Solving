import java.util.Scanner;
import java.lang.Math;


public class hps_7578 {
	
	static int capacity;
	static long[] tree;

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int[] A = new int[N+1];
		int[] B = new int[1000001];
		long result =0;
		
		for(int a=1; a<=N; a++) {
			A[a]=sc.nextInt();
		}
		for(int b=1; b<=N; b++) {
			int b_number=sc.nextInt();
			B[b_number]=b;
		}
		
		//initialize tree
		int height = (int)(Math.ceil(Math.log(N)/Math.log(2)));
		int maximize = 2*(int)Math.pow(2, height);
		tree = new long[maximize];
		
		for(int i=1; i<=N; i++) {
		    result += Query(1, N, 1, B[A[i]], N);
			Update(1, N, 1, B[A[i]]);
		}
		
		System.out.println(result);
	
		sc.close();
	}

	//check whether other machine cables exists after the certain position and count
	private static long Query(int s, int e, int n, int left, int right) {
		if(right<s || e<left)
			return 0;
		if(left<=s && e<=right)
			return tree[n];
		int m = (s+e)/2;
		return Query(s, m, n*2, left, right)+Query(m+1, e, n*2+1, left, right);
	}

	//update value of the checking position to 1
	private static void Update(int s, int e, int n, int target) {
		
		if(target<s || e<target)
			return;
		if(s==e) {
			tree[n]=1;
			return;
		}
		int m=(s+e)/2;
		Update(s, m, n*2, target);
		Update(m+1, e, n*2+1, target);
		tree[n]=tree[n*2]+tree[n*2+1];
	}
}
