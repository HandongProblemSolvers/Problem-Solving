import java.util.*;
import java.io.*;
import java.math.*;
 
public class Main{
    
    public static int[] node;
    public static Edge[] E;
    public static int[][]v;
    
    public static void main(String args[]) {
    	 Scanner sc = new Scanner(System.in);
    	int N, S, P, place, d, comp, o1, o2, min;
    	int[] px, py;
    	
    	
    	N = sc.nextInt();
    	
    	for(int n=0; n<N; n++) {
    		
    		S=sc.nextInt();
    		P=sc.nextInt();
    		E = new Edge[P*(P-1)/2];
    		node = new int[P+1];
    		
    		for(int i = 1; i <= P; i++) 
    			node[i] = i;	
    		
    		px = new int[P+1];
    		py = new int[P+1];
    		
    		for(int i = 1; i <= P; i++){
    			px[i] = sc.nextInt();
    			py[i] = sc.nextInt();
    		}
    		
    		place = 0;
    		for(int i = 1; i <= P; i++){
    			for(int j = i+1; j <= P; j++){
    				d = (px[i]-px[j])*(px[i]-px[j])+(py[i]-py[j])*(py[i]-py[j]);
        			E[place++] = new Edge(i, j, d);
        		}
    		}
    		Arrays.sort(E);
    		comp = P;
    		place = 0;
    		min = 0;
    		
    		while(comp > S){
    			o1 = findRoot(E[place].S);
    			o2 = findRoot(E[place].E);
    			if(o1 != o2){
    				node[o2] = o1;
    				min = E[place].D;
    				comp--;
    			}
    			place++;
    		}
    		System.out.format("%.2f\n", Math.sqrt(min));
    		N--;
    	}
    }
    
    public static int findRoot(int x){
    	if(node[x] != x) 
    		node[x] = findRoot(node[x]);
    	return node[x];
    }
    
    
    static class Edge implements Comparable<Edge>{
    	
    	int S, E, D;
    	
    	public Edge(int s, int e, int d){
    		S = s; E = e; D = d;
    	}
    	
    	public int compareTo(Edge Cc){
    		return D <= Cc.D ? -1 : 1;
    	}
    }
}
