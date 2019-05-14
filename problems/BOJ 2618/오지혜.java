import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;
import java.lang.Math;

class Pair{
	int x;
	int y;
	
	Pair(int x, int y){
		this.x=x;
		this.y=y;
	}
}

public class hps_2618{
	
	static int N;
	static int W;
	static int[][] minDis;
	static Pair[] incident;

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		N = sc.nextInt();
		W = sc.nextInt();
		incident = new Pair[W+1];
		minDis = new int[W+1][W+1];

		Queue<Integer> order = new LinkedList<>();
		int caseCar1 =0, caseCar2=0;

		for(int i=1; i<=W; i++) {
			incident[i]= new Pair(sc.nextInt(), sc.nextInt());
		}
		
		
		//To the last incident, find the minimum distance by choosing between Car1 and Car2 
		System.out.println(FindMin(0,0));
		
		
		//based on above each minimum distance, show the choice
		while(caseCar1<W && caseCar2<W) {
			
			int next = Math.max(caseCar1, caseCar2)+1;
			int dCar1 = minDis[next][caseCar2] + dis(caseCar1, next, 1);
			int dCar2 = minDis[caseCar1][next] + dis(caseCar2, next, 2);
			
			if(dCar1 <= dCar2) {
				order.add(1);
				caseCar1 = next;
			}
			else {
				order.add(2);
				caseCar2 = next;
			}
		}
		
		while(!order.isEmpty())
			System.out.println(order.poll());
		
		sc.close();
			
	}

	private static int FindMin(int car1, int car2) {
		
		if(minDis[car1][car2] !=0) 
			return minDis[car1][car2];
		
		if(car1==W || car2==W)
			return 0;
		
		int nextIncident = Math.max(car1, car2) +1;
		minDis[car1][car2]=Math.min(FindMin(nextIncident, car2) + dis(car1, nextIncident, 1), 
				FindMin(car1, nextIncident)+dis(car2, nextIncident, 2));
		
		return minDis[car1][car2];
	}

	private static int dis(int a, int b, int carNum) {
		if(a==0) {
			if(carNum==1) 
				return(incident[b].x-1)+(incident[b].y-1);
			else 
				return(N-incident[b].x)+(N-incident[b].y);
		}
		else {
			return Math.abs(incident[b].x-incident[a].x) + Math.abs(incident[b].y-incident[a].y);
		}
	}

}

