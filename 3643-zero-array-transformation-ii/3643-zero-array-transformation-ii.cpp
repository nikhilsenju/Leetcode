class Solution {
public:
    bool solve(vector<vector<int>>&v,vector<int>&nums, int k){
        int n = nums.size();
        vector<int> vp(n+1,0);
        for(int i=0;i<k;i++){
            int l = v[i][0];
            int r = v[i][1];
            int val = v[i][2];
            vp[l]-=val;
            vp[r+1]+=val;
        }
        for(int i=1;i<vp.size();i++)
        {
            vp[i]+=vp[i-1];
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]+vp[i]>0){
                return false;
            }
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        int lo = 0;
        int hi = m;
        int ans = -1;
        while(hi>=lo){
            int mid = (hi+lo)/2;
            if(solve(queries,nums,mid)){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }

        return ans;
    }
};