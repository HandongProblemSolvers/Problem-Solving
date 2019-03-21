import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		String S;
		S=sc.next();
		int min=10000;
		int k=-1;
		int temp;
		
		for(int i=S.length()-1; i>=S.length()/2; i--){
			temp=0;	
			for(int j=1; i-j>=0; j++){
				if(i+j>S.length()-1||i-j<0){
					temp++;
					continue;
				}			
				if(S.charAt(i+j)==S.charAt(i-j)){
					continue;
				}
				else{temp=10000; break;}

			}		
			if(temp<min){
				min=temp;	
			}

		}
		for(int i=S.length()-2; i>=S.length()/2-1; i--){
			if(S.length()%2==1&&i==S.length()/2-1)break;
			temp=0;	
			for(int j=0; i-j>=0; j++){
				if(i+j+1>S.length()-1||i-j<0){
					temp++;
					continue;
				}			
				if(S.charAt(i+1+j)==S.charAt(i-j)){
					continue;
				}
				else{temp=10000; break;}

			}
		
			if(temp<min){
				min=temp;	
			}

		}
    
		System.out.println(S.length()+min);

	}
}
