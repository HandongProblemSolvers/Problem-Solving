import java.util.*;

public class Main{
	static int[][] L;
	static int N,M;
	static Queue<Integer> q=new LinkedList<>();
	static int ans=1;
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		N=sc.nextInt();
		M=sc.nextInt();
		L=new int[N+2][M+2];	
		sc.nextLine();
		for(int i=1; i<=N; i++){
			String temp=sc.nextLine();
			for(int j=1; j<=M; j++){
				int k=temp.charAt(j-1)-'0';
				L[i][j]=k;	
			}
		}
		int count=1;
		int num;
		q.add(1);q.add(1);
		while(L[N][M]==1){
			num=0;
			ans++;
			for(int m=0; m<count; m++){
				num+=min(q.remove(),q.remove());
					
			}
			count=num;

		}
        System.out.println(L[N][M]);

	}	

	static int min(int i,int j){
		int count=0;
		if(L[i+1][j]==1){
			L[i+1][j]=ans;
			q.add(i+1);q.add(j);
			count++;
		}
		if(L[i-1][j]==1){
			L[i-1][j]=ans;
			q.add(i-1);q.add(j);
			count++;
		}
		if(L[i][j+1]==1){
			L[i][j+1]=ans;
			q.add(i);q.add(j+1);
			count++;
		}
		if(L[i][j-1]==1){
			L[i][j-1]=ans;
			q.add(i);q.add(j-1);
			count++;
		}	
		return count++;
	}
  
}
