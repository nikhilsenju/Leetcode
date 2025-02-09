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
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int k=0;k<=2;k++){
                    if(k!=0){
                        if(buy){
                            dp[ind][buy][k]=max(-prices[ind]+dp[ind+1][!buy][k],dp[ind+1][buy][k]);

                        }
                        else{
                            dp[ind][buy][k]=max(+prices[ind]+dp[ind+1][!buy][k-1],dp[ind+1][buy][k]);
                        }
                    }

                }
            }
        }
        return dp[0][1][2];
    }
};