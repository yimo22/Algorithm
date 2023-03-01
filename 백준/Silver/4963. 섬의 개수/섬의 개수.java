
import java.util.*;
public class Main {

    static int w,h, answ;
    static int[][] map;
    static boolean[][] visited;
    static final int[][] dir = {{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1}};

    static void dfs(int i, int j){
        for(int d=0;d<8;d++){
            int nx = dir[d][0] + i;
            int ny = dir[d][1] + j;
            if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;

            if(!visited[nx][ny] && map[nx][ny] == 1){
                visited[nx][ny] = true;
                dfs(nx,ny);
            }
        }
        return ;
    }
    public static void Solve(){
        answ =0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(!visited[i][j] && map[i][j] == 1){
                    visited[i][j] = true;
                    answ++;
                    dfs(i,j);
                }
            }
        }
        System.out.println(answ);
        return;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        while(true){
            w = sc.nextInt();
            h = sc.nextInt();
            if(w==0 && h ==0) break;
            map = new int[h][w];
            visited = new boolean[h][w];

            for(int i=0;i<h;i++){
                for(int j=0;j<w;j++){
                    map[i][j] = sc.nextInt();
                }
            }
            Solve();
        }
    }

}
