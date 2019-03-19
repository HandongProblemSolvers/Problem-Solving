package hps;

import java.util.*;

//record spot for direction
class Direction {
    int x;
    int y;

    Direction(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class Main{
	
	//height and width
	static int n;
	static int m;
	
	//NxM maze and 1 visit, 0 not yet
	static int[][] maze;
	static int[][] visited;
	
	//down, up, right, left
	static int[] mx = { 0, 0, 1, -1};
	static int[] my = { 1, -1, 0, 0};

	public static void main(String[] args) {
		
	Scanner sc = new Scanner(System.in);
	n = sc.nextInt();
	m = sc.nextInt();
	sc.nextLine();
	
		maze = new int[n][m];
		visited = new int[n][m];
		
		//input maze
		for(int i =0; i<n; i++) {
			String input = sc.nextLine();
			//to input without spacing
			for(int j=0; j<m; j++) {
				maze[i][j] = input.charAt(j)-'0';
				visited[i][j]=0;
			}
		}
	
		//start maze at (1,1)
		visited[0][0]=1;
		BFS(0,0);

		System.out.println(maze[n-1][m-1]);
	}
	
	static public void BFS(int x, int y) {
		
		//to use when move in maze
		int nearX, nearY;
		Queue<Direction> queue = new LinkedList<Direction>();
		
		//add visiting spot
		queue.add(new Direction(x, y));
		
		//continue until finding all movable spot
		while(!queue.isEmpty()) {
			
			//set position to move
			Direction a = queue.poll();
			
			//check possible direction
			for (int k=0; k<4; k++) {
				
				nearX = a.x + mx[k];
				nearY = a.y + my[k];
			    
				//to prevent index error
				if(nearX>=0 && nearY>=0 && nearX<m && nearY<n) {
					//check whether we can move or not 
					if(maze[nearY][nearX]>0 && visited[nearY][nearX]!=1) {	
						
						//move and store for further moving, record for least movement number
						queue.add(new Direction(nearX, nearY));
						visited[nearY][nearX]=1;
						maze[nearY][nearX]=maze[a.y][a.x]+1;
						
					}
				}
			}
		}
	}
}
