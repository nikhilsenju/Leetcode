class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>>dp(k,vector<int>(k,0));
        for(auto &i:nums){
            i=i%k;
        }
        int ans = 0;
        for(auto i:nums){
            int cur = i;
            for(int prev = 0;prev<k;prev++){
                dp[prev][cur]=dp[cur][prev]+1;
                ans = max(ans,dp[prev][cur]);
            }
        }
        return ans;
    }
};