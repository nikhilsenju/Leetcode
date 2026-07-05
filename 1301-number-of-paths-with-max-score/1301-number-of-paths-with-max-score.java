import java.util.*;
class Solution {
    static int[] dr = {-1,0,-1};
    static int[] dc = {0,-1,-1};
    final int MOD = 1000000007;
    public int[] pathsWithMaxScore(List<String> board) {
        int n = board.size();
        int[][] dpmax = new int[n][n];
        int[][] dpcount = new int[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dpmax[i][j]=Integer.MIN_VALUE;
                dpcount[i][j]=0;
            }
        }
        dpmax[n-1][n-1]=0;
        dpcount[n-1][n-1]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==0 && j==0){
                    continue;
                }
                if(dpmax[i][j]==Integer.MIN_VALUE){
                    continue;
                }
                for(int k=0;k<3;k++){
                    int nr = i+dr[k];
                    int nc = j+dc[k];
                    if(nr>=0 && nc>=0 && board.get(nr).charAt(nc)!='X'){
                        char ch = board.get(nr).charAt(nc);
                        int wt;
                        if(ch!='E'){
                            wt = ch-'0';
                        }
                        else{
                            wt = 0;
                        }
                        if(dpmax[i][j]+wt>dpmax[nr][nc]){
                            dpmax[nr][nc]=dpmax[i][j]+wt;
                            dpcount[nr][nc]=dpcount[i][j]%MOD;
                        }
                        else if(dpmax[i][j]+wt==dpmax[nr][nc]){
                            dpcount[nr][nc]=(dpcount[i][j]+dpcount[nr][nc])%MOD;
                        }
                    }
                }
            }
        }
        int[] ans = new int[2];
        if(dpcount[0][0]==0){
            ans[0]=0;
            ans[1]=0;
            return ans;
        }
        ans[0]=dpmax[0][0];
        ans[1]=dpcount[0][0];
        return ans;
        


        
    }
}