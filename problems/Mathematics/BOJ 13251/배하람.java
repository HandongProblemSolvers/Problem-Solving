import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main2 {

    public static void main(String[] args) throws IOException {
        int m,k,sum = 0;
        int stone[] = new int[51];

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        m = Integer.parseInt(br.readLine());
        StringTokenizer tk = new StringTokenizer(br.readLine());
        for(int i=1; i<=m; i++) {
            stone[i] = Integer.parseInt(tk.nextToken());
            sum += stone[i];
        }
        k = Integer.parseInt(br.readLine());

        double ans = 0.0;

        for(int i=1; i<=m; i++){
            int st = sum, it = stone[i];
            double at = 1.0;
            for(int j=1; j<=k; j++,it--,st--) at *= it/(double)st;
            ans += at;
        }

        System.out.println(ans);

        br.close();
    }
}