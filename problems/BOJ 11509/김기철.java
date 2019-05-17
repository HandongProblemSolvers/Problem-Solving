import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int N;
		int[] H;
		int[] M;
		int ans=0;
		N=sc.nextInt();
		H=new int[N+1];
		M=new int[N+1];
		for(int i=1; i<=N;i++){
			H[i]=sc.nextInt();
			if(M[H[i]]==0)ans++;
			else M[H[i]]--;
			M[H[i]-1]+=1;
		}
		System.out.println(ans);
	}
}
