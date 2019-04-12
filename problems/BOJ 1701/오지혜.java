import java.util.Scanner;

public class Cubeditor {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		String S = sc.nextLine();
		int[][] fail = new int[S.length()][S.length()];
		String x="";
		int max = 0;
		
		//Using fail function, finds and counts the longest length of same string. 
		//fail function: If the prefix and suffix of the substring are the same, count the length
		for(int i=0; i<S.length()-2; i++) {
			x = S.substring(i, S.length());
			for(int j=1, k=0; j<x.length(); j++) {
				while(k>0 && x.charAt(j)!=x.charAt(k))
					k=fail[i][k-1];
				if(x.charAt(j)==x.charAt(k))
					fail[i][j]=++k;
			}
		}
		
		//store the longest length among the substring. 
		for(int a=0; a<fail.length; a++) {
			for(int b=0; b<fail.length; b++) {
				if(max<fail[a][b])
					max=fail[a][b];
			}
		}
		
		System.out.println(max);
		
		sc.close();

	}

}
