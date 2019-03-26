import java.util.*;

class P1699{
        public static void main(String[] args){
                Scanner sc=new Scanner(System.in);
                int N;
                N=sc.nextInt();
                int[] B=new int[100001];
                
                for(int i=1; i<=N; i++){
                        for(int j=1; j*j<=i; j++){
                                if(B[i]>B[i-j*j]+1||B[i]==0){
                                        B[i]=B[i-j*j]+1;
                                }

                        }
                }
                System.out.println(B[N]);
        }
}
