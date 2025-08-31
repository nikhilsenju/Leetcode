class Solution {
public:
    const int mod = 1e9+7;
    //r,c,dir
    int solve(vector<vector<int>>&grid,int r, int c, int dir,vector<vector<vector<int>>>&dp){
        if(r<0 || c<0){
            return 0;
        }
        if(r==0 && c==0){
            return 1;
        }
        if(dp[r][c][dir]!=-1){
            return dp[r][c][dir];
        }
        if(grid[r][c]==1){//mirror
            if(dir==1){
                return dp[r][c][dir]=solve(grid,r-1,c,0,dp);
            }
            else{
                return dp[r][c][dir]=solve(grid,r,c-1,1,dp);
            }
        }
        else{
            int op1 = solve(grid,r-1,c,0,dp);
            int op2 = solve(grid,r,c-1,1,dp);
            return dp[r][c][dir]=(op1+op2)%mod;
        }
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(2,-1)));
        return solve(grid,n-1,m-1,0,dp);

    }
};