class Solution {
public:
    long long f(int i , int j ,vector<vector<int>>&grid,vector<vector<long long>>&dp){
         if(i==0 && j==0){
            return grid[0][0];
        }
         if(i<0 || j<0){
            return 1e9;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
    
        long long l = grid[i][j]+f(i,j-1,grid,dp);
        long long u = grid[i][j]+f(i-1,j,grid,dp);
        return dp[i][j]=min(l,u);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<long long>> dp(n,vector<long long>(m,-1));
        return f(n-1,m-1,grid,dp);

        
    }
};