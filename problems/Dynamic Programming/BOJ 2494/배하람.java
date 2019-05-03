import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static String s1,s2;
    static int n;
    static int dp[][] = new int[10001][10];
    static int d[][] = new int[10001][10];
    static int c[][] = new int[10001][10];

    public static void main(String[] args) throws IOException{
        n = Integer.parseInt(br.readLine());
        s1 = br.readLine();
        s2 = br.readLine();

        for(int i=0; i<n; i++) {
            for(int j=0; j<10; j++){
                dp[i][j] = -1;
            }
        }
        bw.write(String.valueOf(solve(0,0)+"\n"));
        print(0,0);

        br.close();
        bw.close();
    }

    static void print(int index, int left) throws IOException{
        if(index==n) return;
        // 회전안한 경우에 출력하면 안됨
        if(c[index][left]!=0) bw.write(String.valueOf(index+1 + " " + c[index][left]*d[index][left]+"\n"));
        
        // 회전방향에 따라서 왼쪽으로 얼마나 돌지 결정
        if(d[index][left]==1) print(index+1,(c[index][left]+left)%10);
        else print(index+1,left);
    }

    static int solve(int index, int left) {
        if(index==n) return 0;
        if(dp[index][left]!=-1) return dp[index][left];

        int from = s1.charAt(index)-'0';
        int to = s2.charAt(index)-'0';

        // 이제까지 왼쪽으로 돈 경우를 합산해서 현재 위치 계산
        int cur = (from+left)%10;

        // 현재위치에서 왼쪽, 오른쪽으로 돌아서 주어진 숫자를 만들기 위한 회전횟수
        int lro = (to-cur+10)%10;
        int rro = (cur-to+10)%10;

        // 왼쪽으로 도는 경우에만 왼쪽으로 도는 횟수를 매개변수로 넘겨줘야 하기 때문에
        // lro를 더해주는 것임
        int l = solve(index+1, (lro+left)%10) + lro;
        int r = solve(index+1, left) + rro;

        // dp랑 c를 따로 두는 이유는 해당 상태에서의 c를 알아야
        // 출력할 수가 있기 때문이다.
        if(l<r){
            dp[index][left] = l;
            c[index][left] = lro;
            d[index][left] = 1;
        } else{
            dp[index][left] = r;
            c[index][left] = rro;
            d[index][left] = -1;
        }
        return dp[index][left];
    }
}