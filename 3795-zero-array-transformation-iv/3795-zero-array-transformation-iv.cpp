class Solution {
public:
    int solve(vector<vector<int>>&q,int ind,int k,int tar,vector<vector<int>>&dp){
        if(tar==0){
            return k;
        }
        if(tar<0 || k>=q.size()){
            return q.size()+1;
        }
        if(dp[k][tar]!=-1){
            return dp[k][tar];
        }
        int nt = solve(q,ind,k+1,tar,dp);
        int tt = INT_MAX;
        if(ind>=q[k][0] && q[k][1]>=ind && tar>=q[k][2]){
            tt = solve(q,ind,k+1,tar-q[k][2],dp);
        }
        return dp[k][tar]=min(nt,tt);

    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int n = nums.size();
        int ans = -1;
        for(int i=0;i<n;i++){
            vector<vector<int>> dp(q.size()+1,vector<int>(nums[i]+1,-1));
            ans = max(ans,solve(q,i,0,nums[i],dp));

        }
        return ans>q.size()?-1:ans;

        
    }
};