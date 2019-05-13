import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
 
class Main {
 
    static int N;
    static int map[][] = new int[101][101];
    static List<Integer> list = new ArrayList<>();    
    static int dx[] = {1,0,-1,0};
    static int dy[] = {0,-1,0,1};
    
    public static void main (String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        N = Integer.parseInt(br.readLine());
        
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());
            int g = Integer.parseInt(st.nextToken());
 
            // 0 세대 의 방향
            list.add(d);    
            
            // 각 세대 별로
            for (int j = 0; j < g; j++) {
                int size = list.size();
                // 이전 방향들을 모두 시계 방향으로 회전하여 다시 list에 저장
                for (int s = size-1; s >= 0; s--) {
                    int nd = (list.get(s) + 1) % 4;
                    list.add(nd);
                }
            }
            // check 
            map[y][x] = 1;
            // 기존에 저장한 방향에 따라 초기좌표에서 계속 움직이며 마킹한다.
            for(int dir : list) {
                x += dx[dir];
                y += dy[dir];
                map[y][x] = 1;
            }
            list.clear();
        }
        // 맵에서 1로 마킹된 4각형을 찾아 개수 리턴
        System.out.println(count());
    }
    
    static int count() {
        int res = 0;
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                if(map[i][j] == 1 
                    && map[i][j] == map[i][j+1]
                    && map[i][j] == map[i+1][j]
                    && map[i][j] == map[i+1][j+1]) res++; 
            }
        }
        return res;
    }
}
