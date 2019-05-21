import java.util.*;
import java.io.*;
import java.math.*;


public class hps_4343 {
	
	static int N, S, P;
	static int[] parent;
	static A[] node;


	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.valueOf(br.readLine());
		String[] temp;
		int d=0;
		int min=0;
		int place=0;
		
		//repeat N times
		for(int i=0; i<N; i++) {
			temp=br.readLine().split(" ");
			S=Integer.valueOf(temp[0]);
			P=Integer.valueOf(temp[1]);
			parent= new int[P+1];
			node = new A[P*(P-1)/2];
			
			for(int n=1; n<=P; n++) 
				parent[n]=n;
	
			int[] x = new int[P+1];
			int[] y = new int[P+1];
			
			for(int j=1; j<=P; j++) {
				temp=br.readLine().split(" ");
				x[j]=Integer.valueOf(temp[0]);
				y[j]=Integer.valueOf(temp[1]);
			}
			
			//store edge information
			place=0;
			for(int k=1; k<=P; k++) {
				for(int l=k+1; l<=P; l++) {
					d = (x[k]-x[l])*(x[k]-x[l])+(y[k]-y[l])*(y[k]-y[l]);
					node[place++] = new A(k, l, d);
				}
			}
			
			//to select the smallest weight
			Arrays.sort(node);
			int compare = P;
			place =0;
			min=0;
			
			//find MST 
			while(compare>S) {
				int start = findRoot(node[place].s);
				int end = findRoot(node[place].e);
				
				if(start != end) {
					parent[end]=start;
					min=node[place].d;
					compare--;
				}
				place++;
			}
			System.out.format("%.2f\n", Math.sqrt(min));
		}
		
	}
	
	//find each root to avoid cycle 
	public static int findRoot(int a) {
		if(a==parent[a])
			return a;
		parent[a]=findRoot(parent[a]);
		return parent[a];
	}
	
	
	static class A implements Comparable<A>{
		
		int s, e, d;

		public A(int s, int e, int d) {
			this.s=s;
			this.e=e;
			this.d=d;
		}
		
		public int compareTo(A a) {
			return this.d <= a.d ? -1: 1;
		}
		
	}

}




	
