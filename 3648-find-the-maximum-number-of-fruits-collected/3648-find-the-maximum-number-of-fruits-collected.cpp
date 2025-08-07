typedef long long ll;
class Solution {
public:
    ll solve(int i , int j , vector<vector<int>>&f,vector<vector<int>>&dp){
            if(i>=j){
                return INT_MIN;
            }
            if(j>=f[0].size()){
                return INT_MIN;
            }
            if(i==f.size()-2 && j==f[0].size()-1){
                return f[i][j];
            }
            if(dp[i][j]!=-1){
                return dp[i][j];
            }
            ll maxi = solve(i+1,j-1,f,dp)+f[i][j];
            maxi = max(maxi,solve(i+1,j+1,f,dp)+f[i][j]);
            maxi = max(maxi,solve(i+1,j,f,dp)+f[i][j]);
            return dp[i][j]=maxi;
    }
    int maxCollectedFruits(vector<vector<int>>& f) {
        int n = f.size();
        int m = f[0].size();
        ll sum = 0;
        for(int i = 0; i < n; i++){
            sum+=f[i][i];
            f[i][i]=0;
        }
        vector<vector<int>>dp(n,vector<int>(n,-1));
        sum+=solve(0,n-1,f,dp);// top right 
        //flip 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i>j){
                    swap(f[i][j],f[j][i]);
                }
            }
        }
        vector<vector<int>>fp(n,vector<int>(n,-1));
        sum+=solve(0,n-1,f,fp);
        return sum;

    }
};