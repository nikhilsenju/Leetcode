class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxi = 1;
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int l = 0;l<i;l++){
                if(nums[i]>nums[l]){
                    dp[i]=max(dp[i],1+dp[l]);
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
        
    }
};