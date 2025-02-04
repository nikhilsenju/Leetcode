
class Solution {
public:
     bool f(int ind, int tar , vector<int>&arr,vector<vector<int>>&dp){
        if(tar==0){
            return dp[ind][tar]=true;
        }
        if(ind == 0){
            return dp[ind][tar]=(tar==arr[0]);
        }
        if(dp[ind][tar]!=-1){
            return dp[ind][tar];
        }
        int take = 0;
        if(tar>=arr[ind]){
            take=f(ind - 1 , tar-arr[ind],arr,dp);
        }
        int notake = f(ind-1,tar,arr,dp);
        return dp[ind][tar]=take||notake;
    }
    bool canPartition(vector<int>& nums){
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2){return false;}
        int tar = sum/2;
        vector<vector<int>>dp(n,vector<int>(tar+1,-1));
        return f(n-1,tar,nums,dp);
        
    }
};