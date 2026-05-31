class Solution {
public:
    int solve(int ind,vector<vector<int>>&it,vector<vector<int>>&dp,int bud,int mini,vector<int>&free){
        // base case
        if(ind>=it.size()){
            return bud/mini;
        }
        if(dp[ind][bud]!=-1){
            return dp[ind][bud];
        }

        //i will take 
        int take = 0;
        if(it[ind][1]<=bud){
            take = free[ind]+solve(ind+1,it,dp,bud-it[ind][1],mini,free);
        }
        int notake = solve(ind+1,it,dp,bud,mini,free);
        return dp[ind][bud]=max(take,notake);
        //i will not take

    }
    int maximumSaleItems(vector<vector<int>>& v, int bd) {
        int n = v.size();
        vector<int> free(n);
        int mini = INT_MAX;
        vector<vector<int>>dp(n,vector<int>(1501,-1));
        for(int i = 0; i<n ;i++){
            mini = min(mini,v[i][1]);
            for(int j=0;j<n;j++){
                if(v[j][0]%v[i][0]==0){
                    free[i]++;
                }
            }
        }
        //will call dp
        return solve(0,v,dp,bd,mini,free);
    }
};


