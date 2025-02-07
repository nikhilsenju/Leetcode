class Solution {
public:
    int f(int ind, int tar, vector<int>&v,vector<vector<int>>&dp){
        if(ind == 0 ){
            if(tar== 0 && v[0]==0){return 2;}
            if(tar == 0 || v[0]==tar){return 1;}
            return 0;
        }
        if(dp[ind][tar]!=-1){
            return dp[ind][tar];
        }
        int take = 0;
        if(tar>=v[ind]){
            take = f(ind-1,tar - v[ind],v,dp);
        }
        int notake=f(ind-1,tar,v,dp);
        return dp[ind][tar]=notake + take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(auto i:nums){
            sum+=i;
        }
        if((sum+target)%2){
            return 0;
        }
        target = (sum+target)/2;
        if(target<0){
            return 0;
        }
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return f(n-1,target,nums,dp);
        
    }
};