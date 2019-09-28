package hps;
import java.util.Scanner;
import java.lang.Math;
import java.util.Queue;
import java.util.LinkedList;

//for interval(x-y)
class Pair{
	
	int x, y;
	
	Pair(int x, int y){
		this.x=x;
		this.y=y;
	}
}


public class Segmenting {
	
	static int capacity;
	static long[] tree;

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		Queue<Pair> queue = new LinkedList<>(); 
		
		int N = sc.nextInt();
		int M = sc.nextInt();
		
		//1. Making tree structure
		for(capacity=1; capacity<N; capacity*=2);
		tree = new long[capacity*2];
	    
		//store data in the leaf
		for(int i=capacity; i<capacity+N; i++) {
			tree[i]=sc.nextInt();
		}
		
		//store pair a, b
		for(int j=0; j<M; j++) {
			int x= sc.nextInt();
			int y= sc.nextInt();
			queue.add(new Pair(x, y));
		}
		
		//store the max value in the remaining leaf
		for(int j=capacity+N; j<capacity*2; j++) {
			tree[j]=(long) 1e10;
		}
		
		//Fill parent node values
		for(int k=capacity-1; k>0; k--) {
			tree[k]=Math.min(tree[k*2],tree[k*2+1]);
		}
		
		
		
		//2. Find the minimum value at a specified interval 
		while(!queue.isEmpty()) {
			Pair pair = queue.remove();
			int a = pair.x;
			int b = pair.y;
			
			System.out.println(Query(a, b));
		}
		
		
		
		sc.close();
	}
	
	//Querying data by combining the information of the subtrees
	private static long Query(int L, int R) {
		long min=(long) 1e10;
		L+=capacity-1;
		R+=capacity-1;
		
		for(; L<R; L/=2, R/=2){
			if(L%2==1) {
				min=Math.min(min, tree[L++]);
			}
			if(R%2!=1) {
				min=Math.min(min, tree[R--]);
			}
		}
		if(L==R)
			min=Math.min(tree[L], min);
		
		return min;
	}
}
