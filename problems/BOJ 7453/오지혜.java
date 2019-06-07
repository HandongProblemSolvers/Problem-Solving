import java.util.Arrays;
import java.util.Scanner;


public class hps_7453 {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int[][] arr = new int[n][4];
		int[] AB = new int[n*n];
		int[] CD = new int[n*n];
		long result=0;
		
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<4; j++) {
				arr[i][j]=sc.nextInt();
			}
		}
		
		//Combine A and B , C and D (N * N times) to reduce calculating number
		int a=0;
		for(int k=0; k<n; k++) {
			for(int l=0; l<n; l++) {
				AB[a]=arr[k][0] + arr[l][1];
				CD[a]=arr[k][2] + arr[l][3];
				a++;
			}
		}
		
		//Before using binary search, sort.
		Arrays.sort(AB);
		Arrays.sort(CD);
		
		
		int min = 0;
		int max = n*n-1;
	
		//Until the end of index, find combination which sums make 0.
		while(min<n*n && max>=0) {
			long cnt=0;
			long cnt2=0;
			//case 1. when the sum is 0
			if(AB[min]+CD[max]==0) {
				int tmp=AB[min];
				int tmp2=CD[max];
				
				//count the same combination and after finding, skip the other thing.
				for( ; min<n*n; min++) {
					if(AB[min]==tmp) {
						cnt++;
					}
					else {
						break;
					}
				}
				//count the same combination and after finding, skip the other thing.
				for(; max>=0; max--) {
					if(CD[max]==tmp2) {
						cnt2++;
					}
					else {
						break;
					}
				}
				result+=(cnt*cnt2);
			}
			//case 2. when the sum is under 0, shift the min index
			else if(AB[min]+CD[max]<0) {
				min++;
			}
			//case 3. when the sum is over 0, shift the max index
			else {
				max--;
			}
		}
		
		System.out.println(result);
		
		sc.close();
	}

}
