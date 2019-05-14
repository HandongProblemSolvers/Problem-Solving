import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;


public class hps_15685 {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
	    List<Integer> list = new ArrayList<>();
	    
	    //direction: right, up, left, down
	    int[] dx = {1, 0, -1, 0};
	    int[] dy = {0, -1, 0, 1};
	    
		int N = sc.nextInt();
		
		int[][] dragon = new int[N][4];
		
		for(int n=0; n<N; n++) 
			for(int n1=0; n1<4; n1++)
				dragon[n][n1]=sc.nextInt();

		int[][] rect = new int[101][101];
		int count=0;
		
		//direction sequence according to generation
		for(int i=0; i<N; i++) {
			list.add(dragon[i][2]);
			for(int j=0; j<dragon[i][3]; j++) {
				int size=list.size();
				for(int k=size-1; k>=0; k--) {
					int update = (list.get(k) + 1) %4;
					list.add(update);
				}
			}
		
			int x = dragon[i][0];
			int y = dragon[i][1];
			
			rect[x][y]=1;
			
			//marking 
			for(int l=0; l<list.size(); l++) {
				x+=dx[list.get(l)];
				y+=dy[list.get(l)];
				
				if(x>=0 && y>=0)
					rect[x][y]=1;
			}
			
			list.clear();
				
		
		}
		
		//find the result
		for(int a=0; a<100; a++) {
			for(int b=0; b<100; b++) {
				if(rect[a][b]==1) 
					if(rect[a+1][b]==1 && rect[a+1][b+1]==1 && rect[a][b+1]==1) 
						count++;
			}
		}
		
		System.out.println(count);
		
		sc.close();

				
	}

}
