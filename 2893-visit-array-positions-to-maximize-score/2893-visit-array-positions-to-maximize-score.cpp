class Solution {
public:
    long long solve(long long ind ,long long p ,vector<int>&v,long long x,vector<vector<long long>>&dp){
        if(ind>=v.size()){
            return 0;
        }
        if(dp[ind][p]!=-1){
            return dp[ind][p];
        }
        long long cur = (v[ind]%2)==(p)?v[ind]:0;
        long long change = -x + solve(ind+1,!p,v,x,dp)+cur;
        long long nott = solve(ind+1,p,v,x,dp)+cur;
        return dp[ind][p]=max(change,nott);
    }
    long long maxScore(vector<int>& nums, int x) {
        long long n = nums.size();
        vector<vector<long long>>dp(n+1,vector<long long>(2,-1LL));
        return solve(0,nums[0]%2,nums,x,dp);

        
    }
};