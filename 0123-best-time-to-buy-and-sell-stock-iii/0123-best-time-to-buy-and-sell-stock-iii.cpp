class Solution {
public:
    int f(int ind ,int buy,int k,vector<int>&prices, vector<vector<vector<int>>> &dp){
        if(ind>=prices.size()){
            return 0;
        }
        if(k<=0){
            return 0;
        }
        if(dp[ind][buy][k]!=-1){
            return dp[ind][buy][k];
        }
        if(buy){
            return dp[ind][buy][k]=max(-prices[ind]+f(ind,!buy,k,prices,dp),f(ind+1,buy,k,prices,dp));
        }
        else{
            return dp[ind][buy][k]=max(+prices[ind]+f(ind+1,!buy,k-1,prices,dp),f(ind+1,buy,k,prices,dp));

        }
    }
    int maxProfit(vector<int>& prices) {
        int n  = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,2,prices,dp);

    }
};